#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student {
    string name;
    int rollno;
    char div;
    string add;

public:
    void setData() {
        cout << "Enter name of student: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter rollno of student: ";
        cin >> rollno;
        cout << "Enter division of student: ";
        cin >> div;
        cout << "Enter address of student: ";
        cin.ignore(); 
        getline(cin, add);
    }

    void getData() {
        cout << "Name of student: " << name << endl;
        cout << "Rollno of student: " << rollno << endl;
        cout << "Division of student: " << div << endl;
        cout << "Address of student: " << add << endl;
    }

    int getRollno() {
        return rollno;
    }
};

void writeF() {
    ofstream fout;
    Student s1;
    fout.open("student.dat", ios::binary | ios::app);
    s1.setData();
    fout.write((char*)&s1, sizeof(s1));
    fout.close();
}

void readF(){
    bool fileEmpty=true;
    ifstream fin;
    Student s1;
    fin.open("student.dat",ios::in);
    while(fin.read((char*)&s1,sizeof(s1))){
        fileEmpty=false;
        s1.getData();
    }
    if(fileEmpty){
        cout<<"Record not found"<<endl;
    }
    fin.close();
}

void search() {
    ifstream fin;
    Student s1;
    int roll;
    bool found = false;
    cout << "Enter rollno for search: ";
    cin >> roll;
    fin.open("student.dat", ios::in | ios::binary);
    while (fin.read((char*)&s1, sizeof(s1))) {
        if (s1.getRollno() == roll) {
            cout << "Record found:" << endl;
            s1.getData();
            found = true;
            break;
        }
    }
    fin.close();

    if (!found) {
        cout << "Record not found" << endl;
    }
}

void deleteRecord() {
    fstream file;
    Student s1;
    int roll;
    bool found = false;
    cout << "Enter rollno to delete: ";
    cin >> roll;

    file.open("student.dat", ios::in | ios::out | ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    if (file.is_open() && tempFile.is_open()) {
        while (file.read((char*)&s1, sizeof(s1))) {
            if (s1.getRollno() != roll) {
                tempFile.write((char*)&s1, sizeof(s1));  
            } else {
                found = true;  
            }
        }

        file.close();
        tempFile.close();

        if (found) {
            remove("student.dat");
            rename("temp.dat", "student.dat");
            cout << "Record deleted successfully." << endl;
        } else {
            remove("temp.dat");
            cout << "Record not found to delete." << endl;
        }
    } else {
        cout << "Error opening file." << endl;
    }
}

int main() {
    int ch;
    do {
        cout << "1. Create" << endl
             << "2. Display" << endl
             << "3. Search" << endl
             << "4. Delete" << endl
             << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            writeF();
            break;
        case 2:
            readF();
            break;
        case 3:
            search();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            cout << "Thanks for using the program" << endl;
            break;
        default:
            cout << "Please enter a valid choice" << endl;
        }
    } while (ch != 5);

    return 0;
}