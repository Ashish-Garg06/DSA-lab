#include <iostream>
#include <stack>
using namespace std;

// Function to return the precedence of the operator
int F(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2; 
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
    case '#':
        return -1;
    default:
        return 8;
    }
}

// Function to return the priority of the symbol
int G(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
    case ')':
    default:
        return 7;
    }
}

// Function to convert infix expression to postfix expression
void infix_postfix(char infix[], char postfix[])
{
    // Create a stack and push '#' into it
    stack<char> s;
    s.push('#');
    int j = 0;
    // Traverse the infix expression
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char symbol = infix[i];
        // Pop and append the symbols with higher precedence from stack to postfix expression
        while (F(s.top()) > G(symbol))
        {
            postfix[j] = s.top(); // Append the top symbol of stack to postfix expression
            s.pop();              // Pop the top symbol from stack
            j++;                  // Increment the index of postfix expression
        }
        // Push the symbol onto the stack if its precedence is lower than the top of stack or if the stack is empty
        if (F(s.top()) != G(symbol))
        {
            s.push(symbol); // Push the symbol onto the stack
        }
        else
        {
            s.pop(); // Pop the symbol if its precedence is equal to the top of stack
        }
    }
    // Pop and append the remaining symbols from stack to postfix expression
    while (s.top() != '#')
    {
        postfix[j] = s.top(); // Append the top symbol of stack to postfix expression
        s.pop();              // Pop the top symbol from stack
        j++;                  // Increment the index of postfix expression
    }
    postfix[j] = '\0'; // Add null character at the end of postfix expression
}


int main()
{
    char infix[20], postfix[20];
    cout << "Enter a valid infix expression: ";
    cin.getline(infix, 20);                                   // Input the infix expression
    infix_postfix(infix, postfix);                            // Convert infix expression to postfix expression
    cout << "The infix expression is: " << infix << endl;     // Display the infix expression
    cout << "The postfix expression is: " << postfix << endl; // Display the postfix expression
    return 0;
}