#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> tokenize(const string& code);

string BigOdetection(string code) {

    vector<string> tokens = tokenize(code);
    bool hasLogPattern = false;

    for (string t : tokens) {
    if (t.find("/2") != string::npos) {
        hasLogPattern = true;
    }
}
    // Part 2
    bool hasFor = (code.find("for") != string::npos);
    bool hasWhile = (code.find("while") != string::npos);
    bool hasDivideBy2 = (code.find("/2") != string::npos) || (code.find("/ 2") != string::npos);
    bool hasTwoFors = (code.find("for") != string::npos && code.find("for", code.find("for") + 1) != string::npos);
    bool hasTwoLoops = hasTwoFors || (code.find("while") != string::npos && code.find("for")   != string::npos);
    bool hasDo   = (code.find("do") != string::npos);
    bool hasSwap = (code.find("swap") != string::npos);
    bool hasMid = (code.find("mid") != string::npos);
    bool hasMin = (code.find("min") != string::npos);
    bool hasMax = (code.find("max") != string::npos);

    //hasDivideBy2 = hasDivideBy2 || hasLogPattern;

    // Part 2: : No loop -> O(1)
    if (!hasFor && !hasWhile)
        return "O(1)";

    // Part 2: : Loop that halves inputm process n times  -> O(n log n)
    if (hasFor && hasWhile && hasDivideBy2)
        return "O(n log n)";

    // Part 2: : Loop that halves input -> O(log n)
    if (hasDivideBy2 && hasWhile)
        return "O(log n)";

    // Part 2: : Loop inside a loop   -> O(n^2)
    if (hasTwoLoops || (hasDo && hasSwap))
        return "O(n^2)";

    // Part 2: : One loop -> O(n)
    return "O(n)";
}

//Tokens
vector<string> tokenize(const string& code) {
    vector<string> tokens;
    stringstream ss(code);
    string word;

    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}


int main() {
   
    cout << "--------Searching and Sorting Algorithms----" <<endl;
    cout << endl;

    string code1 = "int x = 41;";                                // O(1)
    string code2 = "while{ n = n/2; }";                          // O(log n)
    string code3 = "for(int i=0; i<n; i++)";                     // O(n)
    string code4 = "for(i=0;i<n;i++){ while}{ j=j/2;}";          // O(n log n)
    string code5 = "for(i=0;i<n;i++){ for(j=0;j<n;j++)}";        // O(n^2)

    cout << "Code 1: " << BigOdetection(code1) << endl; // O(1)
    cout << "Code 2: " << BigOdetection(code2) << endl; // O(log n)
    cout << "Code 3: " << BigOdetection(code3) << endl; // O(n)
    cout << "Code 4: " << BigOdetection(code4) << endl; // O(n log n)
    cout << "Code 5: " << BigOdetection(code5) << endl; // O(n^2)

    cout << endl;
    //////////////////////////////////////////////////////////////////////////
    cout << "--------Algorithms Test---------------------" <<endl;
    cout << endl;

    string alg1 = R"(
        void Function1(int arr[], int n) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    )";
    cout << "Algorithm 1: " << BigOdetection(alg1) << endl; // Algorithm 1: O(n^2)

    string locateItem =
        "void locateItem(int array[], int n, int target) {\n"
        " for (int i = 0; i < n; ++i)\n"
        " if (array[i] == target)\n"
        " return;\n"
        "}";
    cout << "locateItem: " << BigOdetection(locateItem) << endl; // locateItem:  O(n)


    string focusedScan =
        "void focusedScan(int array[], int n, int key) {\n"
        "    int min = 0, max = n;\n"
        "    while (min < max) {\n"
        "        int mid = (min + max) / 2;\n"
        "        if (array[mid] == key) return;\n"
        "        (array[mid] < key) ? min = mid + 1 : max = mid;\n"
        "    }\n"
        "}";
    cout << "focusedScan: " << BigOdetection(focusedScan) << endl; // focusedScan: O(log n)

   
    string stabilizeStream =
        "void stabilizeStream(int array[], int n) {\n"
        " bool swapped = true;\n"
        " int pass = 0;\n"
        " while (swapped) {\n"
        " swapped = false;\n"
        " for (int j = 0; j < n - pass - 1; ++j) {\n"
        " if (array[j] > array[j + 1]) {\n"
        " swap(array[j], array[j + 1]);\n"
        " swapped = true;\n"
        " }\n"
        " }\n"
        " ++pass;\n"
        " }\n"
        "}";
    cout << "stabilizeStream: " << BigOdetection(stabilizeStream) << endl; // stabilizeStream: O(n^2)

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
    cout << "slotAligner: " << BigOdetection(slotAligner) << endl; // slotAligner: O(n^2)

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
    cout << "minimumPlacer: " << BigOdetection(minimumPlacer) << endl; // minimumPlacer: O(n^2)

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
    cout << "spacingPass: " << BigOdetection(spacingPass) << endl; // spacingPass:  O(n^2)

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
    cout << "ladderWalk: " << BigOdetection(ladderWalk) << endl; // ladderWalk:  O(n^2)

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
    cout << "rippleScan: " << BigOdetection(rippleScan) << endl; // rippleScan:  O(n^2)


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
    cout << "shrinkingArea: " << BigOdetection(shrinkingArea) << endl; // shrinkingArea:  O(n^2)

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
    cout << "parityWave: " << BigOdetection(parityWave) << endl; // parityWave:  O(n^2)

    string balance =
        "void balance(int array[], int n) {\n"
        "    if (n==0) return;\n"
        "\n"
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
    cout << "balance: " << BigOdetection(balance) << endl; // balance: O(n^2)


    cout << endl;

    //Tokens/////////////////////////////////////////////////////////////
    cout << "--------TOKEN TEST -------------------------"<<endl;
    cout << endl;

    string tokenString = "for (int i=0; i<n; i++);";

    vector<string> tokens = tokenize(tokenString);

    for (string t : tokens)
        cout << t << endl;

    return 0;
}