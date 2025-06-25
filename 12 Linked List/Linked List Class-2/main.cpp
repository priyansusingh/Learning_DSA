#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }

};

int getLength(Node* &head){
   int len = 0;
   Node* temp = head;
   while(temp != NULL){
    len++;
    temp = temp->next;
   }
   return len;
}

void insertAtHead(int value, Node* &head, Node* &tail){
    
    if( head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        return;
    }
    else{
      Node* newNode = new Node(value);
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data <<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;

}

void insertAtTail(int value,Node* &head, Node* &tail){
    if( head == NULL && tail == NULL ){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        return;
    }
   else{
    Node* newNode = new Node(value);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
   }
}

void insertAtPosition(int value, Node* &head, Node* &tail, int position){
    int len = getLength(head);
    if(position < 1 || position > len + 1){
        cout << "Invalid position!" << endl;
        return;
    }
    if( position == 1){
        insertAtHead(value,head,tail);
    }
    else if(position == len+1){
        insertAtTail(value,head,tail);
    
    }
else{
    Node* temp = head;
    for(int i=0; i<position-2; i++){
       temp = temp->next;
    }
  
    Node* newNode = new Node(value);
    Node* forward = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    forward->prev = newNode;
    newNode->next = forward;
}
}

void printReverse(Node* tail){
    Node* temp = tail;
    while(temp != NULL){
      cout << temp->data <<"->";
      temp = temp->prev;
    }cout<<"NULL"<<endl;
}

int main(){
   Node* head = NULL;
   Node* tail = NULL;

   insertAtHead(10,head,tail);
   print(head);
   insertAtHead(20,head,tail);
   print(head);
   insertAtHead(30,head,tail);
   print(head);
   insertAtHead(40,head,tail);
   print(head);
   insertAtHead(50,head,tail);
   print(head);
   printReverse(tail);
   insertAtTail(500,head,tail);
   print(head);
   insertAtPosition(300,head,tail,7);
   print(head);
   cout << "Length: " << getLength(head) << endl;
//    printReverse(tail);
    return 0;
}