#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person() // Default Constructor
    {
        name = " ";
        age = 0;
        ID = " ";
        contact = " ";
    }
    Person(string name, int age, string ID, string contact) // Parameterised Constructor
    {
        this->name = name;
        this->age = age;
        this->ID = ID;
        this->contact = contact;
    }
    Person(Person const &copy) // Copy constructor
    {
        name = copy.name;
        age = copy.age;
        ID = copy.ID;
        contact = copy.contact;
    }
    ~Person() // Destructer called
    {
        cout << "object destroyed" << endl;
    }
    // getter methods
    string get_person_name()
    {
        return name;
    }
    int get_person_age()
    {
        return age;
    }
    string get_person_id()
    {
        return ID;
    }
    string get_person_contact()
    {
        return contact;
    }
    // setter methods
    void set_person_name(string name)
    {
        if (name.empty())
            throw invalid_argument("Name cannot be empty.");
        this->name = name;
        cout << "Name set successfully" << endl;
    };
    void set_person_age(int age)
    {
        if (age > 0 && age <= 130)
        {
            this->age = age;
            cout << "Age Set Successfully" << endl;
        }
        else
        {
            throw invalid_argument("Invalid age! Age should be between 1 and 130.");
        }
    };
    void set_person_id(string ID)
    {
        this->ID = ID;
        cout << "Id Set successfully" << endl;
    }
    void set_person_contact(string contact)
    {
        this->contact = contact;
        cout << "Contact Set Successfully" << endl;
    }
    virtual void displayDetail()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl;
        cout << "Contact: " << contact << endl;
    }
    virtual double calculatePayment()
    {
        cout << "Payment calculation not defined for generic Person.\n";
        return 0.0;
    }
};
class student : public Person
{
private:
    string enrollment_date;
    string program;
    float gpa;

public:
    student() // Default Constructor
    {
        enrollment_date = " ";
        program = " ";
        gpa = 0.00;
    }
    student(string enrollment_date, string program, float gpa) // parameterised constructor
    {
        this->enrollment_date = enrollment_date;
        this->program = program;
        this->gpa = gpa;
    }
    student(student const &copy) // copy constructor
    {
        enrollment_date = copy.enrollment_date;
        program = copy.program;
        gpa = copy.gpa;
    }
    ~student() // Destructor called
    {
        cout << "object destroyed" << endl;
    }
    // getter methods
    string get_enrollment_date()
    {
        return enrollment_date;
    }
    string get_program()
    {
        return program;
    }
    float get_gpa()
    {
        return gpa;
    }
    // setter methods
    void set_enrollment_date(string enrollment_date)
    {
        this->enrollment_date = enrollment_date;
        cout << "Enrollment date set successfully" << endl;
    }
    void set_program(string program)
    {
        this->program = program;
        cout << "Program set successfully" << endl;
    }
    void set_gpa(float gpa)
    {
        if (gpa >= 0.0 && gpa <= 4.0)
        {
            this->gpa = gpa;
            cout << "gpa Set Successfully" << endl;
        }
        else
        {
            throw invalid_argument("Invalid gpa! gpa should be between 0.0 and 4.0.");
        }
    }
    void displayDetail() override
    {
        Person::displayDetail();
        cout << "Enrollment date: " << enrollment_date << endl;
        cout << "Program: " << program << endl;
        cout << "Gpa: " << gpa << endl;
    }
    double calculatePayment() override
    {
        double perSemesterFee = 159900.0; // Example value
        return perSemesterFee;
    }
};
class professor : public Person
{
private:
    string department;
    string specialisation;
    string hire_date;

public:
    professor() // default constructer
    {
        department = " ";
        specialisation = " ";
        hire_date = " ";
    }
    professor(string department, string specialisation, string hire_date) // parameterised constructer
    {
        this->department = department;
        this->specialisation = specialisation;
        this->hire_date = hire_date;
    }
    professor(professor const &copy) // copy constructor
    {
        department = copy.department;
        specialisation = copy.specialisation;
        hire_date = copy.hire_date;
    }
    ~professor() // destructer called
    {
        cout << "object destroyed" << endl;
    }
    // getter methods
    string get_department()
    {
        return department;
    }
    string get_specialisation()
    {
        return specialisation;
    }
    string get_hire_date()
    {
        return hire_date;
    }
    // setter methods
    void set_department(string department)
    {
        this->department = department;
        cout << "Department set successflly" << endl;
    }
    void set_specialisation(string specialisation)
    {
        this->specialisation = specialisation;
        cout << "Specialisation set successfully" << endl;
    }
    void set_hire_date(string hire_date)
    {
        this->hire_date = hire_date;
        cout << "hire date set successfully" << endl;
    }
    void displayDetail() override
    {
        Person::displayDetail();
        cout << "Department: " << department << endl;
        cout << "Specialization: " << specialisation << endl;
        cout << "Hire date: " << hire_date << endl;
    }
    double calculatePayment() override
    {
        double perSemestersalary = 100900.0;
        return perSemestersalary;
    }
};
class course
{
private:
    string code;
    string title;
    int credit;
    string description;

public:
    course() // default constructer
    {
        code = " ";
        title = " ";
        credit = 0;
        description = " ";
    }
    course(string code, string title, int credit, string description) // parameterised constructer
    {
        this->code = code;
        this->title = title;
        this->credit = credit;
        this->description = description;
    }
    course(course const &copy) // copy constructor
    {
        code = copy.code;
        title = copy.title;
        credit = copy.credit;
        description = copy.description;
    }
    ~course() // destructer called
    {
        cout << "Object destroyed" << endl;
    }
    // getter methods
    string get_code()
    {
        return code;
    }
    string get_title()
    {
        return title;
    }
    int get_credit()
    {
        return credit;
    }
    string get_description()
    {
        return description;
    }
    // setter methods
    void set_code(string code)
    {
        this->code = code;
        cout << "Code set successfully" << endl;
    }
    void set_title(string title)
    {
        this->title = title;
        cout << "Title set successfully" << endl;
    }
    void set_credit(int credit)
    {
        if (credit > 0)
        {
            this->credit = credit;
            cout << "Credit Set Successfully" << endl;
        }
        else
        {
            throw invalid_argument("Invalid credit! Credit should be positive.");
        }
    }
    void set_description(string description)
    {
        this->description = description;
        cout << "Description set succeessfullly" << endl;
    }
};
class department
{
private:
    string name;
    string location;
    float budget;

public:
    department() // default constructer
    {
        name = " ";
        location = " ";
        budget = 0;
    }
    department(string name, string location, float budget) // parameterised constructer
    {
        this->name = name;
        this->location = location;
        this->budget = budget;
    }
    department(department const &copy) // copy constructor
    {
        name = copy.name;
        location = copy.location;
        budget = copy.budget;
    }
    ~department() // destructer called
    {
        cout << "object destroyed" << endl;
    }
    // getter methods
    string get_name()
    {
        return name;
    }
    string get_location()
    {
        return location;
    }
    float get_budget()
    {
        return budget;
    }
    // setter methods
    void set_name(string name)
    {
        this->name = name;
        cout << "name set successfully" << endl;
    }
    void set_location(string location)
    {
        this->location = location;
        cout << "Location set sucessfully" << endl;
    }
    void set_budget(float budget)
    {
        this->budget = budget;
        cout << "Budget set sucessfully" << endl;
    }
};
// CLASS Gradebook
class GradeBook
{
private:
    map<string, float> studentGrades; // studentID -> grade

public:
    // Add or update a grade
    void setGrade(string studentID, float grade)
    {
        if (grade >= 0 && grade <= 100)
        {
            studentGrades[studentID] = grade;
        }
        else
        {
            cout << "Invalid grade. Must be between 0 and 100." << endl;
        }
    }

