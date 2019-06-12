////link to this question: https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("");
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
struct node* makeUnion(struct node* head1, struct node* head2);
int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(makeUnion(a, b));
    }
    return 0;
}


struct node* makeUnion(struct node* head1, struct node* head2)
{
    node *head=NULL,*ptr;
    set<int> s;
    set<int>::reverse_iterator itr;
    set<int>::iterator itr1;
    ptr=head1;
    while(ptr!=NULL){
        s.insert(ptr->data);
        ptr=ptr->next;
    }
    ptr=head2;
    while(ptr!=NULL){
        s.insert(ptr->data);
        ptr=ptr->next;
    }
    for(itr=s.rbegin();itr!=s.rend();itr++){
        push(&head,*itr);
    }
    return head;
}
