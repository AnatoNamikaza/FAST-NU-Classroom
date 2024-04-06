#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------Global Template Function----------------------------------------
//Add here




//-----------------------------------------Name----------------------------------------------------------
class Name{
	char* fname;
	char* lname;
public:
	Name(char* fname, char* lname) {
		this->fname = new char[strlen(fname) + 1];
		this->lname = new char[strlen(lname) + 1];
		strcpy(this->fname, fname);
		strcpy(this->lname, lname);
	}
	~Name() {
		if (fname != nullptr)
			delete[] fname;
		if (lname != nullptr)
			delete[] lname;
	}

	Name(const Name & n) {
		this->fname = new char[strlen(n.fname) + 1];
		this->lname = new char[strlen(n.lname) + 1];
		strcpy(this->fname, n.fname);
		strcpy(this->lname, n.lname);

	}
	friend ostream& operator<<(ostream& out, const Name & n);
};

ostream& operator<<(ostream& out, const Name & n) {
	out << n.fname << " " << n.lname;
	return out;
}

//-----------------------------------------Player----------------------------------------------------------

class Player {
	int id;
	Name  pname;
	char * contact;
	int balance;
	static int count;
public:
	//Add all required functions.
	friend ostream& operator<<(ostream& out, const Player& p);
};

//-----------------------------------------------------------------------------------------------------------

//Add all required classes with complete Implementaion here.


//-----------------------------------------GamingZone----------------------------------------------------------

class GamingZone {
	//Add all required functions and data members.
public:
	void run() {
		while (true) {
			system("cls");
			int option;
			cout << "What do you want to do?\n\t1. Register new player\n\t2. Login\n\t3. Press Any key to Exit \n\nEnter your choice: ";
			cin >> option;
			if (option == 1) // 1. Register new player
			{
				signUp();
				system("PAUSE");
			}
			else if (option == 2)	// 2. Login
			{
				int id;
				cout << "Enter Your User Id:";
				cin >> id;
				if (getPlayerWithId(id) != nullptr) { //Search player in list and return its address if exist.
					cout << "What do you want to do?\n\t1. Play a PS game\n\t2. Play a PC game\n\t3. Press Any key to Exit\n\nEnter your choice: ";
					cin >> option;
					if (option == 1) // 1. Play a PS game
						playonPS(id); 
					else if (option == 2)	// 2. Play a PC game
						playonPC(id);
					else  //3. Exit
						return;  
				}
			}
			else //3. Exit
				return; 
		}
	}

};

//-----------------------------------------Driver----------------------------------------------------------
int main() {
		GamingZone zone (50, 20);
		zone.loadPlayers();
		zone.loadPlatforms();
		zone.run();
		return 0;
}