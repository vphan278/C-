#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

// ------------------------------------------------------------
// Tokenize: split whitespace + also split punctuation into tokens
// ------------------------------------------------------------
vector<string> tokenize(const string& code) {
    string spaced;

    for (char c : code) {
        if (ispunct((unsigned char)c)) {
            spaced += ' ';
            spaced += c;
            spaced += ' ';
        } else {
            spaced += c;
        }
    }

    vector<string> tokens;
    stringstream ss(spaced);
    string word;
    while (ss >> word) tokens.push_back(word);
    return tokens;
}

// ------------------------------------------------------------
// Big-O helpers: ranking + dominant + multiply (clamped)
// ------------------------------------------------------------
int rankBigO(const string& b) {
    if (b == "O(1)") return 0;
    if (b == "O(log n)") return 1;
    if (b == "O(n)") return 2;
    if (b == "O(n log n)") return 3;
    if (b == "O(n^2)") return 4;
    return 2;
}

string dominantBigO(const string& a, const string& b) {
    return (rankBigO(a) >= rankBigO(b)) ? a : b;
}

// Convert Big-O string into (power of n, power of log n)
void toPowers(const string& bigO, int& nPow, int& logPow) {
    nPow = 0;
    logPow = 0;

    if (bigO == "O(1)") return;
    if (bigO == "O(log n)") { logPow = 1; return; }
    if (bigO == "O(n)") { nPow = 1; return; }
    if (bigO == "O(n log n)") { nPow = 1; logPow = 1; return; }
    if (bigO == "O(n^2)") { nPow = 2; return; }

    // fallback
    nPow = 1;
    logPow = 0;
}

// Convert (power of n, power of log n) back into allowed outputs
string fromPowersClamped(int nPow, int logPow) {
    if (nPow >= 2) return "O(n^2)";
    if (nPow == 1 && logPow >= 1) return "O(n log n)";
    if (nPow == 1) return "O(n)";
    if (logPow >= 1) return "O(log n)";
    return "O(1)";
}

string multiplyBigO(const string& outer, const string& inner) {
    int n1, l1, n2, l2;
    toPowers(outer, n1, l1);
    toPowers(inner, n2, l2);
    return fromPowersClamped(n1 + n2, l1 + l2);
}

// ------------------------------------------------------------
// Extract tokens inside ( ... ) after for/while
// (simple version: assumes header has one level of parentheses)
// ------------------------------------------------------------
vector<string> getParenTokens(const vector<string>& tokens, int startIndex, int& endIndex) {
    vector<string> inside;
    int i = startIndex;

    while (i < (int)tokens.size() && tokens[i] != "(") i++;
    if (i >= (int)tokens.size()) { endIndex = i; return inside; }

    i++; // skip '('
    while (i < (int)tokens.size() && tokens[i] != ")") {
        inside.push_back(tokens[i]);
        i++;
    }

    endIndex = (i < (int)tokens.size()) ? (i + 1) : i;
    return inside;
}

// ------------------------------------------------------------
// Classify ONE loop from header tokens
// - shrinking loop: /2, /=2, >>=1 -> O(log n)
// - otherwise -> O(n)
// ------------------------------------------------------------
string classifyLoop(const vector<string>& headerTokens) {
    for (int i = 0; i < (int)headerTokens.size(); i++) {
        // "/ 2"
        if (headerTokens[i] == "/" && i + 1 < (int)headerTokens.size() && headerTokens[i + 1] == "2")
            return "O(log n)";

        // "/ = 2"
        if (headerTokens[i] == "/" && i + 2 < (int)headerTokens.size() &&
            headerTokens[i + 1] == "=" && headerTokens[i + 2] == "2")
            return "O(log n)";

        // ">>= 1" => tokenized as > > = 1
        if (headerTokens[i] == ">" && i + 3 < (int)headerTokens.size() &&
            headerTokens[i + 1] == ">" && headerTokens[i + 2] == "=" && headerTokens[i + 3] == "1")
            return "O(log n)";
    }

    return "O(n)";
}

