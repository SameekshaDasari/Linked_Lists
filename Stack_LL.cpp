#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* link;
    Node(int value): data(value), link(NULL){}
};

class Head_Node{
public:
    Node* top;
    int count;
    Head_Node(): count(0), top(NULL) {}
};

void push(Head_Node* &head){
    int data;
    cout << "Enter Value: "; cin >> data;
    Node* new_node = new Node(data);
    new_node->link = head->top;
    head->top = new_node;
    head->count = head->count + 1;}

void pop(Head_Node* &head){
    if (head->top != NULL){
        Node* temp = head->top;
        head->top = temp->link;
        free(temp);
        head->count = head->count - 1;
    }
    else cout << "UNDERFLOW!!" << endl;}

void search(Head_Node* head, int tar){
    Node* temp = head->top;
    int pos=0;
    while (temp != NULL){
        if (temp->data==tar){
            cout << "ELEMENT FOUND AT POSITION: " << pos << endl;
            return;}
        else{
            temp = temp->link;
            pos++;}
    }
    cout << "ELEMENT NOT FOUND!" << endl;
}

void display(Head_Node* head){
    Node* temp = head->top;
    while (temp != NULL){
        cout << temp->data <<"->";
        temp = temp->link;
    }
    cout << "NULL" << endl;
    cout << "COUNT: " << head->count << endl;
}

int main(){
    int choice, target;
    char cont = 'y';
    Head_Node* HN = new Head_Node();
    while(cont=='y'){
        cout << "MENU\n1. PUSH\n2. POP\n3. SEARCH\n4. DISPLAY\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                push(HN);
                break;
            case 2:
                pop(HN);
                break;
            case 3:
                cout << "TARGET: "; cin >> target;
                search(HN, target);
                break;
            case 4:
                display(HN);
                break;
            default:
                cout << "INVALID INPUT" << endl;
                cin.clear();
                cin.ignore();
        }
        cout << "CONTINUE? (y/n): "; cin >> cont;
    }
}