#include<iostream>
using namespace std;

class Message {
private:
	char *data;
public:

	Message(const char *p = nullptr) {
		if (p != nullptr) {
			int i = 0;
			for (; p[i] != '\0'; i++);
			i++;

			data = new char[i];
			int j = i;
			i = 0;
			for (; i <= j; i++) {
				data[i] = p[i];
			}
		}
	}

	void SetData(const char *q) {
		int i = 0;
		for (; q[i] != '\0'; i++);
		i++;

		data = new char[i];
		int j = i;
		i = 0;
		for (; i < j-1; i++) {
			data[i] = q[i];
		}
		data[i]='\0';
	}

	char *GetData() {
		return this->data;
	}

	void printinfo() {
		cout << this->data << endl;
	}

	Message &operator=(const Message &Masseg){
		SetData(Masseg.data);
		return *this;
	}

	friend ostream &operator<<(ostream &out, const Message &Masseg){
		out << Masseg.data;
		return out;
	}

	~Message() {
		if(data!= nullptr) {
			delete[] data;
			data = nullptr;
			cout << "~Message() called." << endl;
		}
	}
};


class Animal {
protected:
	Message Msg;
public:
	Animal(const char *text = nullptr) {
		if (text != nullptr) {
			Msg.SetData(text);
		}
	}

	virtual Message speak() {
		cout << "Animal's speak() called. \n";

		return Msg;
	}

	virtual ~ Animal() {
		cout <<"~Animal() called."<<endl;
	}
};

class Dog : public Animal {
public:

	Dog(const char* p=nullptr) : Animal(p) {}

	Message speak() override {
		cout<<"Dog's speak() called. \n";
		Msg.SetData("woof!");
		return Msg;
	}

	~Dog() override {
		cout <<"~Dog() called."<<endl;
	}
};

class Cat : public Animal {
public:
	Cat(char* p=nullptr) : Animal(p) {}

	Message speak() override {
		cout<<"Cat's speak() called. \n";
		Msg.SetData("mew!");

		return Msg;
	}

	~Cat() override {
		cout <<"~Cat() called."<<endl;
	}
};

int main() {
	const int size = 5;
	Animal * myPets[size];
	int i = 0;
	while (i<size) {
		int num;
		cout << "Press 1 for a Dog and 2 for a Cat."<< endl ;
		cin>>num;
		if(num==1) {
			cin.ignore(1,'\n');
			cin.clear();
			myPets[i] = new Dog[1];
			cout << "Dog added at position" << i << endl << endl;
			i++;
		} else if(num==2) {
			cin.ignore(1,'\n');
			cin.clear();
			myPets[i] = new Cat[1];
			cout << "Cat added at position " << i << endl << endl;
			i++;
		}else {
			cout << "Invalid input. Enter again." << endl << endl;
		}
	}

	for(int i=0; i<size; i++){
		cout <<	myPets[i]->speak() <<endl;
	}

	for(int i=0; i<size; i++){
		delete	myPets[i];
	}


	system("pause");
	return 0;
}

//Exercise#1 result:
//Animal's speak() called.
//Hi
//Dog's speak() called.
//woof!
//Animal's speak() called.
//Hi
//Dog's speak() called.
//woof!

//Exercise#1 result:
//Animal's speak() called.
////Hi

//Exercise#2 result:
//Dog's speak() called.
//woof!

//Exercise#3 result:
//Cat's speak() called.
//mew!
//Dog's speak() called.
//woof!

//Exercise#5 result:
//Dog's speak() called.
//woof!
//~Message() called.
//Cat's speak() called.
//mew!
//~Message() called.
//Cat's speak() called.
//mew!
//~Message() called.
//Dog's speak() called.
//woof!
//~Message() called.
//Dog's speak() called.
//woof!
//~Dog() called.
//~Animal() called.
//~Message() called.
//~Cat() called.
//~Animal() called.
//~Message() called.
//~Cat() called.
//~Animal() called.
//~Message() called.
//~Dog() called.
//~Animal() called.
//~Message() called.
//~Dog() called.
//~Animal() called.
//~Message() called.