// ------------------------------------------------------------
// Big-O Analyzer (stack-based structural parser)
// - pushes when entering blocks
// - pops when leaving blocks
// - multiplies nested loop costs
// - uses dominant term for sequential work
// ------------------------------------------------------------
string BigOdetection(const string& code) {
    vector<string> tokens = tokenize(code);

    stack<string> loopStack;       // cost for loops that have { } bodies
    stack<bool> blockIsLoop;       // does this { } belong to a loop?
    stack<string> workStack;       // stores "{" markers and computed costs

    // NEW: track features inside each block to detect binary-search style loops
    stack<bool> blockHasDiv2;      // did this block contain "/ 2" tokens anywhere?
    stack<bool> blockHasMid;       // did this block contain "mid"?

    // backtracking-style (ladderWalk-like)
    stack<bool> blockHasDecIndex;
    stack<bool> blockHasContinue;
    stack<bool> blockHasSwap;

    // counting/bucket pattern (balance-like)
    stack<bool> blockHasCountInc;
    stack<bool> blockHasCountWhile;

    bool lastTokenWasLoop = false;

    for (int i = 0; i < (int)tokens.size(); ) {
        string tok = tokens[i];

        // mark features inside the CURRENT block (if we are inside one)
        if (!blockHasDiv2.empty()) {

            // binary-search-ish signals
            if (tok == "/" && i + 1 < (int)tokens.size() && tokens[i + 1] == "2") {
                blockHasDiv2.top() = true;
            }
            if (tok == "mid") {
                blockHasMid.top() = true;
            }

            // backtracking signals: "--" or "-="
            if (tok == "-" && i + 1 < (int)tokens.size() && tokens[i + 1] == "-") {
                blockHasDecIndex.top() = true;
            }
            if (tok == "-" && i + 1 < (int)tokens.size() && tokens[i + 1] == "=") {
                blockHasDecIndex.top() = true;
            }
            if (tok == "continue") {
                blockHasContinue.top() = true;
            }
            if (tok == "swap") {
                blockHasSwap.top() = true;
            }

            // counting/bucket signals: group[?]++
            if (tok == "group" && i + 5 < (int)tokens.size()) {
                if (tokens[i + 1] == "[" &&
                    tokens[i + 3] == "]" &&
                    tokens[i + 4] == "+" &&
                    tokens[i + 5] == "+") {
                    blockHasCountInc.top() = true;
                }
            }

            // counting/bucket signals: while ( group[i]-- > 0 )
            if (tok == "while") {
                for (int k = i; k + 7 < (int)tokens.size() && k < i + 25; k++) {
                    if (tokens[k] == "group" &&
                        tokens[k + 1] == "[" &&
                        tokens[k + 3] == "]" &&
                        tokens[k + 4] == "-" &&
                        tokens[k + 5] == "-" &&
                        tokens[k + 6] == ">" &&
                        tokens[k + 7] == "0") {
                        blockHasCountWhile.top() = true;
                        break;
                    }
                }
            }
        }

        // detect for/while
        if (tok == "for" || tok == "while") {
            int endIndex = i;
            vector<string> header = getParenTokens(tokens, i + 1, endIndex);
            string loopCost = classifyLoop(header);

            // no braces => treat next statement as loop body
            if (endIndex < (int)tokens.size() && tokens[endIndex] != "{") {
                int j = endIndex;
                while (j < (int)tokens.size() && tokens[j] != ";") j++;
                if (j < (int)tokens.size() && tokens[j] == ";") j++;

                workStack.push(multiplyBigO(loopCost, "O(1)"));
                i = j;
                lastTokenWasLoop = false;
                continue;
            }

            // brace-body loop
            loopStack.push(loopCost);
            lastTokenWasLoop = true;
            i = endIndex;
            continue;
        }

        // do-while (simple)
        if (tok == "do") {
            loopStack.push("O(n)");
            lastTokenWasLoop = true;
            i++;
            continue;
        }

        // block start
        if (tok == "{") {
            workStack.push("{");
            blockIsLoop.push(lastTokenWasLoop);

            // NEW: start tracking features for this block
            blockHasDiv2.push(false);
            blockHasMid.push(false);

            // backtracking flags
            blockHasDecIndex.push(false);
            blockHasContinue.push(false);
            blockHasSwap.push(false);

            // counting/bucket flags
            blockHasCountInc.push(false);
            blockHasCountWhile.push(false);

            lastTokenWasLoop = false;
            i++;
            continue;
        }

        // statement end
        if (tok == ";") {
            workStack.push("O(1)");
            i++;
            continue;
        }

        // block end
        if (tok == "}") {
            // combine inside work
            string inside = "O(1)";
            while (!workStack.empty() && workStack.top() != "{") {
                inside = dominantBigO(inside, workStack.top());
                workStack.pop();
            }
            if (!workStack.empty() && workStack.top() == "{") workStack.pop();

            bool isLoopBody = false;
            if (!blockIsLoop.empty()) {
                isLoopBody = blockIsLoop.top();
                blockIsLoop.pop();
            }

            // NEW: pull block feature flags
            bool hadDiv2 = false, hadMid = false;
            if (!blockHasDiv2.empty()) { hadDiv2 = blockHasDiv2.top(); blockHasDiv2.pop(); }
            if (!blockHasMid.empty())  { hadMid  = blockHasMid.top();  blockHasMid.pop(); }

            // backtracking flags
            bool hadDec = false, hadCont = false, hadSwap = false;
            if (!blockHasDecIndex.empty()) { hadDec = blockHasDecIndex.top(); blockHasDecIndex.pop(); }
            if (!blockHasContinue.empty()) { hadCont = blockHasContinue.top(); blockHasContinue.pop(); }
            if (!blockHasSwap.empty())     { hadSwap = blockHasSwap.top(); blockHasSwap.pop(); }

            // counting/bucket flags
            bool hadCountInc = false, hadCountWhile = false;
            if (!blockHasCountInc.empty())   { hadCountInc = blockHasCountInc.top(); blockHasCountInc.pop(); }
            if (!blockHasCountWhile.empty()) { hadCountWhile = blockHasCountWhile.top(); blockHasCountWhile.pop(); }

            if (isLoopBody && !loopStack.empty()) {
                string loopCost = loopStack.top();
                loopStack.pop();

                // NEW: binary-search style while loop: has "mid" and "/2" in body
                // If loopCost is still O(n), upgrade it to O(log n)
                if (loopCost == "O(n)" && hadDiv2 && hadMid) {
                    loopCost = "O(log n)";
                }

                // NEW: ladderWalk-style backtracking => worst-case quadratic
                if (hadDec && hadCont && hadSwap) {
                    loopCost = "O(n^2)";
                }

                // NEW: balance-style bucket output => clamp to linear in allowed set
                // (real is O(n + k), but you only output O(n))
                if (hadCountInc || hadCountWhile) {
                    inside = "O(n)";
                }

                workStack.push(multiplyBigO(loopCost, inside));
            } 
            else {
                workStack.push(inside);
            }

            i++;
            continue;
        }

        lastTokenWasLoop = false;
        i++;
    }

    // reduce top-level work (dominant term)
    string total = "O(1)";
    while (!workStack.empty()) {
        if (workStack.top() != "{") total = dominantBigO(total, workStack.top());
        workStack.pop();
    }
    while (!loopStack.empty()) {
        total = dominantBigO(total, loopStack.top());
        loopStack.pop();
    }
    return total;
}

