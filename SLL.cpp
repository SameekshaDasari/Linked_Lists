#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node(int val){
        value = val;
        next = NULL;
    }
};

void insertion(Node* &head, int pos){
    int data, i=0;
    cout << "Enter Value: "; cin >> data;
    Node* new_node = new Node(data);
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
        if (temp->value==tar){
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
        cout << temp->value <<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void sum(Node* head){
    Node* temp = head;
    int sum=0;
    while(temp != NULL){
        sum = sum + temp->value;
        temp = temp->next;}
    cout << "SUM: " << sum << endl;}

void Swap(Node* &head, int initial, int final){
    if (initial != final){
        Node* temp_1 = head; int i=0;
        Node* temp_2 = head; int j=0;
        while(temp_1 != NULL && i<initial-1){
            temp_1 = temp_1->next;
            i++;}
        while (temp_2 != NULL && j<final-1){
            temp_2 = temp_2->next;
            j++;}
        if (i==initial-1 && j==final-1 && temp_1 !=NULL){
            Node* temp_3 = temp_2->next->next;
            if (final-initial == 1){
                Node* temp_4 = temp_2->next;
                temp_2->next->next = temp_1->next->next;
                temp_1->next->next = temp_3;
                temp_4->next = temp_1->next;
                temp_1->next = temp_4;}
            else{
                temp_2->next->next = temp_1->next->next;
                temp_1->next->next = temp_3;
                temp_3 = temp_1->next;
                temp_1->next = temp_2->next;
                temp_2->next = temp_3;
            }}
        else if (initial==0 && j==final-1 && temp_1 != NULL){
            Node* temp_3 = temp_2->next->next;
            if (final==1){
                temp_2->next->next = temp_1;
                head = temp_1->next;
                temp_1->next = temp_3;}
            else{
                temp_2->next->next = temp_1->next;
                temp_1->next = temp_3;
                head = temp_2->next;
                temp_2->next = temp_1;
            }
        }
        else
            cout << "ELEMENT NOT FOUND!!" << endl;
    }}

int main(){
    int choice, position, target;
    char cont = 'y';
    Node* head = nullptr;
    while(cont=='y'){
        cout << "MENU\n1. INSERTION\n2. DELETION\n3. SEARCH\n4. DISPLAY\n5. SUM\n6. SWAP\nEnter your choice: ";
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
                cout << "TARGET: "; cin >> target;
                search(head, target);
                break;
            case 4:
                display(head);
                break;
            case 5:
                sum(head);
                break;
            case 6:
                cout << "INITIAL POSITION: "; cin >> position;
                cout << "FINAL POSITION: "; cin >> target;
                if(position>target) swap(position, target);
                Swap(head, position, target);
                break;
            default:
                cout << "INVALID INPUT" << endl;
                cin.clear();
                cin.ignore();
        }
        cout << "CONTINUE? (y/n): "; cin >> cont;
    }
}