#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  // Constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};


int sizeOfLL(Node* &head, Node* &tail){
  int n = 0;
  Node* temp = head;
  if(head == NULL && tail == NULL ){
    return 0;
  }
  while(temp != NULL){
    temp = temp->next;
    n++;
  }
  return n;
}

void insertAtHead(int value, Node* &head, Node* &tail){
  // If LL is empty
  if(head == NULL && tail == NULL){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
  }
  else{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }
}

void insertAtTail(int value, Node* &head, Node* &tail){
  // If LL is empty
  if(head == NULL && tail == NULL){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
  }
  else{
    Node* newNode = new Node(value);
    tail->next = newNode;
    tail = newNode;
  }
 
}

void insertAtPosition(int value, Node* &head, Node* &tail, int pos){
   
    if(head == NULL && tail == NULL){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
  }
  Node* temp = head;
  int count = 1;
  int size = sizeOfLL(head,tail);
  
  if(pos == 1 ){
    insertAtHead(value,head,tail);
  }

  if(pos == size){
    insertAtTail(value,head,tail);
  }

  while(count != pos-1){
    temp = temp->next;
    count++;
  }

  Node* newNode = new Node(value);
  newNode->next = temp->next;
  temp->next = newNode;

}


void print(Node* &head){
  Node* i = head;
  while(i != NULL){
    cout << i->data << "->";
    i = i->next;
  } cout <<"NULL"<<endl;
}


int main() {
  Node* head = NULL;
  Node* tail = NULL;

  // insertAtHead(10, head, tail);
  //   print(head);
  // insertAtHead(20, head, tail);
  //   print(head);
  // insertAtHead(30, head, tail);
  //   print(head);

  insertAtTail(11,head,tail);
  insertAtTail(22,head,tail);
  insertAtTail(31,head,tail);
  insertAtTail(13,head,tail);
  insertAtTail(32,head,tail);
  insertAtTail(232,head,tail);
  print(head);
  cout <<"Size: "<< sizeOfLL(head,tail)<<endl;
  insertAtPosition(420,head,tail,3);
  print(head);
  insertAtPosition(230,head,tail,4);
  print(head);
  cout <<"Size: "<< sizeOfLL(head,tail)<<endl;
  insertAtPosition(730,head,tail,9);
  insertAtPosition(6,head,tail,1);
  print(head);
  cout << "Size: "<< sizeOfLL(head,tail)<<endl;

  return 0;
}