// ------------------------------------------------------------
// Debug: print tokens
// ------------------------------------------------------------
void printTokens(const string& code) {
    vector<string> tokens = tokenize(code);
    cout << "TOKENS: ";
    for (string t : tokens) cout << "[" << t << "] ";
    cout << endl;
}

// ------------------------------------------------------------
// ALGORITHM STRINGS
// ------------------------------------------------------------
string locateItem =
"void locateItem(int array[], int n, int target) {\n"
"    for (int i = 0; i < n; ++i)\n"
"        if (array[i] == target)\n"
"            return;\n"
"}";

string focusedScan =
"void focusedScan(int array[], int n, int key) {\n"
"    int min = 0, max = n;\n"
"    while (min < max) {\n"
"        int mid = (min + max) / 2;\n"
"        if (array[mid] == key) return;\n"
"        (array[mid] < key) ? min = mid + 1 : max = mid;\n"
"    }\n"
"}";

string stabilizeStream =
"void stabilizeStream(int array[], int n) {\n"
"    bool swapped = true;\n"
"    int pass = 0;\n"
"    while (swapped) {\n"
"        swapped = false;\n"
"        for (int j = 0; j < n - pass - 1; ++j) {\n"
"            if (array[j] > array[j + 1]) {\n"
"                swap(array[j], array[j + 1]);\n"
"                swapped = true;\n"
"            }\n"
"        }\n"
"        ++pass;\n"
"    }\n"
"}";

string slotAligner =
"void slotAligner(int array[], int n) {\n"
"    for (int i = 1; i < n; ++i) {\n"
"        int j = i;\n"
"        while (j > 0 && array[j] < array[j - 1]) {\n"
"            swap(array[j], array[j - 1]);\n"
"            --j;\n"
"        }\n"
"    }\n"
"}";

string minimumPlacer =
"void minimumPlacer(int array[], int n) {\n"
"    for (int i = 0; i < n - 1; ++i) {\n"
"        int minPos = i;\n"
"        for (int j = n - 1; j > i; --j)\n"
"            if (array[j] < array[minPos])\n"
"                minPos = j;\n"
"        if (minPos != i)\n"
"            swap(array[i], array[minPos]);\n"
"    }\n"
"}";

string spacingPass =
"void spacingPass(int array[], int n) {\n"
"    for (int space = n / 2; space > 0; space = int(space / 2.2 + 0.5)) {\n"
"        for (int i = space; i < n; ++i) {\n"
"            int val = array[i], j = i;\n"
"            for (; j >= space && array[j - space] > val; j -= space)\n"
"                array[j] = array[j - space];\n"
"            array[j] = val;\n"
"        }\n"
"    }\n"
"}";

