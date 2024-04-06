#include<iostream>
using namespace std;

class CompactDisc {
	char title[20];
	int capacity;
public:
	CompactDisc() : title{ NULL } {
		capacity = 0;
	}

	CompactDisc(char* p, int val) {
		this->capacity = val;
		int size = 0;
		for (int i = 0; p[i] != '\0'; i++) {
			size++;
		}
		size++;
		for (int i = 0; i < size; i++) {
			title[i] = p[i];
		}
		cout << "CompactDisc() Called " << endl;
	}

	void SetTitle(char* p) {
		int size = 0;
		for (int i = 0; p[i] != '\0'; i++) {
			size++;
		}
		size++;
		for (int i = 0; i < size; i++) {
			title[i] = p[i];
		}
	}

	void SetCapacity(int val) {
		capacity = val;
	}

	int GetCapacity() {
		return this->capacity;
	}

	char* GetTitle() {
		return this->title;
	}

	~CompactDisc() {
		cout << "~CompactDisc() Called " << endl;
	}

	void print() {
		cout << "( Title: " << title << " ) \n" << " Capacity: " << capacity << endl;

	}
};

class CDDrive {
	char manufacturer[20];
	int speed;
	CompactDisc* aCompactDisc;
public:
	CDDrive() : manufacturer{ NULL } {
		speed = 0;
	}

	CDDrive(char* company, int sped) {
		this->speed = sped;
		int size = 0;
		for (int i = 0; company[i] != '\0'; i++) {
			size++;
		}
		size++;
		for (int i = 0; i < size; i++) {
			manufacturer[i] = company[i];
		}
		aCompactDisc = nullptr;

		cout << "CDDrive() called " << endl;
	}

	void InsertCD(CompactDisc* obj) {
		aCompactDisc = new CompactDisc;
		if (obj != nullptr) {
			aCompactDisc->SetTitle(obj->GetTitle());
			aCompactDisc->SetCapacity(obj->GetCapacity());
			
		}
	}

	void Play() {
		if (aCompactDisc->GetTitle() == NULL) {
			cout << "Please insert a disc. \n";
		}
		else {
			cout << "( Title: " << aCompactDisc->GetTitle() << " ) \n" << " Capacity: " << aCompactDisc->GetCapacity() << endl;
		}
	}

	CompactDisc *EjectCD() {
		CompactDisc *ptr;

		if (aCompactDisc->GetTitle() == NULL) {
			ptr = nullptr;
			return ptr;
		}
		else {
			ptr = aCompactDisc;
			aCompactDisc = nullptr;
			return ptr;
		}
	}

	void print() {
		cout << "( Manufacturer: " << manufacturer << " ,Speed: " << speed << " ) \n";
		aCompactDisc->print();
	}

	~CDDrive() {
		cout << "~CDDrive() called " << endl;
	}
};

int main(){
	char title[] = "King in Distress", title2[] = "Way To Happiness";
	char manufacturer1[] = "Legend Records";
	CompactDisc cd1(title, 440);
	CompactDisc cd2(title2, 350);
	CompactDisc* ptr1;
	CompactDisc* ptr2;
	ptr1 = &cd1;
	ptr2 = &cd2;
	CDDrive theCDDrive(manufacturer1, 50);
	theCDDrive.InsertCD(ptr1);
	theCDDrive.Play();
	theCDDrive.EjectCD();
	theCDDrive.Play();
	theCDDrive.InsertCD(ptr2);
	theCDDrive.Play();
	theCDDrive.EjectCD();
	system("pause");
	return 0;
}

//Output:
//CompactDisc() Called
//CompactDisc() Called
//CDDrive() called
//(Title : King in Distress)
//Capacity : 440
//Please insert a disc.
//(Title : Way To Happiness)
//Capacity : 350
//~CDDrive() called
//~CompactDisc() Called
//~CompactDisc() Called

