/*
ID : 22011105
Name : Farhan Darwisy Bin Mohd Fauzi
*/


#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string email;
    string contact;
};

int main() 
{
    Student student[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter ID for student " << (i + 1) << ": ";
        cin >> student[i].id;
        cin.ignore();

        cout << "Enter Name for student " << (i + 1) << ": ";
        getline (cin, student[i].name);
        
        cout << "Enter Email for student " << (i + 1) << ": ";
        getline (cin, student[i].email);
        
        cout << "Enter Contact for student " << (i + 1) << ": ";
        getline (cin, student[i].contact);
        
        cout << endl;
        
    }
    
    cout << "\n---Student List---\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << (i + 1) << ":\n";
        cout << "ID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Email: " << student[i].email << endl;
        cout << "Contact: " << student[i].contact << endl << endl;
    }
    return 0;
}
