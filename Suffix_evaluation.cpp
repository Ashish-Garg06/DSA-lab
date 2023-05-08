#include <iostream>
#include <stack>  // Required to use stack data structure
#include <string> // Required to use string data type
#include <cmath>  // Required to use pow() function for exponentiation

using namespace std;

// Function to perform arithmetic operations
int performOperation(char op, int num1, int num2)
{
    switch (op)
    {
    case '+':                   // If the operator is addition
        return num1 + num2;     // Return the sum of two numbers
    case '-':                   // If the operator is subtraction
        return num1 - num2;     // Return the difference of two numbers
    case '*':                   // If the operator is multiplication
        return num1 * num2;     // Return the product of two numbers
    case '/':                   // If the operator is division
        return num1 / num2;     // Return the quotient of two numbers
    case '%':                   // If the operator is modulus
        return num1 % num2;     // Return the remainder of two numbers
    case '^':                   // If the operator is exponentiation
        return pow(num1, num2); // Return the result of raising num1 to the power of num2
    }
    return -1; // If the operator is not recognized, return -1
}

// Function to evaluate a suffix expression
int evaluateSuffixExpression(string exp)
{
    stack<int> stack;                      // Create an empty stack of integers
    for (int i = 0; i < exp.length(); i++) // Loop through each character of the string
    {
        char c = exp[i]; // Get the current character
        if (isdigit(c))  // If the character is a digit
        {
            // Convert the character to integer and push onto the stack
            stack.push(c - '0'); // Convert the character to integer and push it onto the stack
        }
        else // If the character is an operator
        {
            // Pop two operands from the stack and perform the operation
            int num2 = stack.top();                       // Get the top element of the stack and store it as num2
            stack.pop();                                  // Pop the top element from the stack
            int num1 = stack.top();                       // Get the new top element of the stack and store it as num1
            stack.pop();                                  // Pop the new top element from the stack
            int result = performOperation(c, num1, num2); // Perform the operation using num1, num2 and operator c, and store the result in result variable

            // Push the result back onto the stack
            stack.push(result); // Push the result onto the stack
        }
    }

    // The final element on the stack is the result of the expression
    return stack.top(); // Return the top element of the stack, which is the result of the expression
}

// Main function to test the program
int main()
{
    string exp;                                 // Declare a string variable to store the suffix expression
    cout << "Enter Suffix Expression: ";        // Prompt the user to enter the suffix expression
    getline(cin, exp);                          // Read the input from the user and store it in the exp variable
    int result = evaluateSuffixExpression(exp); // Evaluate the suffix expression and store the result in the result variable
    cout << "Result: " << result;               // Print the result of the suffix expression
    return 0;                                   // Return 0 to indicate successful execution of the program
}