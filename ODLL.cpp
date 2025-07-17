//ODLL
#include <iostream>
using namespace std;

class Node{public:
    Node* prev;
    int data;
    Node* next;
    Node(int value): data(value), prev(NULL), next(NULL) {}};

void insertion(Node* &head){
    int data;
    cout << "Enter Value: "; cin >> data;
    Node* new_node = new Node(data);
    if (head == NULL){
        head = new_node;
        return;}
    else if (head->data > data){
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
        return;}
    Node* temp = head;
    while(data > temp->data && temp->next != NULL)
        temp = temp->next;
    if (data > temp->data && temp->next == NULL){
        new_node->prev = temp;
        temp->next = new_node;
        return;}
    new_node->prev = temp->prev;
    new_node->next = temp;
    temp->prev->next = new_node;
    temp->prev = new_node;
}

void deletion(Node* &head, int tar){
    Node* temp = head;
    if (head != NULL && head->data == tar){
        if(head->next!=NULL){
            temp->next->prev = NULL;
            head = temp->next;
            delete(temp);
            return;}
        head = NULL;
        delete(temp);
        return;}
    else{
        while (temp!=NULL && temp->data <= tar){
            if (temp->data==tar){
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                delete(temp);
                return;}
            temp = temp->next;}}
    cout << "ELEMENT NOT FOUND!!" << endl;
}

void search(Node* head, int tar){
    Node* temp = head; int i=0;
    while(temp!= NULL){
        if (temp->data == tar){
            cout << "ELEMENT FOUND AT POSITION: " << i << endl;
            return;}
        else{
            temp = temp->next;
            i++;}}
    cout << "ELEMENT NOT FOUND!!" << endl;}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "<-->";
        temp = temp->next;}
    cout << "NULL" << endl;}


int main(){
    int choice, target;
    char cont = 'y';
    Node* head = NULL;
    while(cont=='y'){
        cout << "MENU\n1. INSERTION\n2. DELETION\n3. SEARCH\n4. DISPLAY\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                insertion(head);
                break;
            case 2:
                cout << "TARGET: "; cin >> target;
                deletion(head, target);
                break;
            case 3:
                cout << "TARGET: "; cin >> target;
                search(head, target);
                break;
            case 4:
                display(head);
                break;
            default:
                cout << "INVALID INPUT!!";
                cin.clear();
                cin.ignore();}
        cout << "CONTINUE?(y/n): "; cin >> cont;}}