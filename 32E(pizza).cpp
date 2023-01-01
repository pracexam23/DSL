/*
Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
using circular queue using array
*/

#include <iostream>
using namespace std;

#define M 10

class Queue{
public:
    int data[M];
    int front, rear;

    Queue(): front(-1), rear(-1) {};

    bool full();
    bool empty();
    void enque(int);
    int dequeue();
};

bool Queue::full(){
    return (rear + 1) % M == front;
}

bool Queue::empty(){
    return front == -1;
}

void Queue::enque(int order){
    if(full()){
        cout<<"\tQueue is full"<<endl;
        return;
    }

    if(empty())
        rear = front = 0;
    else
        rear = (rear + 1) % M;
    data[rear] = order;
    cout<<"\nOrder has been placed"<<endl;
}

int Queue::dequeue(){
    if(empty()){
        cout<<"\nQueue is empty"<<endl;
        return -1;
    }
    int servedOrder = data[front];
    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % M;
    return servedOrder;
}

int main(){
    Queue q;
    int choice;

    do{
        cout<<"\nMENU"<<
              "\n1. Place order"<<
              "\n2. Serve order"<<
              "\n3. display queue"<<
              "\nEnter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                int order;
                cout<<"\nEnter table number: ";   cin>>order;
                q.enque(order);
                break;
            
            case 2:
                int servedOrder;
                servedOrder = q.dequeue();
                if(servedOrder == -1){
                    cout<<"\nQueue is empty"<<endl;
                    break;
                }
                cout<<"\nOrder at table number "<<servedOrder<<" has been served"<<endl;
                break;
            
            case 3:\
                cout<<"\nCurrent order queue: ";
                for(int i=q.front; i!=(q.rear+1); i++){
                    cout<<q.data[i]<<" ";
                }
                break;

            default:
                cout<<"\nInvalid choice"<<endl;
                break;
        }

    }while(choice != 4);
}