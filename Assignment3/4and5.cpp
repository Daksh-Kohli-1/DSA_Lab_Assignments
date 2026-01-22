#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Charstack {
    int top;
    int n;
    char* arr;
public:
    Charstack(int size) {
        top = -1;
        n = size;
        arr = new char[n];
    }
    ~Charstack() {
        delete[] arr;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == n - 1;
    }
    void push(char ele) {
        if (!isFull())
            arr[++top] = ele;
    }
    char pop() {
        if (!isEmpty())
            return arr[top--];
        return '\0';
    }
    char peek() {
        if (!isEmpty())
            return arr[top];
        return '\0';
    }
};

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(string str) {
    Charstack st(str.length());
    string ans = "";

    for (char c : str) {
        if (isalnum(c)) {
            ans += c; // operand → output
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                ans += st.pop();
            }
            st.pop(); // remove '('
        }
        else { // operator
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                ans += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        ans += st.pop();
    }

    cout << "Postfix Expression: " << ans << endl;
}

int main() {
    string str = "(a+b)*c";
    infixToPostfix(str);
    return 0;
}
