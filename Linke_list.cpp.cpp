#include<bits/stdc++.h>
using namespace std ;
class Node{
   public:
     int data ;
     Node* next ;
     // constructor 
    Node(int data){
        this -> data = data ;
        this -> next = NULL ;
     }
};

void insertAthead(Node* &head,int data ){
    Node* temp = new Node(data);
    temp -> next = head ;
    head = temp ;
}
void insertAtTail(Node*  &tail,int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next ;

}
void insertAtPosition(Node* &head , Node* &tail, int position , int data){
    Node* temp = head;
    int cnt = 1  ;
    if(position == 1){
        insertAthead(head,data);
        return;
    }
    if(temp -> next == NULL){
        insertAtTail(tail,data);
        return ;
    }
    while(cnt < position - 1){
        temp = temp -> next ;
        cnt++ ;
    }
    Node* NodetoInsert = new Node(data);
    NodetoInsert -> next = temp -> next ;
    temp -> next = NodetoInsert;
}

bool cyclic(Node* head){
    Node* temp = head; 
    map<Node*,bool>visited;
    while(temp != NULL){
        if(visited[temp] == true){
            cout << "element on which it present is : " << temp -> data << endl ;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next ;
    }
    return false;
}

Node* floydcycleDetect(Node* head){
    if(head == NULL){
        return NULL ;
    }
    Node* fast = head ;
    Node* slow = head ;
while(fast != NULL && slow != NULL){    
    fast = fast -> next ;
    if(fast != NULL){
        fast = fast -> next ;
    }
    slow = slow -> next ;

    if(slow == fast){
        cout << "element is : -  " << slow -> data << endl ;
        return slow ;
    }
}
    return NULL ;
}

Node* startingNode(Node* head){
    if(head == NULL){
        return NULL ;
    }
    Node* slow = head ;
    Node* intersection = floydcycleDetect(head);
    while (slow != intersection)
    {
       slow = slow -> next ;
       intersection = intersection -> next ;
    }
    return slow ;  
}

void removeloop(Node* head){
    if(head == NULL){
        return ;
    }
    Node* forstart = startingNode(head);
    Node* temp = forstart ;
    while(temp -> next != forstart){
        temp = temp -> next ;
    }
    temp -> next = NULL ;
    cout << "previous node is " << temp -> data << endl ;
}

void print(Node* &head){
    Node* temp = head ;
    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next ;
    }
    cout << endl ;
}
int main(){
    Node* Node1 = new Node(10);
    // cout << Node1 -> data << endl ;
    // cout << Node1 -> next << endl ;
    Node* head = Node1;
    insertAthead(head,12);
    // print(head);
    // cout << endl ;
    Node* tail = Node1;
    insertAtTail(tail,15);
    // print(head);
    insertAtTail(tail,22);
    // insertAtPosition(tail,head,2,29);
    Node* temp = head;
    tail -> next = head -> next ;
    cout << "head : " << head -> data << endl ;
    cout << "tail : " << tail -> data << endl ;
    // print(head);
    // cout << "head" << head -> data << endl ;
    // cout << "tail" << tail -> data << endl ;
//   if(cyclic(head)){
//     cout << "cycle is present " << endl ;
//   }else{
//     cout << "cycle is not present " << endl ;
//   }
 
Node* round = startingNode(head);
cout << "starting element is : - " << round -> data << endl ;


if(floydcycleDetect(head) == NULL){
    cout << "cycle is not present " << endl ;
}else{
    cout << "cycle is present " << endl ;
}
removeloop(head);
print(head);


    return 0 ;
}