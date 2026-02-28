#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ------------------------------------------------------------
// ANSI Colors
// ------------------------------------------------------------
#define ANSI_LIME   "\033[92m"
#define ANSI_RED    "\033[91m"
#define ANSI_YELLOW "\033[93m"
#define ANSI_CYAN   "\033[96m"
#define ANSI_RESET  "\033[0m"

// ------------------------------------------------------------
// Loop structure
// ------------------------------------------------------------
struct ForLoopNode {
    string init;
    string condition;
    string increment;
    string body;
};

// ------------------------------------------------------------
// Clean stack visualizer (top clearly marked)
// ------------------------------------------------------------
void printStack(const stack<string>& st) {
    stack<string> temp = st;
    vector<string> items;

    while (!temp.empty()) {
        items.push_back(temp.top());
        temp.pop();
    }

    cout << ANSI_CYAN << "   Stack: [ ";
    for (int i = items.size() - 1; i >= 0; --i) {
        cout << items[i];
        if (i != 0) cout << " | ";
    }
    cout << " ]  <--- top" << ANSI_RESET << "\n";
}

void push(stack<string>& st, const string& item) {
    cout << ANSI_LIME << " PUSH: " << item << ANSI_RESET << "\n";
    st.push(item);
    printStack(st);
}

void pop(stack<string>& st) {
    if (!st.empty()) {
        cout << ANSI_RED << " POP:  " << st.top() << ANSI_RESET << "\n";
        st.pop();
        printStack(st);
    }
}