    // Calculate average grade
    float calculateAverageGrade() const
    {
        if (studentGrades.empty())
            return 0;

        float total = 0;
        for (auto &entry : studentGrades)
        {
            total += entry.second;
        }
        return total / studentGrades.size();
    }

    // Get highest grade
    float getHighestGrade() const
    {
        float highest = -1;
        for (auto &entry : studentGrades)
        {
            if (entry.second > highest)
                highest = entry.second;
        }
        return highest;
    }

    // Get list of students who failed (< 40)
    vector<string> getFailingStudents() const
    {
        vector<string> failing;
        for (auto &entry : studentGrades)
        {
            if (entry.second < 40)
                failing.push_back(entry.first);
        }
        return failing;
    }

    // Optional: Print all grades
    void printAllGrades() const
    {
        for (auto &entry : studentGrades)
        {
            cout << "Student ID: " << entry.first << ", Grade: " << entry.second << endl;
        }
    }
};
// CLASS Enrollment manager
class EnrollmentManager
{
private:
    // Map from course code to list of student IDs
    map<string, vector<string>> courseEnrollments;

public:
    // Enroll a student in a course
    void enrollStudent(const string &courseCode, const string &studentID)
    {
        vector<string> &students = courseEnrollments[courseCode];
        if (find(students.begin(), students.end(), studentID) == students.end())
        {
            students.push_back(studentID);
            cout << "Student " << studentID << " enrolled in course " << courseCode << " successfully." << endl;
        }
        else
        {
            cout << "Student " << studentID << " is already enrolled in course " << courseCode << "." << endl;
        }
    }

