#include <iostream>
#include <vector>
#include <string>

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
// Stackframe structure
// ------------------------------------------------------------
struct Frame {
    int value;
    string note = "";
};

// ------------------------------------------------------------
// Stackframe visualizer
// ------------------------------------------------------------
void printStackFrames(const vector<Frame>& frames) {
    cout << ANSI_CYAN << "   StackFrames: [ ";
    for (size_t i = 0; i < frames.size(); i++) {
        cout << "{n=" << frames[i].value  << frames[i].note << "}";
        if (i != frames.size() - 1) cout << " | ";
    }
    cout << " ] <--- top" << ANSI_RESET << "\n";
}

// ------------------------------------------------------------
// Recursive binary converter with stackframe visualization
// ------------------------------------------------------------
void toBinary(int n, vector<Frame>& callstack) {

    // PUSH FRAME
    cout << ANSI_LIME << " PUSH FRAME: n=" << n << ANSI_RESET << "\n";
    callstack.push_back({ n, "" });
    printStackFrames(callstack);

    cout << ANSI_YELLOW << "Token: call toBinary(" << n << ")" << ANSI_RESET << "\n";

    if (n > 1) {
        toBinary(n / 2, callstack);
    }

    cout << ANSI_YELLOW << "Token: output bit " << (n % 2) << ANSI_RESET << "\n";
    cout << (n % 2);

    // POP FRAME
    cout << "\n" << ANSI_RED << " POP FRAME: n=" << n << ANSI_RESET << "\n";
    callstack.pop_back();
    printStackFrames(callstack);
}

// ------------------------------------------------------------
// Main
// ------------------------------------------------------------
int main() {
    int value = 123;
    vector<Frame> callstack;

    cout << "\n=== Recursive Binary Conversion With Stackframe Visualization ===\n\n";
    cout << "Converting decimal " << value << " to binary:\n\n";

    toBinary(value, callstack);

    cout << "\n\n=== Done ===\n";
    return 0;
}