#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>
using namespace std;

class Check {
public:
    bool closingBrackets(char open, char close) {
        if (open == '(' && close == ')') {
            return true;
        }
        else if (open == '{' && close == '}') {
            return true;
        }
        else if (open == '[' && close == ']') {
            return true;
        }
        return false;
    }

    void checkBrackets(const string& line) {
        stack<char> brackets;
        int errorIndex = -1;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '(' || line[i] == '{' || line[i] == '[') {
                brackets.push(line[i]);
            }
            else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
                if (brackets.empty()) {
                    errorIndex = i;
                    break;
                }
                else if (closingBrackets(brackets.top(), line[i])) {
                    brackets.pop();
                }
                else {
                    errorIndex = i;
                    break;
                }
            }
            else if (line[i] == ';') {
                break;
            }
        }

        if (brackets.empty() && errorIndex == -1) {
            cout << "Рядок коректний" << endl;
        }
        else {
            for (int i = 0; i < errorIndex; i++) {
                cout << line[i];
            }
            cout << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string example1 = "({x-y-z} * [x + 2y] - (z + 4x)).";
    string example2 = "([x-y-z} * [x + 2y) - {z + 4x)].";

    Check checker;

    cout << example1 << endl;
    checker.checkBrackets(example1);

    cout << endl;

    cout << example2 << endl;
    checker.checkBrackets(example2);

    return 0;
}
