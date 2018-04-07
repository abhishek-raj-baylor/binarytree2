#include<iostream>
using namespace std;
int count=0;
class node
{
public:
    node *parent;
    node *leftc;
    node *rightc;
    int data;
    node()
    {
        parent=leftc=rightc=NULL;
    }
};
class btree{
public:
    node *root=NULL;
/*btree()
    {
        root->parent=root->leftc=root->rightc=NULL;
        }*/
void insert(int val)
    {
        node *temp=new node;
        temp->data=val;
        //temp->parent=temp->leftc=temp->rightc=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else{
            node *curr=new node;
            curr=root;
            while(true)
            {
                if(val<curr->data){
                    if(curr->leftc==NULL){
                    curr->leftc=temp;
                        temp->parent=curr;
                        break;
                    }
                    else
                        curr=curr->leftc;
                }
                else{
                    if(curr->rightc==NULL){
                        curr->rightc=temp;
                        temp->parent=curr;
                        break;
                        }
                    else
                        curr=curr->rightc;
                }
        }
    }
    }
    int search(node *temp,int n)
    {
        int v=0;
        if(temp==NULL)
            return (0);
        search(temp->leftc,n);
        if(n==temp->data){
            cout<<"found";
            v=1;
        }
        search(temp->rightc,n);
        return (v);
}

    void display(node *temp)
    {
        if(temp==NULL)
            return;
        display(temp->leftc);
        cout<<temp->data;
            display(temp->rightc);
        
    }

    void del(int n)
    {
        node *temp=new node;
        temp=root;
        node *sp=new node;
        node *sl=new node;
        node *sr=new node;
        node *p=new node;
        int c=0;
        int f=0;
        while(c==0){
            if(temp->data==n)
                c=1;
            else if(temp->data<n)
                temp=temp->rightc;
            else if(temp->data>n)
                temp=temp->leftc;
                }
        if(c==1)
        {
            if(temp->leftc==NULL&&temp->rightc==NULL){
                sp=temp->parent;
                f=1;
                if(sp->leftc->data==n){
                    sp->leftc=NULL;
                    delete temp;
                }
                if(sp->rightc->data==n){
                    sp->rightc=NULL;
                    delete temp;            }
                else if(temp->leftc!=NULL&&temp->rightc!=NULL)
                {
                    sp=temp->parent;
                    sr=temp->rightc;
                    sl=temp->leftc;
                    p=temp->rightc;
                    while(p->leftc==NULL)
                    {
                        p=p->leftc;
                    }
                    if(sp->leftc->data==n)
                    {
                        sp->leftc=sr;
                        p->leftc=sl;
                    }
                    else{
                        sp->rightc=sr;
                        p->leftc=sl;
                    }
                    delete temp;
                }
            else if(temp->leftc==NULL&&temp->rightc!=NULL){
                sp=temp->parent;
                sr=temp->rightc;
                sp->rightc=sr;
                delete temp;
            }
                else if(temp->leftc!=NULL&&temp->rightc==NULL)
                {
                    sp=temp->parent;
                    sl=temp->leftc;
                    sp->leftc=sl;
                    delete temp;
                }
        }
        }
}
};
int main()
{
    btree obj;
    obj.insert(1);
    obj.insert(7);
    obj.insert(5);
    obj.insert(9);
    int i=obj.search(obj.root,0);
    obj.del(5);
    obj.display(obj.root);
    if(i==0)
        cout<<"not found";

    
}
