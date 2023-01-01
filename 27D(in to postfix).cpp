/*
Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.
*/

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c){
    if((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'))
        return true;
    return false;
}

int precedence(char c){
    if(c == '^')                    return 3;
    if((c == '/') || (c == '*'))    return 2;
    if((c == '+') || (c == '-'))    return 1;
    else                            return -1;
}

string infixToPostfix(stack<char> stack, string infix_Expression){
    string postfix_expression;

    int len = infix_Expression.length();
    for(int i=0; i!=len; i++)
    {
        if((infix_Expression[i] >= 'a' && infix_Expression[i] <= 'z') || (infix_Expression[i] >= 'A' && infix_Expression[i] <= 'Z'))
            postfix_expression += infix_Expression[i];
        else if(infix_Expression[i] == '(')
            stack.push(infix_Expression[i]);
        else if(infix_Expression[i] == ')')
        {
            while((stack.top() != '(') && (!stack.empty()))
            {
                postfix_expression += stack.top();
                stack.pop();
            }
            if(stack.top() == '(')
                stack.pop();
        }

        else if(isOperator(infix_Expression[i]))
        {
            if(stack.empty())
                stack.push(infix_Expression[i]);
            else
            {
                if(precedence(infix_Expression[i] > precedence(stack.top())))
                    stack.push(infix_Expression[i]);
                else if(precedence(infix_Expression[i] == precedence(stack.top())))
                    stack.push(infix_Expression[i]);
                else{
                    while((!stack.empty()) && (precedence(infix_Expression[i] < precedence(stack.top())))){
                        postfix_expression += stack.top();
                        stack.pop();
                    }   
                    if(stack.top() == '(')
                        stack.pop();
                    stack.push(infix_Expression[i]);
                }
            }
        }
    }
    while(!stack.empty()){
        postfix_expression += stack.top();
        stack.pop();
    }
    return postfix_expression;
}

int main(){

    stack<char> stack;

    string infix_Expression;
    cout<<"\nEnter infix expression: ";   cin>>infix_Expression;

    string postfix_Expression = infixToPostfix(stack, infix_Expression);
    cout<<"\nPostfix expression is: "<<postfix_Expression;
}