    // Drop a student from a course
    void dropStudent(const string &courseCode, const string &studentID)
    {
        auto it = courseEnrollments.find(courseCode);
        if (it != courseEnrollments.end())
        {
            vector<string> &students = it->second;
            auto pos = find(students.begin(), students.end(), studentID);
            if (pos != students.end())
            {
                students.erase(pos);
                cout << "Student " << studentID << " dropped from course " << courseCode << " successfully." << endl;
            }
            else
            {
                cout << "Student " << studentID << " is not enrolled in course " << courseCode << "." << endl;
            }
        }
        else
        {
            cout << "Course " << courseCode << " does not exist." << endl;
        }
    }

    // Get number of students enrolled in a course
    int getEnrollmentCount(const string &courseCode) const
    {
        auto it = courseEnrollments.find(courseCode);
        if (it != courseEnrollments.end())
        {
            return it->second.size();
        }
        else
        {
            return 0;
        }
    }

    // Optional: Display enrolled students for a course
    void printEnrolledStudents(const string &courseCode) const
    {
        auto it = courseEnrollments.find(courseCode);
        if (it != courseEnrollments.end())
        {
            cout << "Students enrolled in course " << courseCode << ": ";
            for (const string &studentID : it->second)
            {
                cout << studentID << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No students enrolled or course not found." << endl;
        }
    }
};
void testPerson(Person *person)
{
    person->displayDetail();
    cout << "Calculated Payment:" << person->calculatePayment() << "\n";
}
void testPerson(Person &person)
{
    person.displayDetail();
    cout << "Calculated Payment:" << person.calculatePayment() << "\n";
}

void testArrayOfPersons()
{
    const int size = 2;
    Person *people[size];

    // Create objects
    people[0] = new student("7/5/25", "B.tech", 7.77);
    people[1] = new professor("APS", "Maths", "2/3/25");

    // Demonstrate polymorphic behavior
    for (int i = 0; i < size; i++)
    {
        people[i]->displayDetail();
        cout << "Calculated Payment:" << people[i]->calculatePayment() << "\n\n";
    }

    // Clean up memory
    for (int i = 0; i < size; i++)
    {
        delete people[i];
    }
}
class undergraduateStudent : public student
{
private:
    string major = "";
    string minor = "";
    string expected_graduation_date = "";

public:
    undergraduateStudent() {}
    undergraduateStudent(string enrollment, string program, double GPA,
                         string major, string minor, string expected_graduation_date) : student(enrollment, program, GPA)
    {
        this->major = major;
        this->minor = minor;
        this->expected_graduation_date = expected_graduation_date;
    }

    string getUndergraduateStudentMajor() { return major; }
    string getUndergraduateStudentMinor() { return minor; }
    string getUndergraduateStudentExpectedGraduationDate() { return expected_graduation_date; }

    void setUndergraduateStudentMajor(string major)
    {
        this->major = major;
        cout << "Undergraduate Student Major Updated Successfully!\n";
    }

    void setUndergraduateStudentMinor(string minor)
    {
        this->minor = minor;
        cout << "Undergraduate Student Minor Updated Successfully!\n";
    }

    void setUndergraduateStudentExpectedGraduationDate(string date)
    {
        this->expected_graduation_date = date;
        cout << "Date Format is Correct!\nExpected Graduation Date Updated Successfully!\n";
    }

    void displayDetail() override
    {
        student::displayDetail();
        cout << "Undergraduate Student Details: \n";
        cout << "Major:\t" << major << '\n';
        cout << "Minor:\t" << minor << '\n';
        cout << "Expected Graduation Date:\t" << expected_graduation_date << '\n';
    }

