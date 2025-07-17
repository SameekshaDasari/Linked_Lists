#include <iostream>
using namespace std;

class Node{ public:
    Node* previous;
    int data;
    Node* next;
    Node(int value): previous(NULL), data(value), next(NULL){}
};

class Metadata{ public:
    Node* front;
    int count;
    Node* rear;
    Metadata(): front(NULL), count(0), rear(NULL) {}
};

void insertion(Metadata* &head, int pos){
    int data;
    cout << "Enter Value: "; cin >> data;
    Node* new_node = new Node(data);
    if (head->count == 0 && pos==0){
        head->front = new_node;
        head->rear = new_node;
        head->count++;}
    else if (pos==0){
        new_node->next = head->front;
        head->front->previous = new_node;
        head->front = new_node;
        head->count++;}
    else{
        Node* temp = head->front; int i=0;
        while (temp!=NULL && i<pos-1){
            temp = temp->next;
            i++;}
        if (i==pos-1 && temp!=NULL){
            new_node->previous = temp;
            new_node->next = temp->next;
            if (temp->next!=NULL)
                new_node->next->previous = new_node;
            else
                head->rear = new_node;
            temp->next = new_node;
            head->count++;}
        else
            cout << "OUT OF BOUND!!" << endl;}
}

void deletion(Metadata* &head, int pos){
    Node* temp = head->front; int j=0;
    if (pos==0 && temp != NULL){
        if (head->count!=1){
            temp->next->previous = NULL;
            head->front = temp->next;
            free(temp);}
        else{
            free(temp);
            head->front = NULL;
            head->rear = NULL;}
        head->count--;}
    else{
        while (j<pos-1 && temp != NULL){
            temp = temp->next;
            j++;}
        if (j==pos-1 && temp != NULL){
            Node* del = temp->next;
            temp->next = del->next;
            if (del->next!=NULL)
                del->next->previous = temp;
            else
                head->rear = temp;
            free(del);
            head->count--;
        }
        else
            cout << "OUT OF BOUND!!" << endl;
}}

void search(Node* head, int tar){
    Node* temp = head; int index=0;
    while(temp != NULL){
        if (temp->data == tar){
            cout << "ELEMENT FOUND AT INDEX: " << index << endl;
            return;}
        index++;
        temp = temp->next;}
    cout << "ELEMENT NOT FOUND!!" << endl;
}

void display_f(Metadata* head){
    Node* temp = head->front;
    while(temp != NULL){
        cout << temp->data << "<<-->>";
        temp = temp->next;}
    cout << "NULL\nCOUNT: " << head->count <<endl;
}

void display_r(Metadata* head){
    Node* temp = head->rear;
    cout << "REVERSED DISPLAY: \nNULL";
    while(temp != NULL){
        cout << "<<-->>" << temp->data;
        temp = temp->previous;
    }
    cout << "\nCOUNT: " << head->count << endl;
}


int main(){
    int choice, position, target; char cont = 'y';
    Metadata* info = new Metadata();
    while (cont=='y'){
        cout << "MENU\n1. INSERTION\n2. DELETION\n3. SEARCH\n4. DISPLAY_FROM_FRONT\n5. DISPLAY_FROM_REAR\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "POSITION: "; cin >> position;
                insertion(info, position);
                break;
            case 2:
                cout << "POSITION: "; cin >> position;
                deletion(info, position);
                break;
            case 3:
                cout << "TARGET: "; cin >> target;
                search(info->front, target);
                break;
            case 4:
                display_f(info);
                break;
            case 5:
                display_r(info);
                break;
            default:
                cout << "INVALID INPUT!" << endl;
                cin.clear();
                cin.ignore();}
        cout << "CONTINUE ? (y/n): "; cin >> cont;
    }
}