#include <iostream>
using namespace std;

class Animal {
protected:
	int id;

public:

	Animal() {
		id = 0;
		cout << "Animal's Default Constructor." << endl;
	}

	Animal(int i) {
		id = i;
		cout << "Animal's Default Constructor." << endl;
	}

	int GetAnimalId() {
		return this->id;
	}

	void SetAnimalId(int x) {
		this->id = x;
	}

	virtual void tellAboutSelf() {
		cout << "I am an Animal.\n";
	}

	virtual void Speak() {
		cout << "I am Animal, I can't speak...." << endl;
	}

	~Animal() {
		cout << "Animal's Default Destructor." << endl;
	}
};

class Reptile : public Animal {
public:

	Reptile() {
		id = 1;
		cout << "Reptile's Default Constructor." << endl;
	}

	Reptile(int x) : Animal(x) {
		cout << "Reptile's Default Constructor." << endl;
	}

	void tellAboutSelf() {
		cout << "I am a Reptile." << endl;
	}

	void Speak() {
		cout << "Family of Reptiles..." << endl;
	}

	~Reptile() {
		cout << "Reptile's Default Destructor." << endl;
	}
};

class Bird : public Animal {
public:

	Bird() {
		id = 2;
		cout << "Bird's Default Constructor." << endl;
	}

	Bird(int x) : Animal(x) {
		cout << "Bird's Default Constructor." << endl;
	}

	void tellAboutSelf() {
		cout << "I am a Bird." << endl;
	}

	void Speak() {
		cout << "Family of Birds...." << endl;
	}

	~Bird() {
		cout << "Bird's Default Destructor." << endl;
	}
};

class Mammal : public Animal {
public:

	Mammal() {
		id = 3;
		cout << "Mammal's Default Constructor." << endl;
	}

	Mammal(int x) : Animal(x) {
		cout << "Mammal's Default Constructor." << endl;
	}

	void tellAboutSelf() {
		cout << "I am a Mammal." << endl;
	}

	void Speak() {
		cout << "Family of Mammals...." << endl;
	}

	~Mammal() {
		cout << "Mammal's Default Destructor" << endl;
	}
};

class Snake : public Reptile {
public:

	int GetFamily() {
		return id;
	}

	void Speak() {
		cout << "( Voice: Shhh...)" << endl;
	}

	void tellAboutSelf() {
		cout << "---------------------------------------------------------" << endl;
		cout << "I am a Snake" << endl;
		cout << "My Family class is Reptile." << endl;
		cout << "My Family ID is: " << GetFamily() << endl;
		cout << "---------------------------------------------------------" << endl;
	}
};

class Parrot : public Bird {
public:

	int GetFamily() {
		return id;
	}

	void Speak() {
		cout << "( Voice: Trrrr...)" << endl;
	}

	void tellAboutSelf() {
		cout << "---------------------------------------------------------" << endl;
		cout << "I am a Parrot." << endl;
		cout << "My Family class is Bird." << endl;
		cout << "My Family ID is: " << GetFamily() << endl;
		cout << "---------------------------------------------------------" << endl;
	}
};

class Horse : public Mammal {
public:

	int GetFamily() {
		return id;
	}

	void Speak() {
		cout << "( Voice: Hurrrrr...)" << endl;
	}

	void tellAboutSelf() {
		cout << "---------------------------------------------------------" << endl;
		cout << "I am a Horse.." << endl;
		cout << "My Family class is Mammel." << endl;
		cout << "My Family ID is: " << GetFamily() << endl;
		cout << "---------------------------------------------------------" << endl;
	}
}


int main() {
	Animal Animal1;
	Animal1.tellAboutSelf();
	Animal1.Speak();


	Reptile Reptile1;
	Reptile1.tellAboutSelf();
	Reptile1.Speak();


	Snake Snake1;
	Snake1.tellAboutSelf();
	Snake1.Speak();
	cout << "[The id of Snake Family is: " << Snake1.GetFamily() << " ]" << endl;
	cout << "---------------------------------------------------------" << endl;


	Bird Bird1;
	Bird1.tellAboutSelf();
	Bird1.Speak();
	
	
	Parrot Parrot1;
	Parrot1.tellAboutSelf();
	Parrot1.Speak();
	cout << "[The id of Parrot Family is: " << Parrot1.GetFamily() << " ]" << endl;
	cout << "---------------------------------------------------------" << endl;
	
	
	Mammal Mammal1;
	Mammal1.tellAboutSelf();
	Mammal1.Speak();
	
	
	Horse Horse1;
	Horse1.tellAboutSelf();
	Horse1.Speak();
	cout << "[The id of Horse Family is: " << Horse1.GetFamily() << " ]" << endl;
	cout << "---------------------------------------------------------" << endl;

	
	
	
	system("pause");
	return 0;
}

//Result:
//Animal's Default Constructor.
//I am an Animal.
//I am Animal, I can't speak....
//Animal's Default Constructor.
//Reptile's Default Constructor.
//I am a Reptile.
//Family of Reptiles...
//Animal's Default Constructor.
//Reptile's Default Constructor.
//---------------------------------------------------------
//I am a Snake
//My Family class is Reptile.
//My Family ID is: 1
//---------------------------------------------------------
//( Voice: Shhh...)
//[The id of Snake Family is: 1 ]
//---------------------------------------------------------
//Animal's Default Constructor.
//Bird's Default Constructor.
//I am a Bird.
//Family of Birds....
//Animal's Default Constructor.
//Bird's Default Constructor.
//---------------------------------------------------------
//I am a Parrot.
//My Family class is Bird.
//My Family ID is: 2
//---------------------------------------------------------
//( Voice: Trrrr...)
//[The id of Parrot Family is: 2 ]
//---------------------------------------------------------
//Animal's Default Constructor.
//Mammal's Default Constructor.
//I am a Mammal.
//Family of Mammals....
//Animal's Default Constructor.
//Mammal's Default Constructor.
//---------------------------------------------------------
//I am a Horse..
//My Family class is Mammel.
//My Family ID is: 3
//---------------------------------------------------------
//( Voice: Hurrrrr...)
//[The id of Horse Family is: 3 ]
//---------------------------------------------------------
//Press any key to continue . . .
//Mammal's Default Destructor
//Animal's Default Destructor.
//Mammal's Default Destructor
//Animal's Default Destructor.
//Bird's Default Destructor.
//Animal's Default Destructor.
//Bird's Default Destructor.
//Animal's Default Destructor.
//Reptile's Default Destructor.
//Animal's Default Destructor.
//Reptile's Default Destructor.
//Animal's Default Destructor.
//Animal's Default Destructor.
