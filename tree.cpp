#include<iostream>
using namespace std;


struct node{
    string name;
    int count;
    struct node* child[10];
}*root;

class book{
    public:
    book(){
        root=NULL;
    }
    void creat_tree(){
        root=new node;
        cout<<"Enter name of Book: ";
        cin>>root->name;
        cout<<"Enter number of chapter:";
        cin>>root->count;
        for(int i=0;i<root->count;i++){
            root->child[i]=new node;
            cout<<"Enter name of chapter: ";
            cin>>root->child[i]->name;
            cout<<"Enter number of section:";
            cin>>root->child[i]->count;
            for(int j=0;j<root->child[i]->count;j++){
                root->child[i]->child[j]=new node;
                cout<<"Enter name of section: ";
                cin>>root->child[i]->child[j]->name;
                cout<<"Enter number of sub-section:";
                cin>>root->child[i]->child[j]->count;
            }
        }
    }

    void display(){
        cout<<root->name<<endl;
        for(int i=0;i<root->count;i++){
            cout<<"    "<<root->child[i]->name<<endl;
            for(int j=0;j<root->child[i]->count;j++){
                cout<<"        "<<root->child[i]->child[j]->name<<endl;
            }
        }
    }
};




int main(){
    book b1;
    b1.creat_tree();
    b1.display();
    return 0;
}