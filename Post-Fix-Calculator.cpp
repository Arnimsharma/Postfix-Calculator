#include <bits/stdc++.h>
using namespace std;

// Function for the operation
int performOperation(int operand1, int operand2, char operation) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                cout << "Error: Division by zero!" << endl;
                exit(1);  // Exit if division by zero
            }
        default:
            return 0;
    }
}

//postfix expression
int evaluatePostfix(string expression) {
    stack<int> s;  // Stack implementation
    stringstream ss(expression); //works to read or write in a single stream like cin
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            // If it is a number push it to the stack 
            s.push(stoi(token)); // stoi is string to the integer
        } else {
            // if token is operator then perform the operation
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            int result = performOperation(operand1, operand2, token[0]);
            s.push(result);  // Push result back and continue
        }
    }
    return s.top(); //final result
}

int main() {
    cout << "Enter your postfix expression with spaces like - 7 2 * 6 + : ";

    string expression;
    getline(cin, expression);

    int result = evaluatePostfix(expression);

    cout << "your answer is " << result << endl;

    return 0;
}