    double calculatePayment() override
    {
        return student::calculatePayment() + 1;
    }
};
class GraduateStudent : public student
{
};

int main()
{
    cout << "CLASS person" << endl;
    Person p1("Krish", 18, "24csu104", "9899891897"); // parameterised constructer
    Person p2;                                                // default constructor
    Person p3(p1);                                            // copy constructor
    try
    {
        p1.set_person_age(-10); // setter method
    }
    catch (const invalid_argument &copy)
    {
        cerr << "Exception caught: " << copy.what() << endl;
    }
    try
    {
        p1.set_person_name(""); // Should throw
    }
    catch (const invalid_argument &copy)
    {
        cerr << "Exception caught: " << copy.what() << endl;
    }

    cout << "Person 1 Name:" << p1.get_person_name() << endl; // getter methods
    cout << "Person 1 Age:" << p1.get_person_age() << endl;
    cout << "Person 1 ID:" << p1.get_person_id() << endl;
    cout << "Person 1 Contact:" << p1.get_person_contact() << endl;
    cout << "CLASS student" << endl;
    student s1("4/5/25", "B.tech", 7.77);
    student s2;
    student s3(s1);
    try
    {
        s1.set_gpa(8.00);
    }
    catch (const invalid_argument &copy)
    {
        cerr << "Exception caught: " << copy.what() << '\n';
    }

    cout << "Student 1 Enrollment Date:" << s1.get_enrollment_date() << endl;
    cout << "Student 1 Program:" << s1.get_program() << endl;
    cout << "Student 1 GPA:" << s1.get_gpa() << endl;
    cout << "CLASS Proffessor" << endl;
    professor pr1("SOE", "Ai/ml", "4/5/25");
    professor pr2;
    professor pr3(pr1);
    pr1.set_department("APS");
    cout << "Professor 1 Department:" << pr1.get_department() << endl;
    cout << "Professor 1 Specialisation:" << pr1.get_specialisation() << endl;
    cout << "Professor 1 Hire Date:" << pr1.get_hire_date() << endl;
    cout << "CLASS Course" << endl;
    course c1("PSY150", "Engineering Physics", 3.0, "All about Physics");
    course c2;
    course c3(c1);
    try
    {
        c1.set_credit(-4.0);
    }
    catch (const invalid_argument &copy)
    {
        cerr << "Exception caught: " << copy.what() << '\n';
    }
    cout << "Course c1 Code:" << c1.get_code() << endl;
    cout << "Course c1 Title:" << c1.get_title() << endl;
    cout << "Course c1 Credit:" << c1.get_credit() << endl;
    cout << "Course c1 Description:" << c1.get_description() << endl;
    cout << "CLASS Department" << endl;
    department d1("SOE", "Old building", 25000);
    department d2;
    department d3(d1);

    d1.set_budget(0);
    cout << "Department d1 Name:" << d1.get_name() << endl;
    cout << "Department d1 Location:" << d1.get_location() << endl;
    cout << "Department d1 Budget:" << d1.get_budget() << endl;

    GradeBook gb1;
    gb1.setGrade("24csu121", 12);
    gb1.setGrade("24csu104", 15);
    gb1.setGrade("24csu353", 95);
    cout << gb1.calculateAverageGrade() << endl;
    cout << gb1.getHighestGrade() << endl;
    vector<string> failStudents = gb1.getFailingStudents();

    cout << "Failing Students: \n";
    for (auto student : failStudents)
    {
        cout << student << '\n';
    }
    gb1.printAllGrades();

    EnrollmentManager em;
    em.enrollStudent("CLL-110", "24CSU121");
    em.enrollStudent("PSY-150", "24CSU121");
    em.enrollStudent("CLL-110", "24CSU104");

    em.dropStudent("CLL-110", "24CSU121");

    cout << "Enrollment count for 24CSU121: " << em.getEnrollmentCount("CLL-110") << endl;
    em.printEnrolledStudents("CLL-110");

    cout << "--- Student Details ---" << endl;
    s1.displayDetail();

    cout << "\n--- Professor Details ---" << endl;
    pr1.displayDetail();

    cout << "Person Payment: " << p1.calculatePayment() << endl;
    cout << "Student Payment: " << s1.calculatePayment() << endl;
    cout << "Professor Payment: " << pr1.calculatePayment() << endl;

    cout << "--- Testing Student ---\n";
    testPerson(&s1); // or testPerson(s); if using reference version

    cout << "\n--- Testing Professor ---\n";
    testPerson(&pr1); // or testPerson(p);

    testArrayOfPersons();

    return 0;
}
