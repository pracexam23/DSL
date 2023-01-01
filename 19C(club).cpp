/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of
club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists
*/

#include <iostream>
using namespace std;

struct Node{
        int PRN;
        string name;
        Node *next;

        Node(int _PRN, string _name){
            PRN = _PRN;
            name = _name;
            next = NULL;
        }
        friend class Club;
};

class Club{
    Node *head;  
public:
    Club(): head(NULL) {};

    void create();
    void insert_Member();
    void insert_President();
    void insert_Secretary();
    void delete_Member();
    void delete_President();
    void delete_Secretary();
    void display();
    int size_of_club();
    void sort_list();
    void concatenate(Club &lst);
};

void Club::create(){
    int PRN;
    string name;

    if(head == NULL){
        cout<<"\nEnter PRN number: ";       cin>>PRN;
        cout<<"\nenter name: ";             cin>>name;
        head = new Node(PRN, name);
        cout<<"\nList created"<<endl;
    }
    else    
        cout<<"\nList is already present"<<endl;
}

void Club::insert_President(){
    int PRN;
    string name;
    Node *temp;

    if(head == NULL)
        create();
    else{
        // To add new president
        cout<<"\nEnter PRN number: ";       cin>>PRN;
        cout<<"\nenter name: ";             cin>>name;
        temp = new Node(PRN, name);
        temp->next = head;     // point to current president
        head = temp;
        cout<<"\n"<<head->name<<" has been added as president"<<endl;
    }
}

void Club::display(){
    Node *temp;
    temp = head;

    if(head == NULL)
        cout<<"\nList has not been created yet"<<endl;
    else{
        while(temp != NULL){
            cout<<  temp->PRN   <<" "<<   temp->name    <<endl;
            temp = temp->next;
        }
    }
}

void Club::insert_Member(){
    int prev_Member{}, flag{};
    cout<<"\nEnter PRN of member after whom entry should be done: ";       cin>>prev_Member;
    int PRN;
    string name;
    Node *temp;
    temp = head;
    
    while(temp != NULL){
        if(temp->PRN == prev_Member){
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 1){
        Node *t;
        cout<<"\nEnter PRN number: ";       cin>>PRN;
        cout<<"\nenter name: ";             cin>>name;
        t = new Node(PRN, name);
        t->next = temp->next;
        temp->next = t;
    }
    else    
        cout<<prev_Member<<" is not in the list"<<endl;
}

void Club::insert_Secretary(){
    int PRN;
    string name;
    Node *temp;
    temp = head;

    if(head == NULL)
        create();
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        cout<<"\nEnter PRN number: ";       cin>>PRN;
        cout<<"\nenter name: ";             cin>>name;
        temp->next = new Node(PRN, name);        
    }    
}

void Club::delete_President(){
	Node *temp;
	if(head == NULL)
		cout<<"\nList is empty"<<endl;
	else{
		temp = head;                 //copying president node into temp and then deletinf that node
		head = temp->next;
		delete temp;
		cout<<"\nPresident deleted"<<endl;
	}
}

void Club::delete_Secretary(){
	Node *temp, *prev;
	temp = head;
	if(head == NULL)
		cout<<"\nList is empty"<<endl;
	else{
		// iterate to the last node
		while(temp->next != NULL){
			prev = temp;             // preserving the node before last(secretary) node
			temp = temp->next;
		}
		prev->next = NULL;            //making this the last node
		delete temp;
		cout<<"\nSecretary deleted"<<endl;
	}
}

void Club::delete_Member(){
	Node *temp, *prev;
	int PRN, flag = 0;
	temp = head->next;
	if(head == NULL)
		cout<<"\nList is empty"<<endl;
	else{
		cout<<"\nEnter PRN of the member to be deleted: "<<endl;	cin>>PRN;
		
		while(temp->next != NULL){
			if(temp->PRN != PRN){
				flag = 1;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		if(flag == 1){
			prev->next = temp->next;
			temp->next = NULL;
			delete temp;
			cout<<"\nMember with PRN"<<PRN<<" deleted"<<endl;
		}
		else
			cout<<"\nNo  member with PRN"<<PRN<<" is present"<<endl;
	}
}

int Club::size_of_club(){
	Node *temp;
	temp = head;
	int count{};
	if(head == NULL){
		cout<<"\nList is empty"<<endl;
		return 0;
	}
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return 0;
}

void Club::sort_list(){
    if(head == NULL){
        cout<<"\nList has not been created yet"<<endl;
        return;
    }

    Node *i, *j;
    int temp_PRN;
    string temp_name;

    for(i=head; i->next!=NULL; i=i->next){
        for(j=head; j->next!=NULL; j=j->next){
            if((j->PRN) > (j->next->PRN)){

                temp_PRN = j->next->PRN;
                j->next->PRN = j->PRN;
                j->PRN = temp_PRN;

                temp_name = j->next->name;
                j->next->name = j->name;
                j->name = temp_name;
            }
        }
    }

    cout<<"\nList is sorted"<<endl;
    display();
}

void Club::concatenate(Club &lst){
    Node *temp;
    temp = lst.head;

    if(temp == NULL)
        cout<<"\n2nd list is empty"<<endl;
    
    Node *last;
    last = head;
    while(last->next != NULL)
        last = last->next;
    last->next = temp;
    cout<<"\nAfter concatenation"<<endl;
    display();
    
}

int main(){
    Club *lst, lst1, lst2;
    int choice{}, select{};

select:
    cout<<"\nChoose list\n"<<
				"1) List 1\n"<<
				"2) List 2\n"<<
				"Enter choice: ";
	cin>>select;
    
    if(select == 1)
        lst = &lst1;
    else if(select == 2)
        lst = &lst2;
    else{
        cout<<"\nInvalid choice"<<endl;
        goto select;
    }

    do{
			cout<<"\n\nMenu--------------------------------------------------------"<<endl<<
					"1) Create list\n"<<
					"2) Display list\n"<<
					"3) Enter President\n"<<
					"4) Enter Secretary\n"<<
					"5) Enter Member\n"<<
					"6) Delete President\n"<<
					"7) Delete Secretary\n"<<
					"8) Delete Member\n"<<
					"9) Display size of club\n"<<
					"10) Sort List by PRN\n"<<
					"11) Concatenate both list\n"<<
					"12) Exit\n"<<
					"Enter choice: ";
					
			cin>>choice;
            cout<<"\n\n";
			
			switch(choice){
				case 1:
					lst->create();
					break;
				case 2:
					lst->display();
					break;
				case 3:
					lst->insert_President();
					break;
				case 4:
					lst->insert_Secretary();
					break;
				case 5:
					lst->insert_Member();
					break;
				case 6:
					lst->delete_President();
					break;
				case 7:
					lst->delete_Secretary();
					break;
				case 8:
					lst->delete_Member();
					break;
				case 9:
					lst->size_of_club();
					break;
				case 10:
					lst->sort_list();
					break;
				case 11:
					lst1.concatenate(lst2);
					break;
				default:
					cout<<"\nInvalid choice"<<endl;			
			}
				
		}while(choice != 12);
}