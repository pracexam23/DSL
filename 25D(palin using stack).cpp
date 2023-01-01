/*
A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop”
is a palindrome, as can be seen by examining the characters “poor danisina droop” and
observing that they are the same forward and backward. One way to check for a
palindrome is to reverse the characters in the string and then compare with them the
original-in a palindrome, the sequence will be identical. Write C++ program with
functions
a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not
*/

#include <iostream>
#include <string.h>
using namespace std;

#define MAX 50

class Stack{
    char data[MAX];
    int top;
public:
    Stack(): top(-1) {};

    void convert(char []);
    void push(char);
    void palindrome();
    void reverse();
};

void Stack::convert(char str[]){
        int j, k, len = strlen(str);
        for(j=0, k=0; j!=len; j++){
            if(((int)str[j] >= 97) && ((int)str[j] <= 122) || ((int)str[j] >= 65) && ((int)str[j] <= 90)){
                if((int)str[j] <= 90){
                    str[k] = (char)(int)str[j]+32;
                }
                else
                    str[k] = str[j];
                k++;
            }
        }
        str[k] = '\0';
        cout<<"\nConverted string is: "<<str<<endl;
}

void Stack::push(char c){
    top++;
    data[top] = c;
    data[top + 1] = '\0';
    //cout<<"\nStack is pushed"<<endl;
}

void Stack::palindrome(){
    char str[MAX];
    int i, j;

    for(i=top, j=0; i!=-1; i--, j++)
        str[j] = data[i];
    str[j] = '\0';
    cout<<strcmp(str,data)<<endl;
    if(strcmp(str,data) == 0)
        cout<<"\nGiven string is a paliindrome"<<endl;
    else
        cout<<"\nGiven string is not a palindrome"<<endl;
}

void Stack::reverse(){
    for(int i=top; i>=0; i--){
        cout<<data[i];
    }
}

int main(){
    Stack stack;
    
    char str[MAX];
    cout<<"\nEnter string: ";   cin.getline(str, MAX);
    stack.convert(str);

    int i{};
    while(str[i] != '\0'){
        stack.push(str[i]);
        i++;
    }

    stack.palindrome();
    stack.reverse();
}