#include<iostream>
using namespace std;

class Media {
protected:
	char* Title;
public:
	//Media() : Title{ nullptr } {}

	Media(const char* p = nullptr) {
		if (p != nullptr) {
			int size = 0;
			for (int i = 0; p[i] != '\0'; i++) {
				size++;
			}
			size++;
			for (int i = 0; i < size; i++) {
				Title[i] = p[i];
			}
			//cout << "Media() Called " << endl;
		}
	}

	
	void SetTitle(const char* NewTitle) {
		int size = 0;
		for (int i = 0; NewTitle[i] != '\0'; i++) {
			size++;
		}
		size++;
		for (int i = 0; i < size; i++) {
			Title[i] = NewTitle[i];
		}
	}

	char* GetTitle() {
		return Title;
	}


	virtual void display() {
		cout << "Media: \"" << Title << "\" " << endl;
	}

	~Media() {
		//cout << "~Media() Called " << endl;
	}

};

//===================================================================================================================================================
//===================================================================================================================================================
//===================================================================================================================================================
//===================================================================================================================================================

class Book : public Media {
private:
	char *Author;
	char *ISBN;
public:

	/*Book() : Media() {
		Author = "\0";
		ISBN = "\0";
	}*/

	Book(char *Mediatype = nullptr, const char *author = nullptr, const char *isbn = nullptr) : Media(Mediatype) {
		if (author != nullptr) {
			int size = 0;
			for (int i = 0; author[i] != '\0'; i++) {
				size++;
			}
			size++;
			for (int i = 0; i < size; i++) {
				this->Author[i] = author[i];
			}
			size = 0;
			for (int i = 0; isbn[i] != '\0'; i++) {
				size++;
			}
			size++;
			for (int i = 0; i < size; i++) {
				this->ISBN[i] = isbn[i];
			}

			//cout << "Book() called" << endl;
		}
	}

	void Copy(const Book &B2) {
		if (B2.Author != nullptr) {
			int size = 0;
			for (int i = 0; B2.Author[i] != '\0'; i++) {
				size++;
			}
			size++;
			Author = new char[size];
			for (int i = 0; i < size; i++) {
				this->Author[i] = B2.Author[i];
			}
			size = 0;
			for (int i = 0; B2.ISBN[i] != '\0'; i++) {
				size++;
			}
			size++;
			this->ISBN = new char[size];
			for (int i = 0; i < size; i++) {
				this->ISBN[i] = B2.ISBN[i];
			}
		}
	}

	char *GetAuthor() {
		return this->Author;
	}

	char *&GetISBN() {
		return ISBN;

	}

	void UpdateInfo(int z) {
		cout << "Enter title of Media Item #" << z + 1 << ": \n";
		char MedTitle[20];
		cin.getline(MedTitle, 20, '\n');
		int size = 0;
		for (int i = 0; MedTitle[i] != '\0'; i++) {
			size++;
		}
		size++;
		Title = new char[size];
		for (int i = 0; i < size; i++) {
			this->Title[i] = MedTitle[i];
		}
		cout << "Enter Author's name: \n";
		char *author;
		author = new char[40];
		cin.getline(author, 40, '\n');
		size = 0;
		for (int i = 0; author[i] != '\0'; i++) {
			size++;
		}
		size++;
		Author = new char[size];
		for (int i = 0; i < size; i++) {
			this->Author[i] = author[i];
		}
		cout << "Enter Book's ISBN: \n";
		char *isbn;
		isbn = new char[18];
		cin.getline(isbn, 18, '\n');
		size = 0;
		for (int i = 0; isbn[i] != '\0'; i++) {
			size++;
		}
		size++;

		this->ISBN = new char[size];
		for (int i = 0; i < size; i++) {
			this->ISBN[i] = isbn[i];
		}

		delete[] author;
		author = nullptr;
		delete[] isbn;
		isbn = nullptr;
	}

	bool SearchBookTile(const char *author = nullptr) {
		if (author != nullptr) {
			bool res = false;

			int size = 0;
			for (int i = 0; author[i] != '\0'; i++) {
				size++;
			}
			size++;

			for (int i = 0; i < size; i++) {
				if (this->Author[i] == author[i]) {
					res = true;
				}
				else {
					return false;
				}
			}

			return res;
		}
	}

	bool SearchBookISBN(const char *isbn = nullptr) {
		if (isbn != nullptr) {
			bool res = false;

			int size = 0;
			for (int i = 0; isbn[i] != '\0'; i++) {
				size++;
			}
			size++;

			for (int i = 0; i < size; i++) {
				if (this->ISBN[i] == isbn[i]) {
					res = true;
				}
				else {
					return false;
				}
			}

			return res;
		}
	}

