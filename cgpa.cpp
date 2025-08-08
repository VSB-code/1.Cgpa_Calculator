//cgpa calculator
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Subject {
    public:
    string name;
    int gradepoints;
    int credits;
    Subject(string n,int gp,int c){
        name=n;
        gradepoints=gp;
        credits=c;
    }
};

class Student{
    public:
    string name;
    vector<Subject>subjects;
    //constructor
    Student(string n){
        name=n;
    }
    void addSubject(string subjectName, int gradePoints, int creditHours) {
        Subject newSubject(subjectName, gradePoints, creditHours);
        subjects.push_back(newSubject);
    }
    double CalculateCGPA() {
        double totalgradepoints=0;
        int cradit=0;
        for(auto &subject: subjects) {
            cradit+=subject.credits;
            totalgradepoints+=subject.gradepoints*subject.credits;
        }
        return (cradit==0)?0: totalgradepoints/cradit;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "CGPA: ";   
        cout << CalculateCGPA() << endl;
    }    
};

int main(){
    string studentname;
    int subjectnum;
    cout << "Enter your name: ";
    getline(cin,studentname);
    cout<<"Enter number of subjects: ";
    cin>>subjectnum;
    cin.ignore(); // to ignore the newline character left in the buffer
    Student student(studentname);
    for(int i=0;i<subjectnum;i++){
    string name;
    int gradepoints;
    int credit;
    cout<<"Enter subject name: ";
    getline(cin, studentname);
    cout<<"enter grade points: ";
    cin>>gradepoints;
    cout<<"enter credit: ";
    cin>>credit;
    student.addSubject(studentname, gradepoints, credit);
    cin.ignore(); // to ignore the newline character left in the buffer
    }
  student.display();
  return 0;
}
