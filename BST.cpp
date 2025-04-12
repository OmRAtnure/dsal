#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

class tree{
    public:
    Node* root=new Node();

    Node* createRoot(){
        cout<<"Enter root node data: ";
        cin>>root->data;
        root->left=NULL;
        root->right=NULL;
        return root;
    }

    void insert(Node* root,int tempData){
        Node* t=new Node();
        t->data=tempData;
        if(root->data>t->data){
            if(root->left==NULL){
                root->left=t;
            }else{
                insert(root->left,tempData);
            }
        }else{
            if(root->right==NULL){
                root->right=t;
            }else{
                insert(root->right,tempData);
            }
        }
    }

    void display(Node* root){
        if(root==NULL){
            return;
        }
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }

    int min=-1;
    int findMin(Node* root){
        if(root==NULL){
            return min;
        }
        min=root->data;
        return findMin(root->left);
    }

    void search(Node* root,int t){
        if(root==NULL){
            cout<<"Element not found"<<endl;
            return;
        }
        if(root->data==t){
            cout<<"Element found"<<endl;
            return;
        }
        else if(root->data>t){
            search(root->left,t);
        }else if(root->data<t){
            search(root->right,t);
        }
    }
};

int main(){
    tree obj;
    Node* root=obj.createRoot();
    int ch;
    do{
        cout<<"1.Insert"<<endl<<"2.Display"<<endl<<"3.Smallest"<<endl<<"4.search"<<endl<<"5.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        if(ch==1){
            int tempData;
            cout<<"Enter data to be inserted: ";
            cin>>tempData;
            obj.insert(root,tempData);
        }
        else if(ch==2){
            obj.display(root);
            cout<<endl;
        }
        else if(ch==3){
            cout<<"Smallest element: "<<obj.findMin(root)<<endl;
        }
        else if(ch==4){
            int t;
            cout<<"Enter the data to be searched: ";
            cin>>t;
            obj.search(root,t);
        }
        else if(ch==5){
            cout<<"Thanks for using the program!"<<endl;
        }
        else{
            cout<<"please enter valid choice"<<endl;
        }
    }while(ch!=5);

    return 0;
}