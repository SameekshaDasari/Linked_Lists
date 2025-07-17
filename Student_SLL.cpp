#include <iostream>
using namespace std;

class Node{
public:
    string Name, Branch;
    int reg_no;
    Node* next;
    void get_data(){
        cin.ignore();
        cout << "NAME: "; getline(cin, Name);
        cout << "BRANCH: "; getline(cin, Branch);
        cout << "REGISTER NO: "; cin >> reg_no ;
        next = NULL;
    }
};

void insertion(Node* &head, int pos){
    int i=0;
    Node* new_node = new Node();
    new_node->get_data();
    if (pos==0){
        new_node->next = head;
        head = new_node;}
    else{
        Node* temp = head;
        while(i<pos-1 && temp!= NULL){
            temp = temp->next;
            i++;
        }
        if (i==pos-1 && temp!=NULL){
            new_node->next = temp->next;
            temp->next = new_node;}
        else cout << "OUT OF BOUND!" << endl;
    }
}

void deletion(Node* &head, int pos){
    int i=0;
    Node* temp = head;
    if (pos==0 && temp!= NULL){
        head = head->next;
        free(temp);
    }
    else{
        while(i<pos-1 && temp->next!= NULL){
            temp = temp->next;
            i++;
        }
        if (i==pos-1 && temp->next!=NULL){
            Node* end;
            end = temp->next;
            temp->next = end->next;
            free(end);}
        else cout << "OUT OF BOUND!" << endl;
    }
}

void search(Node* head, int tar){
    Node* temp = head;
    int pos=0;
    while (temp != NULL){
        if (temp->reg_no==tar){
            cout << "ELEMENT FOUND AT POSITION: " << pos << endl;
            return;}
        else{
            temp = temp->next;
            pos++;}
    }
    cout << "ELEMENT NOT FOUND!" << endl;
}

void display(Node* head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->Name <<" : " << temp->Branch << " : " << temp->reg_no << "::" << endl;
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    int choice, position, target;
    char cont = 'y';
    Node* head = nullptr;
    while(cont=='y'){
        cout << "MENU\n1. INSERTION\n2. DELETION\n3. SEARCH\n4. DISPLAY\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "POSITION: "; cin >> position;
                insertion(head, position);
                break;
            case 2:
                cout << "POSITION: "; cin >> position;
                deletion(head, position);
                break;
            case 3:
                cout << "TARGET (Reg_No): "; cin >> target;
                search(head, target);
                break;
            case 4:
                display(head);
                break;
            default:
                cout << "INVALID INPUT" << endl;
                cin.clear();
                cin.ignore();
        }
        cout << "CONTINUE? (y/n): "; cin >> cont;
    }
}