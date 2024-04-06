#include <iostream> 
using namespace std;

//class University {
//	Person A;
//public:
//
//};

class Person {
	char* first_Name;
	char* last_Name;
public:
	int age;
	Person() {
		cout << "Person() called" << endl;
		first_Name = NULL;
		last_Name = NULL;
		age = 0;
	}

	Person(char p[], char q[], int a) {
		cout << "Person() called" << endl;
		int size = 0;
		for (int i = 0; p[i] != '\0'; i++) {
			size++;
		}
		size++;
		first_Name = new char[size];
		for (int i = 0; i < size; i++) {
			first_Name[i] = p[i];
		}
		size = 0;
		for (int i = 0; q[i] != '\0'; i++) {
			size++;
		}
		size++;
		last_Name = new char[size];
		for (int i = 0; i < size; i++) {
			last_Name[i] = q[i];
		}
		age = a;
	}

	char* GetFirstName() {
		return this->first_Name;
	}

	char* GetLastName() {
		return this->last_Name;
	}

	void SetFirstName(const char* &p) {
		int size = 0;
		for (int i = 0; p[i] != '\0'; i++) {
			size++;
		}
		size++;
		first_Name = new char[size];
		for (int i = 0; i < size; i++) {
			first_Name[i] = p[i];
		}
	}

	void SetLastName(const char* &q) {
		int size = 0;
		for (int i = 0; q[i] != '\0'; i++) {
			size++;
		}
		size++;
		last_Name = new char[size];
		for (int i = 0; i < size; i++) {
			last_Name[i] = q[i];
		}
	}
	void print() {
		cout << first_Name << last_Name << ", Age: " << age;
	}

	~Person() {
		delete[] first_Name;
		first_Name = NULL;
		delete[] last_Name;
		last_Name = NULL;
		cout << "Erasing Person's Info \n";
	}
};

class Faculty :public Person {
	int course_count;
	int ext_number;
public:
	Faculty() : Person() {
		cout << "Faculty() called" << endl;
		course_count = 0;
		ext_number = 0;
	}

	Faculty(char p[], char q[], const int &a, const int &course_count = 0, const int &ext_number = 0) : Person(p, q, a) {
		cout << "Faculty() called" << endl;
		this->course_count = course_count;
		this->ext_number = ext_number;

	}

	int GetCourse_count() {
		return this->course_count;
	}

	int GetExt_number() {
		return this->ext_number;
	}

	void SetCourse_count(const int &a) {
		this->course_count = a;
	}

	void SetExt_number(const int &b) {
		this->ext_number = b;
	}

	void printFaculty() {
		cout << "\"Faculty Member name: ";
		Person::print();
		cout<< ", Numer of courses: " << this->course_count << ", Ext. " << this->ext_number << "\" \n";
	}

	~Faculty() {
		course_count = 0;
		ext_number = 0;
		cout << "Erasing Faculty Person's Info \n";
	}
};

class Student :public Person {
	float CGPA;
public:
	Student() : Person() {
		cout << "Student() called" << endl;
		CGPA = 0;
	}

	Student(char p[], char q[], int a, const float &cgpa = 0) : Person(p, q, a) { 
		cout << "Student() called" << endl;
		this->CGPA = cgpa;

	}

	float GetCGPA() {
		return CGPA;
	}

	void SetCGPA(const float &c) {
		this->CGPA = c;
	}

	void printStudent() {
		cout << "\"Student name: ";
		Person::print();
		cout << ", the CGPA of student is: " << this->CGPA << " .\"" << endl;

	}

	~Student() {
		CGPA = 0;
		cout << "Erasing Student's Info \n";
	}
};

class Undergraduate :public Student {
	char* FYP_name;
public:
	Undergraduate() : Student() {
		cout << "Undergraduate() called" << endl;
		FYP_name = NULL;
	}

	Undergraduate(char p[], char q[], const int &a, const float &cgpa, char fyp[] = '\0') : Student(p, q, a, cgpa) {
		cout << "Undergraduate() called" << endl;
		int size = 0;
		for (int i = 0; fyp[i] != '\0'; i++) {
			size++;
		}
		size++;
		FYP_name = new char[size];
		for (int i = 0; i < size; i++) {
			FYP_name[i] = fyp[i];
		}
	}

