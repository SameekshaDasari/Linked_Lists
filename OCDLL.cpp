//OCD-LL
#include <iostream>
using namespace std;

class Node_{ public:
    Node_* previous;
    int data;
    Node_* next;
    Node_(int value): previous(NULL), data(value), next(NULL){}
};

class Metadata_{ public:
    Node_* front;
    int count;
    Node_* rear;
    Metadata_(): front(NULL), count(0), rear(NULL) {}
};

void insertion(Metadata_* &head){
    int data;
    cout << "Enter Value: "; cin >> data;
    Node_* new_node = new Node_(data);
    if(head->count==0){
        head->front = new_node;
        head->rear = new_node;
        new_node->previous = new_node;
        new_node->next = new_node;}
    else if (data < head->front->data || data > head->rear->data){
        new_node->previous = head->rear;
        new_node->next = head->front;
        head->front->previous = new_node;
        head->rear->next = new_node;
        if (data < head->front->data)
            head->front = new_node;
        else if (data > head->rear->data)
            head->rear = new_node;}
    else {
        Node_* temp = head->front;
        for(int j=1; j<head->count && data > temp->data; j++, temp = temp->next){}
        new_node->previous = temp->previous;
        new_node->next = temp;
        temp->previous->next = new_node;
        temp->previous = new_node;}
    head->count++;}

void deletion(Metadata_* &head, int tar){
    Node_* temp = head->front;
    if (head->front!=NULL && head->count == 1 && tar == temp->data){
        free(temp);
        head->front = NULL;
        head->rear = NULL;
        head->count--;}
    else if(head->front != NULL && tar == temp->data){
        temp->next->previous = head->rear;
        head->rear->next = temp->next;
        head->front = temp->next;
        free(temp);
        head->count--;}
    else if (head->rear != NULL && tar == head->rear->data){
        Node_* dummy = head->rear;
        dummy->previous->next = head->front;
        head->front->previous = dummy->previous;
        head->rear = dummy->previous;
        free(dummy);
        head->count--;}
    else{
        for(int y=0; y<head->count && tar >= temp->data; y++, temp = temp->next){
            if(tar==temp->data){
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                free(temp);
                head->count--;
                return;
            }}
        cout << "OUT OF BOUND!!" << endl;}
    }

int search(Metadata_* head, int tar){
    Node_* temp = head->front; int a;
    for(a=0; a<head->count && tar >= temp->data; a++, temp = temp->next){
        if (temp->data==tar)
            return a;}
    return -1;}

void display_f(Metadata_* head){
    Node_* temp = head->front; int k;
    for(k=0; k < head->count && temp != NULL; k++, temp = temp->next)
        cout << "<-->" << temp->data;
    cout << "<-->\nCOUNT: " << head->count << endl;}

void display_r(Metadata_* tail){
    Node_* temp = tail->rear; int x;
    for(x=0; x < tail->count && temp != NULL; x++, temp = temp->previous)
        cout << "<-->" << temp->data;
    cout << "<-->\nCOUNT: " << tail->count << endl;
}

int main(){
    int choice, position, target;
    char cont = 'y';
    Metadata_* info = new Metadata_();
    while (cont=='y'){
        cout << "MENU\n1. INSERTION\n2. DELETION\n3. SEARCH\n4. DISPLAY_FRONT\n5. DISPLAY_REAR\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                insertion(info);
                break;
            case 2:
                cout << "TARGET: "; cin >> target;
                deletion(info, target);
                break;
            case 3:
                cout << "TARGET: "; cin >> target;
                position = search(info, target);
                if (position==-1) cout << "ELEMENT NOT FOUND!!" << endl;
                else cout << "ELEMENT FOUND AT POSITION: " << position << endl;
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