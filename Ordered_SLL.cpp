#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node (int val){
        value = val;
        next = NULL;}
};

class Previous{
public:
    Node* link;
    Previous (): link(NULL) {}};

void insertion (Node* &head){
    int data;
    cout << "Enter Value: "; cin >> data;
    Node* new_node = new Node(data);
    if (head == NULL || data < head->value){
        new_node->next = head;
        head = new_node;}
    else{
        Node* temp = head;
        Previous* Pointer = new Previous();
        while(temp->value < data && temp->next!= NULL){
            Pointer->link = temp;
            temp = temp->next;}
        if (temp->value >= data){
            new_node->next = Pointer->link->next;
            Pointer->link->next = new_node;}
        else
            temp->next = new_node;}
}

void deletion (Node* &head, int tar){
    Node* temp = head;
    if (tar==temp->value && temp != NULL){
        head = head->next;
        free(temp);}
    else{
        Previous* Pointer = new Previous();
        while(tar > temp->value && temp->next!= NULL){
            Pointer->link = temp;
            temp = temp->next;}
        if (tar==temp->value){
            Pointer->link->next = temp->next;
            free(temp);}
        else cout << "ELEMENT NOT FOUND!" << endl;}
}

void search(Node* &head, int tar){
    Node* temp = head;
    int pos=0;
    while (temp != NULL && tar <= temp->value){
        if (temp->value==tar){
            cout << "ELEMENT FOUND AT POSITION: " << pos << endl;
            return;}
        else{
            temp = temp->next;
            pos++;}}
    cout << "ELEMENT NOT FOUND!" << endl; }

void display(Node* head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->value <<"->";
        temp = temp->next;}
    cout << "NULL" << endl; }

void sum(Node* head){
    Node* temp = head;
    float sum=0;
    while(temp != NULL){
        sum = sum + temp->value;
        temp = temp->next;}
    cout << "SUM: " << sum << endl;}

int main(){
    int choice, target;
    char cont = 'y';
    Node* head = nullptr;
    while(cont=='y'){
        cout << "MENU\n1. INSERTION\n2. DELETION\n3. SEARCH\n4. DISPLAY\n5. SUM\nEnter your choice: ";
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
            case 5:
                sum(head);
                break;
            default:
                cout << "INVALID INPUT" << endl;
                cin.clear();
                cin.ignore();}
        cout << "CONTINUE? (y/n): "; cin >> cont;}
}