	char* GetFYP_name() {
		return this->FYP_name;
	}

	void SetFYP_name(const char* &w) {
		int size = 0;
		for (int i = 0; w[i] != '\0'; i++) {
			size++;
		}
		size++;
		FYP_name = new char[size];
		for (int i = 0; i < size; i++) {
			FYP_name[i] = w[i];
		}
	}

	void printUndergraduate() {
		cout << "\"" << GetFirstName() << " " << GetLastName();
		cout << "is an undergraduate student, the CGPA of student: ";
		cout << GetCGPA();
		cout << " and his final year project is titled ";
		cout << this->FYP_name;
		cout << "\" \n";
	}

	~Undergraduate() {
		cout << "Undergraduate Info deleted" << endl;
		delete[] FYP_name;
		FYP_name = NULL;
	}
};

class Graduate :public Student {
	char* Thesis_topic;
public:
	Graduate() : Student() {
		cout << "Graduate() called" << endl;
		Thesis_topic = NULL;
	
	}
	Graduate(char p[], char q[], const int &a, const float &cgpa, char thesis[] = '\0') : Student(p, q, a, cgpa) {
		cout << "Graduate() called" << endl;
		int size = 0;
		for (int i = 0; thesis[i] != '\0'; i++) {
			size++;
		}
		size++;
		Thesis_topic = new char[size];
		for (int i = 0; i < size; i++) {
			Thesis_topic[i] = thesis[i];
		}
	}

	char* GetThesis_topic() {
		return this->Thesis_topic;
	}

	void SetThesis_topic(const char* &e) {
		int size = 0;
		for (int i = 0; e[i] != '\0'; i++) {
			size++;
		}
		size++;
		Thesis_topic = new char[size];
		for (int i = 0; i < size; i++) {
			Thesis_topic[i] = e[i];
		}
	}

	void printGraduate() {
		cout << "\"" << GetFirstName() << " " << GetLastName();
		cout << "is an undergraduate student, the CGPA of student: ";
		cout << GetCGPA();
		cout << " and his final year project is titled ";
		cout << this->Thesis_topic;
		cout << "\" \n";
	}

	~Graduate() {
		cout << "Graduate Info deleted" << endl;
		delete[] Thesis_topic;
		Thesis_topic = NULL;
	}
};

int main()
{	
	char name1[] = "Ted";
	char name2[] = "Thompson";
	char name3[] = "Richard";
	char name4[] = "Karp";
	char name5[] = "Arnold";
	char name6[] = "Gates";
	char Proj1[] = "The Event Locator";
	char Proj2[] = "Distributed Algorithms";
	//Student s(name1, name2, 22,(float) 3.91);
	
	//Faculty f(name3, name4, 45, 2, 420);
	//here the number of courses is 2
	//and the extension number is 420


	/*s.printStudent();
	f.printFaculty();
	*/

	Undergraduate u(name1, name2, 22, (float) 3.91, Proj1);
	Graduate g(name5, name6, 25, (float) 3.01, Proj2);

	u.printUndergraduate();
	g.printGraduate();

	u.printStudent();

	return 0;
}

//Exercise#5:
//Person() called
//Student() called
//Undergraduate() called
//Person() called
//Faculty() called
//Erasing Faculty Person's Info
//Erasing Person's Info
//Erasing Student's Info
//Erasing Person's Info

//Exercise#6:
//Person() called
//Student() called
//Person() called
//Faculty() called
//"Student name: TedThompson, Age: 22, the CGPA of student is: 3.91 ."
//"Faculty Member name: RichardKarp, Age: 45, Numer of courses: 2, Ext. 420"
//Erasing Faculty Person's Info
//Erasing Person's Info
//Erasing Student's Info
//Erasing Person's Info

//Exercise#7:
//Person() called
//Student() called
//Undergraduate() called
//Person() called
//Student() called
//Graduate() called
//"Ted Thompsonis an undergraduate student, the CGPA of student: 3.91 and his final year project is titled The Event Locator"
//"Arnold Gatesis an undergraduate student, the CGPA of student: 3.01 and his final year project is titled Distributed Algorithms"
//"Student name: TedThompson, Age: 22, the CGPA of student is: 3.91 ."
//Erasing Student's Info
//Erasing Person's Info
//Erasing Student's Info
//Erasing Person's Info

