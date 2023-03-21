#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node*right;

    Node(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class BT{
    public:
    Node* root;
    BT()
    {
    root=nullptr;
    }
    
    void addNode(int data)
    {
        Node* newNode= new Node(data);
        if(root==nullptr){
            root= newNode;
        }
        else{
        Node* focus;
        Node* Parent;
        focus= root;
        while(true){
            Parent=focus;
            if(data<focus->data)
            {
                focus= focus->left;
                if(focus==nullptr)
                {

                    Parent->left=newNode;
                    return;

                }
            }
            else{
                focus=focus->right;
                if(focus==nullptr)
                {
                    Parent->right=newNode;
                    return;
                }
            }
        }
        }
    }
    void PreOrder(Node* focus)
    {
        if(focus!=nullptr)
        {
            cout<<focus->data<<" ";
            PreOrder(focus->left);
            PreOrder(focus->right);
        }
    }
    void inOrder(Node* focus)
    {
        if(focus!=nullptr)
        {
            inOrder(focus->left);
            cout<<focus->data<<" ";
            inOrder(focus->right);
        }
    }
    void PostOrder(Node* focus)
    {
        if(focus!=nullptr)
        {
            PostOrder(focus->left);
            PostOrder(focus->right);
            cout<<focus->data<<" ";
        }
    }
    void LevelOrder(Node* focus)
    {
        if(focus!=nullptr)
        {
            queue<Node*> q;
            q.push(focus);
            while(q.empty()==false)
            {
                Node* node= q.front();
                cout<< node->data<<endl;
                q.pop();
                if(node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    q.push(node->right);
                }
            }
        }
    }
    
};
 int main()
 {
    BT tree;
    tree.addNode(50);
    tree.addNode(25);
    tree.addNode(75);
    tree.addNode(12);
    tree.addNode(37);
    tree.addNode(43);
    tree.addNode(30);
    cout<<"Pre Order Traversal"<<endl;
    tree.PreOrder(tree.root);
    cout<<"InOrder Traversal"<<endl;
    tree.inOrder(tree.root);
    cout<<"Post Order Traversal"<<endl;
    tree.PostOrder(tree.root);
    cout<<"Level Order Traversal"<<endl;
    tree.LevelOrder(tree.root);

 }

