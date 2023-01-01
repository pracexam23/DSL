/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and display
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/
#include <iostream>
using namespace std;


class Node{
private:
    int data;
    Node *next;
public:
    Node *head;

    Node* create();
    void display(Node*);
    void vanilla_and_butterscotch(Node*, Node*);
    int vanilla_or_butterscotch(Node*, Node*);
    void not_Both(Node*, Node*);
};

Node* Node::create(){
    int rollNo;
    cout<<"\nIf you want to stop enter '0"<<endl;
    Node *newNode, *temp;
    bool ifHead = true;    

    while(true){
        cout<<"Enter rollNo. of students: ";    cin>>rollNo;
        if(rollNo == 0) break;
        // just a node creation
        newNode = new Node;
        newNode->data = rollNo;
        newNode->next = NULL;
        //what if node is head node?
        if(ifHead == true){
            head = newNode;
            temp = head;
            ifHead = false;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }        
    }
    return head;
}

void Node::display(Node *head){
    Node *temp = head;
    if(temp == NULL){
        cout<<"\nList is not created"<<endl;
        return;
    }
    else{
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

void Node::vanilla_and_butterscotch(Node *vanilla_head, Node *butterscotch_head){
    Node *V, *B;

    for(V=vanilla_head; V!=NULL; V=V->next){
        for(B=butterscotch_head; B!=NULL; B=B->next){
            if(V->data == B->data)
                cout<<V->data<<" ";
        }
    }
}

void Node::not_Both(Node *vanilla_head, Node *butterscotch_head){
    Node *V, *B;
    int found{};

    for(V=vanilla_head; V!=NULL; V=V->next){
        found = 0;
        for(B=butterscotch_head; B!=NULL; B=B->next){
            if(V->data == B->data){
                found = 1;
                continue;
            }                
        }
        if(found == 0)
            cout<<V->data<<" ";
    }
    for(B=butterscotch_head; B!=NULL; B=B->next){
        found = 0;
        for(V=vanilla_head; V!=NULL; V=V->next){
            if(B->data == V->data){
                found = 1;
                continue;
            }            
        }
        if(found == 0)
            cout<<B->data<<" ";
    }
}

int Node::vanilla_or_butterscotch(Node *vanilla_head, Node *butterscotch_head){
    int count{}, found{};
    Node *V, *B;

    V = vanilla_head;
    while(V != NULL){
        cout<<V->data<<" ";
        count++;
        V = V->next;
    }
    
    for(B=butterscotch_head; B!=NULL; B=B->next){
        found = 0;
        for(V=vanilla_head; V!=NULL; V=V->next){
            if(B->data == V->data){
                found = 1;
                continue;
            }
        }
        if(found == 0){
            cout<<B->data<<" ";
            count++;
        }
    }
    return count;
}


int main(){
    Node obj;
    Node *vanilla_head, *butterscotch_head;
    int choice, students, count;

    cout << "\nEnter the no of Students : ";    cin>>students;


    do{
        cout<<"\n1. Create list of students of like Vanilla and students whi like butterscotch";
        cout<<"\n2. Set of students who like both vanilla and butterscotch";
        cout<<"\n3. Set of students who like either vanilla or butterscotch or not both";
        cout<<"\n4. Number of students who like neither vanilla nor butterscotch";        
        cout<<"\n5. Exit";
        cout<<"\nEnter Choise: ";
        cin>>choice;    

        switch(choice){
            case 1:
                cout<<"\nVanilla List"<<endl;
                vanilla_head = obj.create();
                obj.display(vanilla_head);
                cout<<"\nButterscotch List"<<endl;
                butterscotch_head = obj.create();
                obj.display(butterscotch_head);
                break;
            
            case 2:
                obj.vanilla_and_butterscotch(vanilla_head, butterscotch_head);
                break;

            case 3:
                obj.not_Both(vanilla_head, butterscotch_head);
                break;

            case 4:
                count = obj.vanilla_or_butterscotch(vanilla_head, butterscotch_head);
                cout<<"\n"<<count<<"!!!!"<<endl;
                cout<<"\nNumber of students who like neither vanilla nor butterscotch are: "<<students - count<<endl;
                break;
            
            default:
                cout<<"\nInvalid chocie";
                break;
        }
    }while(choice != 5);
}