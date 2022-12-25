#include <iostream>

using namespace std;


struct student{
    string secondName;
    string firstName;
    string middleName;
    int yearOfBirth;
    int course;
    string group;
};

void createArray(student*& s, int l);
void printArray(student*& s, int l);
void sortArrayByYear(student*& s, int l);
void sortArrayByGroup(student*& s, int l);
void sortArrayBySName(student*& s, int l);
void deleteArray(student*& s, int l);

int main()
{
    student* students = nullptr;
    int length;
    cout << "Enter length of array:\n";
    cin >> length;
    createArray(students, length);
    printArray(students, length);

    sortArrayByGroup(students, length);
    cout << "Sort By group\n\n";
    printArray(students, length);
    sortArrayBySName(students, length);
    cout << "Sort By second name\n\n";
    printArray(students, length);
    sortArrayByYear(students, length);
    cout << "Sort By year of birth\n\n";
    printArray(students, length);

    deleteArray(students, length);
    return 0;
}

void createArray(student*& s, int l){
    s = new student[l];
    for(int i = 0; i < l; i++){
        cout << "Enter first name:\n";
        cin >> s[i].firstName;
        cout << "Enter second name:\n";
        cin >> s[i].secondName;
        cout << "Enter middle name:\n";
        cin >> s[i].middleName;
        cout << "Enter year of birth:\n";
        cin >> s[i].yearOfBirth;
        cout << "Enter course:\n";
        cin >> s[i].course;
        cout << "Enter group:\n";
        cin >> s[i].group;
    }
}

void printArray(student*& s, int l){
//        cout << "First name\n";
//        cout << "Second name\n";
//        cout << "Middle name\n";
//        cout << "Year of birth\n";
//        cout << "Course\n";
//        cout << "Group\n";

    for(int i = 0; i < l; i++){
        cout << i << ")";
        cout << s[i].firstName << endl;
        cout << s[i].secondName << endl;
        cout << s[i].middleName << endl;
        cout << s[i].yearOfBirth << endl;
        cout << s[i].course << endl;
        cout << s[i].group << endl << endl;
    }
}
void sortArrayByYear(student*& s, int l){
    for(int i = l; i > 0; i--){
        for(int j = 1; j < i; j++){
            if(s[j-1].yearOfBirth > s[j].yearOfBirth){
                student temp = s[j-1];
                s[j-1] = s[j];
                s[j] = temp;
            }
        }
    }
}
void sortArrayByGroup(student*& s, int l){
    for(int i = l; i > 0; i--){
        for(int j = 1; j < i; j++){
            if(s[j-1].group > s[j].group){
                student temp = s[j-1];
                s[j-1] = s[j];
                s[j] = temp;
            }
        }
    }
}
void sortArrayBySName(student*& s, int l){
    for(int i = l; i > 0; i--){
        for(int j = 1; j < i; j++){
            if(s[j-1].secondName > s[j].secondName){
                student temp = s[j-1];
                s[j-1] = s[j];
                s[j] = temp;
            }
        }
    }
}

void deleteArray(student*& s, int l){
    delete []s;
    s = nullptr;
}
