#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

// Function to perform arithmetic operations
int performOperation(char op, int num1, int num2)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    case '%':
        return num1 % num2;
    case '^':
        return pow(num1, num2);
    }
    return -1;
}

// Function to evaluate a suffix expression
int evaluateSuffixExpression(string exp)
{
    stack<int> stack;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (isdigit(c))
        {
            // Convert the character to integer and push onto the stack
            stack.push(c - '0');
        }
        else
        {
            // Pop two operands from the stack and perform the operation
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            int result = performOperation(c, num1, num2);

            // Push the result back onto the stack
            stack.push(result);
        }
    }

    // The final element on the stack is the result of the expression
    return stack.top();
}

// Main function to test the program
int main()
{
    string exp;
    cout << "Enter Suffix Expression: ";
    getline(cin, exp);
    int result = evaluateSuffixExpression(exp);
    cout << "Result: " << result;
    return 0;
}
