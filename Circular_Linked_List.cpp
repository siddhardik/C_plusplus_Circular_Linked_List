#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

 void insertAtHead(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
    return;
 }

void insertAtTail(node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    
}

void display(node* head){
    if(head==NULL){
        cout<<"There is no element to display|"<<endl;
    }
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);

    cout<<"head"<<endl;
}

void deleteAtHead(node* &head){
    if(head==NULL){
        cout<<"There is no Element in linked list"<<endl;
        return;
    }
    node* temp=head;
    node* prev=head;
    int count=1;
    while(temp->next!=head){
        count++;
        temp=temp->next;
    }
    if(count==1){
        cout<<"1 No element has been deleted"<<endl;
        delete head;
        head=NULL;
        return;
    }
    
    temp->next=head->next;
    delete head;
    head=temp->next;
    

}

void deletion(node* &head,int pos){
    if(head==NULL){
        cout<<"There is no Element in your Linked List|"<<endl;
        return;
    }

    if(pos==1){
        deleteAtHead(head);
        return;
    }
    int count=1;
    node* temp=head;
    node* prev;
    while(temp->next!=NULL && count!=pos){
        prev=temp;
        count++;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    // insertAtHead(head,5);
    display(head);
    //deleteAtHead(head);
    deletion(head,2);
    display(head);

    return 0;
}

