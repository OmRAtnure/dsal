#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Employee
{
    int ID;
    string name;
    string designation;
    int salery;

public:
    void getdata()
    {
        cout << "Enter name:";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee ID: ";
        cin >> ID;
        cout << "Enter designation:";
        cin >> designation;
        cout << "Enter salery:";
        cin>>salery;
    }
    void display()
    {
        cout << "Name:" << name << endl;
        cout << "ID:" << ID << endl;
        cout << "Designation:" << designation << endl;
        cout << "Salery:" << salery << endl;
    }
    
    bool check(int key)
    {
        if (key == ID)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream &operator<<(ostream &o, Employee &obj);
    friend istream &operator>>(istream &i, Employee &obj);
};

ostream &operator<<(ostream &o, Employee &obj)
{
    o << obj.name << " " << obj.ID << " " << obj.designation << " " << obj.salery << endl;
    return o;
}

istream &operator>>(istream &i, Employee &obj)
{
    i >> obj.name >> obj.ID >> obj.designation >> obj.salery;

    return i;
}

void insert()
{
    ofstream out;
    out.open("Employee.txt", ios::app);
    int choice = 1;
    while (choice)
    {
        Employee v;
        v.getdata();
        out << " " << v;
        // out.write((char*)&v,sizeof(v));
        cout << "Enter more Employee?(1 for yes)";
        cin >> choice;
        cin.ignore();
    }
    out.close();
}

void display()
{
    Employee v;
    ifstream in;
    in.open("Employee.txt");
    while (in>>v)
    {
        v.display();
        cout << endl;
    }
    in.close();
}

void search()
{
    Employee v;
    int key;
    cout << "enter ID no to search: ";
    cin >> key;
    ifstream in;
    in.open("Employee.txt");
    while (in)
    {
        in >> v;
        if (v.check(key))
        {
            v.display();
            // break;
            return;
        }
    }
    cout << "not found";
}

void Delete(){
    ifstream in;
    ofstream out;
    Employee v;
    bool found;
    cout<<"Enter Key to be deleted";
    int key;
    cin>>key;

    out.open("temp.txt", ios::app);
    in.open("Employee.txt");

    while (in)
    {
        in >> v;
        if(v.check(key)){
            found=true;
            continue;
        }else{
            out<<v;
        }
        
        cout << endl;
    }
    in.close();
    out.close();

    if(found){
        remove("Employee.txt");
        rename("temp.txt","Employee.txt");
        cout<<"Record deleted successfully"<<endl;
    }else{
        remove("temp.txt");
        cout<<"Record not found";
    }
}

int main()
{
    while(true)
    {
        int choice;
        cout<<endl;
        cout<< "1.Insert"<<endl;
        cout << "2.search" << endl;
        cout << "3.Delete" << endl;
        cout << "4.Display" << endl;
        cout << "5.Exit" << endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            Delete();
            break;
        case 4:
            display();
            break;
        
        case 5:
            return 0;
        default:
            break;
        }
    }
   
}
