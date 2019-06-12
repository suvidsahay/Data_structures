//link to this question: https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1
#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node*next,*prev;
};
struct node* update(struct node*start,int p);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        struct node*start=NULL,*cur=NULL,*ptr=NULL;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new(struct node);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        struct node*str=update(start,p);
        while(str!=NULL)
        {
            cout<<str->data<<" ";
            str=str->next;
        }
        cout<<endl;  
    }
}

struct node*update(struct node*start,int p)
{
    if(p==0){
        return start;
    }
    else{
        node* ptr=start,*temp;
        start=start->next;
        start->prev=NULL;
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        ptr->prev=temp;
        start=update(start,p-1);
        return start;
    }
}