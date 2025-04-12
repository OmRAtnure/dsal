#include<iostream>
#include<vector>
using namespace std;

void linearProbing(pair<int,string> userno,vector <pair<int,string>> &directory){
    bool placed=false;
    int i=0;
    int index;
    while(!placed){
        if(i>=10){
            cout<<"Table full"<<endl;
            placed=true;
        }
        if(i==10)
            cout<<"Table full";
            index= ((userno.first+i)%10) ;
        if(directory[index].first==-1){
            placed=true;
        }
        else{
            i++;
        }
    }
    directory[index].first=userno.first;
    directory[index].second=userno.second;
}

void quadraticProbing(pair<int,string> userno,vector <pair<int,string>> &directory){
    bool placed=false;
    int i=0;
    int index;
    while(!placed){
        if(i>=10){
            cout<<"Table full"<<endl;
            placed=true;
        }
        index= ((userno.first+i*i)%10) ;
        if(directory[index].first==-1){
            placed=true;
        }
        else{
            i++;
        }
    }
    directory[index].first=userno.first;
    directory[index].second=userno.second;
}

void display(vector <pair<int,string>> directory){
    for(int i=0;i<10;i++){
        cout<<i<<") "<<directory[i].second<<":"<<directory[i].first<<endl;
    }
    cout<<endl;
}


int main(){
    pair<int,string> userno;
    vector <pair<int,string>> directory(10,{-1,"null"});
    while(true){
        int choice;
        cout<<"1.insert using linear probing"<<endl;
        cout<<"2.insert using quadratic probing"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter name: ";
            cin>>userno.second; 
            cout<<"Enter number: ";
            cin>>userno.first;
            linearProbing(userno,directory);
            break;
        case 2:
            cout<<"Enter name: ";
            cin>>userno.second; 
            cout<<"Enter number: ";
            cin>>userno.first;
            quadraticProbing(userno,directory);
        case 3:
            display(directory);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}
