#include <iostream>
#include <vector>
using namespace std;

class Student
{
protected:
    float marks;

public:
    void setMarks(float m)
    {
        marks = m;
    }

    virtual string computeGrade() = 0;

    virtual void display()
    {
        cout << "Marks: " << marks << ", Grade: " << computeGrade() << endl;
    }

    virtual ~Student() {}
};

class Undergraduate : public Student
{
public:
    string computeGrade() override
    {
        if (marks >= 85) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 50) return "C";
        else return "F";
    }
};

class Postgraduate : public Student
{
public:
    string computeGrade() override
    {
        if (marks >= 85) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 60) return "C";
        else return "F";
    }
};

int main()
{
    vector<Student*> students;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
        {
        int type;
        float m;
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Enter type (1 - Undergraduate, 2 - Postgraduate): ";
        cin >> type;
        cout << "Enter marks: ";
        cin >> m;

        Student* s = nullptr;
        if (type == 1)
        {
            s = new Undergraduate();
        }
        else if (type == 2)
        {
            s = new Postgraduate();
        }
        else
        {
            cout << "Invalid type! Skipping this student.\n";
            continue;
        }

        s->setMarks(m);
        students.push_back(s);
    }

    cout << "\nStudent Grades:\n";
    for (size_t i = 0; i < students.size(); ++i)
    {
        cout << "Student " << i + 1 << ": ";
        students[i]->display();
    }

    for (Student* s : students)
    {
        delete s;
    }

    cout<<" "<<endl;
    cout<<"24CE103_Manthan Rangpariya"<<endl;

    return 0;
}
