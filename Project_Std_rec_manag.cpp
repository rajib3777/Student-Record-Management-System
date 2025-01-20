#include<bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    string name;
    char section;
    string fathers_name;
    string mothers_name;
    float marks;
    char blood_group;
    long long contact_number;
    Student* next;
};

void addstudent(Student* &head,int id,string name,char section,string fathers_name,string mothers_name,float marks,char blood_group,long long contact_number)
{
    Student* newstudent = new Student{id,name,section,fathers_name,mothers_name,marks,blood_group,contact_number,nullptr};
    if(head == nullptr)
      head = newstudent;
    else
    {
        Student* temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newstudent;
    }
   cout << "Student Added Successfully !" << endl;    
}

void displaystudents(Student* head)
{
    if (!head)
    {
        cout << "No Student Record Found" << endl;
        return;
    }

    const int ID_WIDTH = 10;
    const int NAME_WIDTH = 20;
    const int SECTION_WIDTH = 10;
    const int FATHER_NAME_WIDTH = 20;
    const int MOTHER_NAME_WIDTH = 20;
    const int MARKS_WIDTH = 8;
    const int BLOOD_GROUP_WIDTH = 15;
    const int CONTACT_WIDTH = 15;


    cout << left 
         << setw(ID_WIDTH) << "ID" 
         << setw(NAME_WIDTH) << "Name" 
         << setw(SECTION_WIDTH) << "Section" 
         << setw(FATHER_NAME_WIDTH) << "Fathers Name" 
         << setw(MOTHER_NAME_WIDTH) << "Mothers Name" 
         << setw(MARKS_WIDTH) << "Marks" 
         << setw(BLOOD_GROUP_WIDTH) << "Blood Group" 
         << setw(CONTACT_WIDTH) << "Contact Number" 
         << endl;

    cout << string(120, '_') << endl; 


    while (head)
    {
        cout << left 
             << setw(ID_WIDTH) << head->id 
             << setw(NAME_WIDTH) << head->name 
             << setw(SECTION_WIDTH) << head->section 
             << setw(FATHER_NAME_WIDTH) << head->fathers_name 
             << setw(MOTHER_NAME_WIDTH) << head->mothers_name 
             << setw(MARKS_WIDTH) << head->marks 
             << setw(BLOOD_GROUP_WIDTH) << head->blood_group 
             << setw(CONTACT_WIDTH) << head->contact_number 
             << endl;

        head = head->next;
    }
}



void search_student(Student* head,int id)
{
    while(head)
    {
        if(head->id == id)
        {
            cout << "Student Found" << endl;

            cout << "ID :" << head->id 
            << "\nName :" << head->name 
            << "\nSection :" << head->section 
            << "\nFathers Name :" << head->fathers_name 
            << "\nMothers Name :" << head->mothers_name 
            << "\nMarks :" << head->marks 
            << "\nBlood Group :" << head->blood_group 
            << "\nContact NUmber :" << head->contact_number << endl;

            return;
        }
        head = head->next;
    }

    cout << "Student ID :" << id << "No Student Found" << endl;
}

void delete_Student_data(Student* &head,int id)
{
    if(!head)
    {
        cout << "No Student Records TO Delete" << endl;
        return;
    }

    if(head->id == id)
    {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Student Delete Successfully" << endl;
        return;
    }

    Student* temp2 = head;
    while(temp2->next && temp2->next->id != id)
    {
        temp2 = temp2->next;
    }

    if(temp2->next)
    {
        Student* temp = temp2->next;
        temp2->next = temp2->next->next;
        delete temp;
        cout << "Student Deleted Successfully !" << endl;
    }
    else
    {
        cout << "Student ID :" << id << "Not Found !" << endl;
    }
}

void save_file(Student* head)
{
    ofstream file("student.txt");

    while(head)
    {
        file << head->id << "," << head->name << "," << head->section << "," << head->fathers_name << "," << head->mothers_name << "," << head->marks << "," << head->blood_group << "," << head->contact_number << endl;
        head = head->next;
    }

    file.close();
    cout << "Data Save From File !" << endl;
}

void load_from_file(Student* &head)
{
    ifstream file("student.txt");
    if(!file)
       return;

    int id;
    string name;
    char section;
    string fathers_name;
    string mothers_name;
    float marks;
    char blood_group;
    long long contact_number;

    while(file >> id)
    {
        file.ignore(); 
        getline(file, name, ','); 
        file >> section;
        file.ignore(); 
        getline(file, fathers_name, ',');
        getline(file, mothers_name, ',');
        file >> marks; 
        file.ignore();
        file >> blood_group;
        file.ignore(); 
        file >> contact_number;

      addstudent(head,id,name,section,fathers_name,mothers_name,marks,blood_group,contact_number); 
    }

    file.close();
    cout << "Data Loaded From File" << endl;
}

void free_memory(Student* head) {
    while (head) {
        Student* temp = head;
        head = head->next;
        delete temp; 
    }
}


int main()
{
    Student* head = nullptr;

    int choice,id;
    string name;
    char section;
    string fathers_name;
    string mothers_name;
    float marks;
    char blood_group;
    long long contact_number;

    load_from_file(head);
    
    do
    {
        cout << "\n---Student Record Management---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Students" << endl;
        cout << "4. Delete Students" << endl;
        cout << "5. Save and Exit" << endl;
        cout << " Enter Your Choice :";
        cin >> choice;


        switch (choice)
        {
        case 1:
            cout << "Enter ID :" ;
            cin >> id;
            
            cin.ignore();
            cout << "Enter Name :";
            getline(cin,name);

            cout << "Enter Section :";
            cin >> section;
            cin.ignore();

            cout << "Enter Fathers Name :";
            getline(cin,fathers_name);

            cout << "Enter Mothers Name :";
            getline(cin,mothers_name);

            cout << "Enter Marks :";
            cin >> marks;
            cin.ignore();

            cout << "Enter Blood Group :";
            cin >> blood_group;
            cin.ignore();

            cout << "Enter Contact Number :";
            cin >> contact_number;

            addstudent(head,id,name,section,fathers_name,mothers_name,marks,blood_group,contact_number);
            break;

        case 2 :
            displaystudents(head);
            break;

        case 3 :
            cout << "Enter Your ID :" ;
            cin >> id;
            search_student(head,id);
            break;

        case 4 :
            cout << "Enter ID to Delete";
            cin >> id;
            delete_Student_data(head,id);
            break;

        case 5 :
            save_file(head);
            cout << "Exiting Program.Goodbye !" << endl;
            break;

        
        default:
            cout << "Invalid Please Try Again." << endl;
        }

        
    } while (choice != 5);

    free_memory(head);


    return 0;
}