	void display() {
		cout << "============================================================================================" << endl;
		cout << "Media: \"" << Title << "\" \n" << "( Author: " << this->Author << ", ISBN: " << this->ISBN << " ) " << endl;
		cout << "============================================================================================" << endl;

	}

	~Book() {
		delete[] Author;
		Author = nullptr;
		delete[] ISBN;
		ISBN = nullptr;
	}
};

//===================================================================================================================================================
//===================================================================================================================================================
//===================================================================================================================================================
//===================================================================================================================================================

class Magazine : public Media {
private:
	char* MonthName;
	int Year;
public:

	/*Magazine() : Media() {
		MonthName = "\0";
		Year=0;
	}*/

	Magazine(char *Mediatype = nullptr, const char* month = nullptr, const int year = 0) : Media(Mediatype) {
		if (month != nullptr) {
			int size = 0;
			for (int i = 0; month[i] != '\0'; i++) {
				size++;
			}
			size++;
			for (int i = 0; i < size; i++) {
				this->MonthName[i] = month[i];
			}

			//	cout << "Magazine() called" << endl;
		}
	}

	void Copy(const Magazine &B2) {
		if (B2.MonthName != nullptr) {
			int size = 0;
			for (int i = 0; B2.MonthName[i] != '\0'; i++) {
				size++;
			}
			size++;
			MonthName = new char[size];
			for (int i = 0; i < size; i++) {
				this->MonthName[i] = B2.MonthName[i];
			}
			this->Year = B2.Year;

		}
	}

	char* GetMonthName() {
		return this->MonthName;
	}

	int GetYear() {
		return Year;
	}

	void UpdateInfo(int z) {
		cout << "Enter title of Media Item #" << z + 1 << ": \n";
		char MedTitle[20];
		cin.ignore(1, 'n');
		cin.clear();
		cin.getline(MedTitle, 20, '\n');
		int size = 0;
		for (int i = 0; MedTitle[i] != '\0'; i++) {
			size++;
		}
		size++;
		Title = new char[size];
		for (int i = 0; i < size; i++) {
			this->Title[i] = MedTitle[i];
		}
		cout << "Enter Month's name: \n";
		char *monName;
		monName = new char[10];
		cin.ignore(1, '\n');
		cin.clear();
		cin.getline(monName, 10, '\n');
		size = 0;
		for (int i = 0; monName[i] != '\0'; i++) {
			size++;
		}
		size++;
		MonthName = new char[size];
		for (int i = 0; i < size; i++) {
			this->MonthName[i] = monName[i];
		}
		cout << "Enter Year of Publication: \n";
		cin >> Year;
		delete[] monName;
		monName = nullptr;
	}

	void display() {
		cout << "============================================================================================" << endl;
		cout << "Media: \"" << Title << "\" \n" << "( Month: " << this->MonthName << ", Year of Publication: " << this->Year << " )" << endl;
		cout << "============================================================================================" << endl;

	}

	~Magazine() {
		delete[] MonthName;
		MonthName = nullptr;
		Year = 0;
	}
};

//===================================================================================================================================================
//===================================================================================================================================================
//===================================================================================================================================================
//===================================================================================================================================================

int main() {

	cout << "                          \" Welcome to The MEDIA_CREATOR \"                          ";
	cout << endl;
	int number = 0;
	cout << "Enter the No. of Media Items you wish to create:" << endl;
	cin >> number;

	Media *Medialist[number];
	Book Booktemp;
	Magazine Magtemp;
	for (int i = 0; i < number; i++) {

		system("CLS");
		int xin;

		for (int j = 0; j < number; j++) {
			cout << "What do you wish to do for Media Item #" << j + 1 << ": " << endl;
			cout << "1.Create Book. \n";
			cout << "2.Create Magazine. \n";
			cout << "Enter choice: ";

			cin >> xin;

			system("CLS");
			if (xin == 1) {
				cin.ignore(1, '\n');
				cin.clear();

				Booktemp.UpdateInfo(j);
				Medialist[j] = &Booktemp;

			}

			//=================================================================================================================================================================================

			else if (xin == 2) {
				Magtemp.UpdateInfo(j);
				Medialist[j] = &Magtemp;
			}


		}


		//=================================================================================================================================================================================
		bool kar = true;
		while (kar) {
			int vba;
			cout << "1.Display All Media Items. \n";
			cout << "2.Close Media Creator. \n";
			cin >> vba;
			if (vba == 1) {
				for (int j = 0; j < number; j++) {
					Medialist[j]->display();
				}
			}
			//=================================================================================================================================================================================
			else if (vba == 2) {
				kar = false;
			}
			else {
				cout << "Option unavailable \n";
				cout << "Enter Correct Choice: \n";
			}
		}
	}

	system("pause");
	return 0;
}