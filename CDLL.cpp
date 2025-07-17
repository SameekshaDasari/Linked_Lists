//CDLL
#include<iostream>
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

void insertion(Metadata_* &head, int pos){
    int data;
    cout << "Enter Value: "; cin >> data;
    Node_* new_node = new Node_(data);
    if (head->count==0 && pos==0){
        head->front = new_node;
        head->rear = new_node;
        new_node->previous = new_node;
        new_node->next = new_node;
        head->count++;}
    else if (head->count != 0 && (pos==0 || pos==head->count)){
        new_node->next = head->front;
        new_node->previous = head->rear;
        head->front->previous = new_node;
        head->rear->next = new_node;
        if (pos==0)
            head->front = new_node;
        else if (pos==head->count)
            head->rear = new_node;
        head->count++;}
    else{
        Node_* temp = head->front;
        int i=0;
        while(i<pos-1 && i<head->count-1){
            temp = temp->next;
            i++;}
        if (temp != NULL && i==pos-1){
            new_node->previous = temp;
            new_node->next = temp->next;
            new_node->next->previous = new_node;
            temp->next = new_node;
            head->count++;}
        else
            cout << "OUT OF BOUND!!" << endl;}
}

void deletion(Metadata_* &head, int pos){
    Node_* temp = head->front;
    if (head->front != NULL && pos==0 && head->count==1){
        free(temp);
        head->front = NULL;
        head->rear = NULL;
        head->count--;}
    else if(head->front != NULL && pos==0){
        temp->next->previous = head->rear;
        head->rear->next = temp->next;
        head->front = temp->next;
        free(temp);
        head->count--;}
    else if (head->rear != NULL && pos==head->count-1){
        Node_* dummy = head->rear;
        dummy->previous->next = head->front;
        head->front->previous = dummy->previous;
        head->rear = dummy->previous;
        free(dummy);
        head->count--;}
    else{
        int k=0;
        while (k<pos-1 && k<head->count-1){
            temp = temp->next;
            k++;}
        if (k==pos-1 && temp != NULL && k<head->count-1){
            Node_* del = temp->next;
            temp->next = del->next;
            del->next->previous = temp;
            free(del);
            head->count--;}
        else
            cout << "OUT OF BOUND!!" << endl;
    }
}

int search(Metadata_* tail, int tar){
    Node_* temp = tail->rear; int j;
    for(j=0; j<tail->count && temp != NULL; j++, temp = temp->next){
        if (temp->data==tar)
            return j-1;}
    return -100;
}

void display(Metadata_* head){
    Node_* temp = head->front; int j;
    for(j=0; j<head->count && temp != NULL; j++, temp = temp->next)
        cout << "<-->" << temp->data;
    cout << "<-->\nCOUNT: " << head->count << endl;
}

int main(){
    int choice, position, target;
    char cont = 'y';
    Metadata_* info = new Metadata_();
    while (cont=='y'){
        cout << "MENU\n1. INSERTION\n2. DELETION\n3. SEARCH\n4. DISPLAY\nEnter your choice: ";
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
                position = search(info, target);
                if (position==-1) cout << "ELEMENT FOUND AT POSITION: " << info->count-1 << endl;
                else if (position==-100) cout << "ELEMENT NOT FOUND!!" << endl;
                else cout << "ELEMENT FOUND AT POSITION: " << position << endl;
                break;
            case 4:
                display(info);
                break;
            default:
                cout << "INVALID INPUT!" << endl;
                cin.clear();
                cin.ignore();}
        cout << "CONTINUE ? (y/n): "; cin >> cont;
    }
}
