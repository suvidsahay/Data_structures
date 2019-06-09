//link to this question: https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node * next;
};

void insertNode(node** head, int item){
    node* temp= new node();
    temp->val=item;
    temp->next=NULL;
    node * ptr=*head;
    if(*head==NULL)
        *head=temp;
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

int countNode(node* head){
    node* ptr=new node();
    ptr=head;
    int count=0;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
}
void display(node * head){
    node * ptr= new node();
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main() {
    int t,n,d;
    cin>>t;
    node * head= new node();
    while(t--){
        cin>>n;
        head = NULL;
        for(int i=0;i<n;i++){
            cin>>d;
            insertNode(&head,d);
        }
        cout<<countNode(head)<<endl;
    }
    return 0;
}