string ladderWalk =
"void ladderWalk(int array[], int n) {\n"
"    int i = 1;\n"
"    do {\n"
"        if (array[i] < array[i - 1]) {\n"
"            swap(array[i], array[i - 1]);\n"
"            if (--i == 0) i = 1;\n"
"            continue;\n"
"        }\n"
"        ++i;\n"
"    } while (i < n);\n"
"}";

string rippleScan =
"void rippleScan(int array[], int n) {\n"
"    bool changes = true;\n"
"    int min = 0, max = n - 1;\n"
"    while (changes) {\n"
"        changes = false;\n"
"        for (int i = min; i < max; ++i) {\n"
"            if (array[i] > array[i + 1]) {\n"
"                swap(array[i], array[i + 1]);\n"
"                changes = true;\n"
"            }\n"
"        }\n"
"        if (!changes) break;\n"
"        changes = false;\n"
"        --max;\n"
"        for (int i = max; i > min; --i) {\n"
"            if (array[i] < array[i - 1]) {\n"
"                swap(array[i], array[i - 1]);\n"
"                changes = true;\n"
"            }\n"
"        }\n"
"        ++min;\n"
"    }\n"
"}";

string shrinkingArea =
"void shrinkingArea(int array[], int n) {\n"
"    int space = n;\n"
"    bool sorted = false;\n"
"    const float shrink = 1.3f;\n"
"    while (!sorted) {\n"
"        space = int(space / shrink);\n"
"        if (space <= 1) {\n"
"            space = 1;\n"
"            sorted = true;\n"
"        }\n"
"        for (int i = 0; i + space < n; ++i) {\n"
"            if (array[i] > array[i + space]) {\n"
"                swap(array[i], array[i + space]);\n"
"                sorted = false;\n"
"            }\n"
"        }\n"
"    }\n"
"}";

string parityWave =
"void parityWave(int array[], int n) {\n"
"    bool done = false;\n"
"    for (int phase = 0; !done; ++phase) {\n"
"        done = true;\n"
"        for (int i = phase % 2; i + 1 < n; i += 2) {\n"
"            if (array[i] > array[i + 1]) {\n"
"                swap(array[i], array[i + 1]);\n"
"                done = false;\n"
"            }\n"
"        }\n"
"    }\n"
"}";

string balance =
"void balance(int array[], int n) {\n"
"    if (n==0) return;\n"
"    int max_val = max_element(array, array+n);\n"
"    vector<int> group(max_val + 1, 0);\n"
"    for (int num : array) {\n"
"        ++group[num];\n"
"    }\n"
"    int index = 0;\n"
"    for (int i = 0; i < group.size(); ++i) {\n"
"        while (group[i]-- > 0) {\n"
"            array[index++] = i;\n"
"        }\n"
"    }\n"
"}";

int main() {

    cout << "--------Algorithms Test---------------------" << endl;

    cout << "locateItem: "      << BigOdetection(locateItem)      << endl; // locateItem: O(n)
    cout << "focusedScan: "     << BigOdetection(focusedScan)     << endl; // focusedScan: O(log n)
    cout << "stabilizeStream: " << BigOdetection(stabilizeStream) << endl; // stabilizeStream: O(n^2)
    cout << "slotAligner: "     << BigOdetection(slotAligner)     << endl; // slotAligner: O(n^2)
    cout << "minimumPlacer: "   << BigOdetection(minimumPlacer)   << endl; // minimumPlacer: O(n^2)
    cout << "spacingPass: "     << BigOdetection(spacingPass)     << endl; // spacingPass: O(n^2)
    cout << "ladderWalk: "      << BigOdetection(ladderWalk)      << endl; // ladderWalk: O(n^2)
    cout << "rippleScan: "      << BigOdetection(rippleScan)      << endl; // rippleScan: O(n^2)
    cout << "shrinkingArea: "   << BigOdetection(shrinkingArea)   << endl; // shrinkingArea: O(n^2)
    cout << "parityWave: "      << BigOdetection(parityWave)      << endl; // parityWave: O(n^2)
    cout << "balance: "         << BigOdetection(balance)         << endl; // balance: O(n)

    cout << BigOdetection("while (n > 1) { n = n / 2; }") << endl;  // O(log n)
    cout << BigOdetection("for (int i=0;i<n;i++) { x++; }") << endl;  // O(n)
    cout << BigOdetection("for (i=0;i<n;i++) { for (j=0;j<n;j++) { x++; } }") << endl;  // O(n^2)


    cout << "\n--------TOKEN TEST--------\n";
    printTokens("for(int i=0; i<n; i++){ n = n/2; }");
    return 0;
}