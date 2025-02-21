#include <iostream>
#include <fstream>
using namespace std;

class student
{
    int roll;
    string name;
    char div;
    string address;

public:
    void getdata()
    {
        cout << "Enter name:";
        cin.ignore();
        getline(cin, name);
        cout << "Enter roll no:";
        cin >> roll;
        cout << "Enter division:";
        cin >> div;
        cout << "Enter address:";
        cin.ignore();
        getline(cin, address);
    }
    void display()
    {
        cout << "Name:" << name << endl;
        cout << "Roll No:" << roll << endl;
        cout << "Division:" << div << endl;
        cout << "Address:" << address << endl;
    }

    bool check(int key)
    {
        if (key == roll)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream &operator<<(ostream &o, student &obj);
    friend istream &operator>>(istream &i, student &obj);
};

ostream &operator<<(ostream &o, student &obj)
{
    o << obj.name << " " << obj.roll << " " << obj.div << " " << obj.address << endl;
    return o;
}

istream &operator>>(istream &i, student &obj)
{
    i >> obj.name >> obj.roll >> obj.div >> obj.address;

    return i;
}

void creatFile()
{
    ofstream out;
    out.open("student.txt", ios::app);
    int choice = 1;
    while (choice)
    {
        student v;
        v.getdata();
        out << " " << v;
        // out.write((char*)&v,sizeof(v));
        cout << "Enter more student?(1 for yes)";
        cin >> choice;
    }
    out.close();
}

void readfile()
{
    student v;
    ifstream in;
    in.open("student.txt");
    while (in)
    {
        in >> v;

        v.display();
        cout << endl;
    }
    in.close();
}

void search()
{
    student v;
    int key;
    cout << "enter roll no to search: ";
    cin >> key;
    ifstream in;
    in.open("student.dat");
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

int main()
{
    creatFile();
    readfile();
    // search();

    return 0;
}

