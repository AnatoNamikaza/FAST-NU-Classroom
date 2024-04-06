#include<iostream>
using namespace std;

class Student {
	char name[50];
	char rollNo[50];
	float cgpa;
public:
	Student() : name{ '\0' }, rollNo{ '\0' } {
		cgpa = 0;
	}

	Student(const char* q = nullptr, const char* p = nullptr, float val = 0) {
		this->cgpa = val;
		int size1 = 0;
		int size2 = 0;
		if (p != nullptr) {
			for (int i = 0; p[i] != '\0'; i++) {
				size1++;
			}
			size1++;
			for (int i = 0; i < size1; i++) {
				name[i] = p[i];
			}
		}

		if (q != nullptr) {
			for (int i = 0; q[i] != '\0'; i++) {
				size2++;
			}
			size2++;
			for (int i = 0; i < size2; i++) {
				rollNo[i] = q[i];
			}
		}
		cout << "Student() Called " << endl;
	}

	void SetName(const char* NewName) {
		int size = 0;
		for (int i = 0; NewName[i] != '\0'; i++) {
			size++;
		}
		size++;
		for (int i = 0; i < size; i++) {
			name[i] = NewName[i];
		}
	}

	void SetRollNo(const char* newRollNo) {
		int size = 0;
		for (int i = 0; newRollNo[i] != '\0'; i++) {
			size++;
		}
		size++;
		for (int i = 0; i < size; i++) {
			name[i] = newRollNo[i];
		}
	}

	void SetCGPA(float CGPA) {
		cgpa = CGPA;
	}

	char* GetName() {
		return name;
	}

	char* GetRollNo() {
		return rollNo;
	}

	float GetCGPA() {
		return cgpa;
	}

	void Print() {
		cout << name << "(" << rollNo << ")" << endl;
	}

	~Student() {
		cout << "~Student() Called " << endl;
	}

};

class Society {
	char name[50];
	Student* president;
	Student* members[5]{};
public:
	Society() :name{ '\0' } {
		president = nullptr;
		for (int i = 0; i < 5; i++) {
			members[i] = nullptr;
		}
	}

	Society(const char* society, Student *p = nullptr, Student*q[5] = nullptr) {
		int size = 0;
		for (int i = 0; society[i] != '\0'; i++) {
			size++;
		}
		size++;
		for (int i = 0; i < size; i++) {
			name[i] = society[i];
		}
		if (p != nullptr) {
			president = (&(*p));
		}

		if (q[0] != nullptr) {
			for (int i = 0; i < 5; i++) {
				members[i] = (&(*q[i]));
			}
		}
	}

	void PrintInfo() {
		if (name[0] != '\0') {
			cout << "Society Name: " << name << endl;
		}
		else {
			cout << "Society Name: Not Available" << endl;
		}

		if (president != nullptr) {
			cout << "President: ";
			president->Print();
		}
		else {
			cout << "President: Not Available" << endl;
		}

		for (int i = 0; i < 5; i++) {
			if (&members[i] != nullptr) {
				cout << "Member#" << i + 1 << ": ";
				members[i]->Print();
			}
			else {
				cout << "Member#" << i + 1 << ": Not Available" << endl;
			}
		}
	}

	~Society() {
		cout << "~Society() called " << endl;
	}
};

int main() {
	Student s1("12L1111", "Hashim Amla", 3.99);
	Student s2("13L1121", "Virat Kohli", 3.45);
	Student s3("13L1126", "Quinton de Kock", 2.98);
	Student s4("14L1361", "Joe Root", 2.99);
	Student s5("14L1124", "Martin Guptil", 3.09);
	Student s6("15L1314", "Rohit Sharma", 3.19);
	
	Student* president = &s1;
	Student* participants[5];
	participants[0] = &s2;
	participants[1] = &s3;
	participants[2] = &s4;
	participants[3] = &s5;
	participants[4] = &s6;

	Society sports("Sports",president,participants[]);
	sports.PrintInfo();

	system("pause");
	return 0;
}

//Output:

