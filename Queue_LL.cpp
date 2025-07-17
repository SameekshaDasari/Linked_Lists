#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* link;
    Node(int value): data(value), link(NULL){}
};

class Queue_Key{
public:
    Node* front;
    Node* rear;
    int count;
    Queue_Key(): count(0), front(NULL), rear(NULL) {}
};

void enqueue(Queue_Key* &reference){
    int data;
    Node* temp = reference->rear;
    cout << "Enter Value: "; cin >> data;
    Node* new_node = new Node(data);
    if(reference->count==0){
        reference->front = new_node;
        reference->rear = new_node;
    }
    else{
        temp->link = new_node;
        reference->rear = new_node;}
    reference->count = reference->count + 1;}

void dequeue(Queue_Key* &reference){
    if (reference->front != NULL){
        if(reference->count==1){
            free(reference->front);
            reference->rear = NULL;
            reference->front= NULL;
        }
        else{
            Node* dummy = reference->front;
            reference->front = dummy->link;
            free(dummy);}
        reference->count = reference->count - 1;
    }
    else cout << "UNDERFLOW!!" << endl;}

void search(Queue_Key* &reference, int tar){
    if (reference->front && reference->rear==NULL){
        if (tar == reference->rear->data){
            cout << "ELEMENT FOUND AT POSITION: " << reference->count-1 << endl;
            return;}
        else{
            Node* temp = reference->front;
            int pos=0;
            while (temp != NULL){
                if (temp->data==tar){
                    cout << "ELEMENT FOUND AT POSITION: " << pos << endl;
                    return;}
                else{
                    temp = temp->link;
                    pos++;}
            }}}
    cout << "ELEMENT NOT FOUND!" << endl;
}

void display(Queue_Key* head){
    Node* temp = head->front;
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
    Queue_Key* QK = new Queue_Key();
    while(cont=='y'){
        cout << "MENU\n1. ENQUEUE\n2. DEQUEUE\n3. SEARCH\n4. DISPLAY\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                enqueue(QK);
                break;
            case 2:
                dequeue(QK);
                break;
            case 3:
                cout << "TARGET: "; cin >> target;
                search(QK, target);
                break;
            case 4:
                display(QK);
                break;
            default:
                cout << "INVALID INPUT" << endl;
                cin.clear();
                cin.ignore();
        }
        cout << "CONTINUE? (y/n): "; cin >> cont;
    }
}