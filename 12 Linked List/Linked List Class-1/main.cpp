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



// to find number of nodes
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
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

void insertAtPosition( int value, Node* &head, Node* &tail,int position){
    //assume-> valid position inputs given
    int length = getLength(head);
    if(position == 1){
        //insert at head
        insertAtHead(value,head,tail);
    }
    else if(position == length + 1){
        //insert at tail
        insertAtTail(value,head,tail);
    }
    else{
        //insert in between
        Node* temp = head;
        for(int i=0; i<position-2;i++){
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void print(Node* &head){
  Node* i = head;
  while(i != NULL){
    cout << i->data << "->";
    i = i->next;
  } cout <<"NULL"<<endl;
}

bool isPresent(int value, Node* head){
    Node* temp = head;

    
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
  cout <<"Size: "<< getLength(head)<<endl;
  insertAtPosition(420,head,tail,3);
  print(head);
  insertAtPosition(230,head,tail,4);
  print(head);
  cout <<"Size: "<< getLength(head)<<endl;
  insertAtPosition(730,head,tail,9);
 
  print(head);
  cout << "Size: "<< getLength(head)<<endl;

  insertAtPosition(6,head,tail,1);
  print(head); 
  cout << "Size: "<< getLength(head) << endl;

  return 0;
}