// ------------------------------------------------------------
// Tokenizer
// ------------------------------------------------------------
vector<string> tokenize(const string& src) {
    vector<string> tokens;
    string token;

    for (char c : src) {
        if (isspace(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else if (c == '(' || c == ')' || c == '{' || c == '}' || c == ';') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, c));
        }
        else {
            token.push_back(c);
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}

// ------------------------------------------------------------
// Single loop
// ------------------------------------------------------------
void single_loop(string code) {

    auto tokens = tokenize(code);
    stack<string> parseStack;

    ForLoopNode loop;
    enum Section { NONE, INIT, COND, INCR, BODY };
    Section current = NONE;

    cout << "\n=== Single Loop ===\n";
    cout << code << "\n\n";


    for (size_t i = 0; i < tokens.size(); i++) {
        const string& t = tokens[i];

        cout << ANSI_YELLOW << "Token: " << setw(6) << t << ANSI_RESET << "\n";

        if (t == "for") {
            push(parseStack, "LOOP");
        }
        else if (t == "(") {
            push(parseStack, "(");
            current = INIT;
        }
        else if (t == ";") {
            if (current == INIT) current = COND;
            else if (current == COND) current = INCR;
        }
        else if (t == ")") {
            pop(parseStack);
            current = NONE;
        }
        else if (t == "{") {
            push(parseStack, "{");
            current = BODY;
        }
        else if (t == "}") {
            pop(parseStack);
            pop(parseStack);
            current = NONE;
        }
        else {
            switch (current) {
            case INIT: loop.init += t + " "; break;
            case COND: loop.condition += t + " "; break;
            case INCR: loop.increment += t + " "; break;
            case BODY: loop.body += t + " "; break;
            default: break;
            }
        }
    }

    cout << "\n=== Recovered Loop Structure ===\n";
    cout << "Initialization: " << loop.init << "\n";
    cout << "Condition:      " << loop.condition << "\n";
    cout << "Increment:      " << loop.increment << "\n";
    cout << "Body:           " << loop.body << "\n";

    cout << "\n=== Done ===\n";
}

// ------------------------------------------------------------
// Double nested loop
// ------------------------------------------------------------
void double_loop(string code) {

    auto tokens = tokenize(code);
    stack<string> parseStack;

    enum Section { NONE, INIT, COND, INCR, BODY };
    Section current = NONE;

    struct LoopNode {
        string init;
        string condition;
        string increment;
        string body;
        bool nested = false;   // NEW: indicates nested vs top-level
    };

    vector<LoopNode> loops;
    LoopNode currentLoop;

    // Helper to avoid pushing empty loops
    auto push_if_nonempty = [&](LoopNode& L) {
        if (!L.init.empty() ||
            !L.condition.empty() ||
            !L.increment.empty() ||
            !L.body.empty())
        {
            loops.push_back(L);
        }
        L = LoopNode();
        };

    cout << "\n=== Nested Loops ===\n";
    cout << code << "\n\n";

    for (size_t i = 0; i < tokens.size(); i++) {
        const string& t = tokens[i];

        cout << ANSI_YELLOW << "Token: " << setw(6) << t << ANSI_RESET << "\n";

        // ------------------------------------------------------------
        // Detect "for"
        // ------------------------------------------------------------
        if (t == "for") {

            // Determine if this loop is nested
            bool isNested = false;
            {
                stack<string> temp = parseStack;
                while (!temp.empty()) {
                    if (temp.top() == "LOOP") {
                        isNested = true;
                        break;
                    }
                    temp.pop();
                }
            }

            // If we were already building a loop, store it
            push_if_nonempty(currentLoop);

            // Start a new loop
            currentLoop = LoopNode();
            currentLoop.nested = isNested;

            push(parseStack, "LOOP");
        }

        // ------------------------------------------------------------
        // Parse parentheses and semicolons
        // ------------------------------------------------------------
        else if (t == "(") {
            push(parseStack, "(");
            current = INIT;
        }
        else if (t == ";") {
            if (current == INIT) current = COND;
            else if (current == COND) current = INCR;
        }
        else if (t == ")") {
            pop(parseStack);
            current = NONE;
        }

        // ------------------------------------------------------------
        // Parse braces
        // ------------------------------------------------------------
        else if (t == "{") {
            push(parseStack, "{");
            current = BODY;
        }
        else if (t == "}") {
            pop(parseStack); // pop "{"
            pop(parseStack); // pop "LOOP"
            current = NONE;

            // Completed loop
            push_if_nonempty(currentLoop);
        }

        // ------------------------------------------------------------
        // Capture loop components
        // ------------------------------------------------------------
        else {
            switch (current) {
            case INIT: currentLoop.init += t + " "; break;
            case COND: currentLoop.condition += t + " "; break;
            case INCR: currentLoop.increment += t + " "; break;
            case BODY: currentLoop.body += t + " "; break;
            default: break;
            }
        }
    }

    // Final safety push
    push_if_nonempty(currentLoop);

    // ------------------------------------------------------------
    // Recovered summary
    // ------------------------------------------------------------
    cout << "\n=== Recovered Nested Loops ===\n";

    for (size_t i = 0; i < loops.size(); i++) {
        cout << ANSI_CYAN << "\nLoop #" << (i + 1) << ANSI_RESET << "\n";

        cout << "Type:           "
            << (loops[i].nested
                ? "Nested (inside another loop)"
                : "Top-level (not nested)")
            << "\n";

        cout << "Initialization: " << loops[i].init << "\n";
        cout << "Condition:      " << loops[i].condition << "\n";
        cout << "Increment:      " << loops[i].increment << "\n";
        cout << "Body:           " << loops[i].body << "\n";
    }

    cout << "\n=== Done ===\n";
}

void consecutive_loops(string code) {

    auto tokens = tokenize(code);
    stack<string> parseStack;

    enum Section { NONE, INIT, COND, INCR, BODY };
    Section current = NONE;

    vector<ForLoopNode> loops;
    ForLoopNode currentLoop;

    cout << "\n=== Consecutive Loops ===\n";
    cout << code << "\n\n";

    for (size_t i = 0; i < tokens.size(); i++) {
        const string& t = tokens[i];

        cout << ANSI_YELLOW << "Token: " << setw(6) << t << ANSI_RESET << "\n";

        if (t == "for") {
            // If we were already in a loop body, that loop is done
            if (!currentLoop.init.empty() ||
                !currentLoop.condition.empty() ||
                !currentLoop.increment.empty() ||
                !currentLoop.body.empty())
            {
                loops.push_back(currentLoop);
                currentLoop = ForLoopNode();
            }

            push(parseStack, "LOOP");
        }
        else if (t == "(") {
            push(parseStack, "(");
            current = INIT;
        }
        else if (t == ";") {
            if (current == INIT) current = COND;
            else if (current == COND) current = INCR;
        }
        else if (t == ")") {
            pop(parseStack);
            current = NONE;
        }
        else if (t == "{") {
            push(parseStack, "{");
            current = BODY;
        }
        else if (t == "}") {
            pop(parseStack); // pop "{"
            pop(parseStack); // pop "LOOP"
            current = NONE;

            // Loop is complete
            loops.push_back(currentLoop);
            currentLoop = ForLoopNode();
        }
        else {
            switch (current) {
            case INIT: currentLoop.init += t + " "; break;
            case COND: currentLoop.condition += t + " "; break;
            case INCR: currentLoop.increment += t + " "; break;
            case BODY: currentLoop.body += t + " "; break;
            default: break;
            }
        }
    }

    cout << "\n=== Recovered Consecutive Loops ===\n";

    for (size_t i = 0; i < loops.size(); i++) {
        cout << ANSI_CYAN << "\nLoop #" << (i + 1) << ANSI_RESET << "\n";
        cout << "Initialization: " << loops[i].init << "\n";
        cout << "Condition:      " << loops[i].condition << "\n";
        cout << "Increment:      " << loops[i].increment << "\n";
        cout << "Body:           " << loops[i].body << "\n";
    }

    cout << "\n=== Done ===\n";
}

int main() {

    string singlecode =
        "for (int i = 0; i < 4; i++) { sum += i; }";

    string consecutivecode =
        "for (int i = 0; i < 4; i++) { sum += i; } "
        "for (int j = 0; j < 3; j++) { sum += j; }";

    string nestedcode =
        "for (int i = 0; i < 3; i++) { "
        "\tfor (int j = 0; j < 2; j++) { "
        "\t\tsum += i + j; "
        "\t} "
        "}";

    single_loop(singlecode);
    double_loop(nestedcode);
    consecutive_loops(consecutivecode);

    return 0;
}