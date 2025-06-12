#include<iostream>
using namespace std;

struct Node{
    Node* next;
    int val;
    Node(int x):val(x),next(NULL) {}
};


Node* createList(int n){
    Node* odd_head=NULL;
    Node* odd_tail=NULL;
    Node* even_head=NULL;
    Node* even_tail=NULL;

    for(int i=0;i<n;i++){
        int m;
        cin>>m;

        if((i%2)==0 && m%2==1){
            if(odd_head==NULL){
                Node* newNode=new Node(m);
                odd_head=newNode;
                odd_tail=newNode;
            }
            else{
                Node* newNode=new Node(m);
                odd_tail->next=newNode;
                odd_tail=newNode;
            }
        }
        else if((i%2)==1 && m%2==0){
            if(even_head==NULL){
                Node* newNode=new Node(m);
                even_head=newNode;
                even_tail=newNode;
            }
            else{
                Node* newNode=new Node(m);
                even_tail->next=newNode;
                even_tail=newNode;
            }
        }
    }

    even_tail->next=odd_head;
    return even_head;
}

void printList(Node* head){
    Node* cur=head;
    while(cur!=NULL){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;

    Node* head=createList(n);
    printList(head);

    return 0;
}