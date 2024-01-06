#include <iostream>
using namespace std;

class course
{
    string course_name;
    int fees;

public:
    void setCourse(string course_name)
    {
        this->course_name = course_name;
    }

    void setFees(int fees)
    {
        this->fees = fees;
    }
};

class student : public course
{
    string name;
    int roll;
    int mobile;

public:
    static int count;

    int getRoll()
    {
        return this->roll;
    }

    int add_student()
    {

        count++;
        this->roll = count;

        cout << "Enter Your Name : " << endl;
        cin >> this->name;

        cout << "Enter Your Mobile : " << endl;
        cin >> this->mobile;

        return roll;
    }
};

int student ::count = 0;

int main()
{

    student student_array[500];

    int choice;
    int i = 0;

    do
    {
        cout << endl;
        cout << endl;
        cout << " 1: Add Student. \n 2: Take Course \n 3: Display Student with Course . \n 4: Display Students .\n 5: Exit ." << endl;
        cout << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            int temp;
            temp = student_array[i].add_student();
            cout << "Your Roll No is : " << temp << endl;
            i++;
            break;

        case 2:

            int temp_roll;

            cout << "Enter Your Roll No. : " << endl;
            cin >> temp_roll;

            if (temp_roll <= 500)
            {
                int temp_course;
                cout << " Press 1 : DAC [Fees -1000] \n Press 2 : DBDA [Fees-5000]" << endl;

                cin >> temp_course;
                if (temp_course == 1)
                {
                    student_array[temp_roll - 1].setCourse("DAC");
                    student_array[temp_roll - 1].setFees(10000);
                    cout << "Course Registered ! " << endl;

                    break;
                }
                else if (temp_course == 2)
                {
                    student_array[temp_roll - 1].setCourse("DBDA");
                    student_array[temp_roll - 1].setFees(5000);
                    cout << "Course Registered ! " << endl;
                }
            }
            else
            {
                cout << "Enter a valid Roll No ! " << endl;
                break;
            }

        default:
            cout << "Enter a valid choice !" << endl;
        }

    } while (choice != 5);
}
