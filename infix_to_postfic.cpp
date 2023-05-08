#include <iostream>
#include <stack>
using namespace std;

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

void infix_postfix(char infix[], char postfix[])
{
    stack<char> s;
    s.push('#');
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char symbol = infix[i];
        while (F(s.top()) > G(symbol))
        {
            postfix[j] = s.top();
            s.pop();
            j++;
        }
        if (F(s.top()) != G(symbol))
        {
            s.push(symbol);
        }
        else
        {
            s.pop();
        }
    }
    while (s.top() != '#')
    {
        postfix[j] = s.top();
        s.pop();
        j++;
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[20], postfix[20];
    cout << "Enter a valid infix expression: ";
    cin.getline(infix, 20);
    infix_postfix(infix, postfix);
    cout << "The infix expression is: " << infix << endl;
    cout << "The postfix expression is: " << postfix << endl;
    return 0;
}