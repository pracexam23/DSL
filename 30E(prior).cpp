/*
Write program to implement a priority queue in C++ using an inorder list to store the
items in the queue. Create a class that includes the data items (which should be
template) and the priority (which should be int). The inorder list should contain these
objects, with operator <= overloaded so that the items with highest priority appear at the
beginning of the list (which will make it relatively easy to retrieve the highest item.)
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
class PriorityQueue{
    struct Item{
        T data;
        int priority;

        Item(T data_, int priority_) : data(data_), priority(priority_) {};

        bool operator<= (const Item &other) const{
            return priority <= other.priority;
        }
    };

    list<Item> queue{};
public:
    void enqueue(T data, int priority){
        Item item = {data, priority};

        auto it = queue.begin();
        while(it != queue.end() && item <= *it){
            it++;
        }
        queue.insert(it, item);
    }

    T dequeue(){
        T data = queue.front().data;
        queue.pop_front();
        return data;
    }

    bool empty(){
        return queue.empty();
    }

    void display(){
        cout<<"Queue : ";
        auto it = queue.begin();
        for(auto ele: queue) cout<<ele.data<<" ";
        cout<<"\n";
    }
};

int main(){
    PriorityQueue<int> pq;

    bool flag = false;

    while(!flag){
        cout<<"Menu:"<<endl;
        cout<<"1. Enqueue an item"<<endl;
        cout<<"2. Dequeue the highest priority item"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";

        int choice;
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"\nEnter the data and priority of the item: ";
                int data, priority;
                cin>>data>>priority;
                pq.enqueue(data, priority);
                pq.display();
                break;
            case 2:
                if(pq.empty())
                    cout<<"\nQueue is empty!"<<endl;
                else{
                    cout<<"\nDequeued item: "<<pq.dequeue()<<endl;
                    pq.display();
                }
                break;
            case 3:
                flag = true;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
                break;
        }
    }
}