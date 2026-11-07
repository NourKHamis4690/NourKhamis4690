#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int value){
    data = value ;
    next = NULL ;
    }
};
class LinkedList{
private:
    Node*head;
public:
    linkedlist(){
    head=NULL;}
 void insertAtPosition(int value , int pos){

 if (pos<1)
    return;
 Node*newNode = new Node(value);
 if(pos==1){
    newNode->next=head;
    head=newNode;
    return;}
    Node*temp=head;

for(int i= 1;i<pos-1&&temp!=NULL;i++){
  temp=temp->next;
}
if (temp==NULL){
delete newNode;
return;
 }
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteFirst(){
if (head==NULL)
    return;
    Node*temp=head;
    head=head->next;
    delete temp;
}
 void search(int value) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Not Found\n";
    }
void deleteLast() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
void update(int pos, int value) {
        if (pos < 1) return;

        Node* temp = head;

        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        temp->data = value;
    }
void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{  LinkedList list;

    list.insertAtPosition(10, 1);
    list.insertAtPosition(20, 2);
    list.insertAtPosition(30, 3);

    list.display();

    list.insertAtPosition(15, 2);
    list.display();

    list.deleteFirst();
    list.display();

    list.search(20);

    list.deleteLast();
    list.display();

    list.update(2, 50);
    list.display();



    return 0;
}
