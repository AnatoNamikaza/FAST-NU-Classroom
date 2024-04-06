#include <iostream>
using namespace std;


//Question#1:

class Account {
protected:
	int AccountNumber;
	int* cnic;
	char* AccountHolder;
	double Balance;
	char* AccountOpenDate;
public:
	Account(char* Holder = NULL, int* Cnic = nullptr, int No = 0, char* OpenDate = NULL, double balance = 0.0) {
		AccountNumber = No;
		if (balance < 0) {
			cout << "Enter correct balance that is greater than 0 credits." << endl;
		}
		else {
			Balance = balance;
		}
		int size = 13;
		if (Cnic != nullptr) {
			cnic = new int[size];
			for (int i = 0; i < size; i++) {
				cnic[i] = Cnic[i];
			}
		}
		size = 0;
		if (Holder != NULL) {
			for (int i = 0; Holder[i] != '\0'; i++) {
				size++;
			}
			size++;
			AccountHolder = new char[size];
			for (int i = 0; i < size; i++) {
				AccountHolder[i] = Holder[i];
			}
		}
		size = 0;
		if (OpenDate != NULL) {
			for (int i = 0; OpenDate[i] != '\0'; i++) {
				size++;
			}
			size++;
			AccountOpenDate = new char[20];
			for (int i = 0; i < size; i++) {
				AccountOpenDate[i] = OpenDate[i];
			}
		}
	}

	int GetAccountNumber() {
		return this->AccountNumber;
	}

	double GetBalance() {
		return this->Balance;
	}

	int* Getcnic() {
		return this->cnic;
	}

	char* GetAccountOpenDate() {
		return this->AccountOpenDate;
	}

	char* GetAccountHolder() {
		return this->AccountHolder;
	}

	void SetAccountNumber(const int &p) {
		AccountNumber = p;
	}

	void SetBalance(const double &r) {
		if (r < 0) {
			cout << "Enter correct balance that is greater than 0 credits." << endl;
		}
		else {
			Balance = r;
		}
	}

	void Setcnic(const int* &p) {
		int size = 13;
		cnic = new int[size];
		for (int i = 0; i < size; i++) {
			cnic[i] = p[i];
		}
	}

	void SetAccountHolder(const char* &q) {
		int size = 0;
		for (int i = 0; q[i] != '\0'; i++) {
			size++;
		}
		size++;
		AccountHolder = new char[size];
		for (int i = 0; i < size; i++) {
			AccountHolder[i] = q[i];
		}
	}

	void SetAccountOpenDate(const char* &d) {
		int size = 0;
		for (int i = 0; d[i] != '\0'; i++) {
			size++;
		}
		size++;
		AccountOpenDate = new char[size];
		for (int i = 0; i < size; i++) {
			AccountOpenDate[i] = d[i];
		}
	}

	void Print() {
		cout << "( Name: " << AccountHolder << ", CNIC: ";
		for (int i = 0; i < 13; i++) {
			cout << cnic[i];
		}
		cout << ", Account No: " << AccountNumber << ", AccountOpeningDate: " << AccountOpenDate << ", CurrentBalance: " << Balance << " )" << endl;
	}

	~Account() {
		AccountNumber = 0;
		Balance = 0.0;
		delete[] cnic;
		cnic = NULL;
		delete[] AccountHolder;
		AccountHolder = NULL;
		delete[] AccountOpenDate;
		AccountOpenDate = NULL;
		cout << "Removing Account " << endl;
	}
};

class SavingsAccount :public Account {
public:
	static int Minbalance;

	SavingsAccount(char* Holder, int* cnic, int No, char* OpenDate, double balance) : Account(Holder, cnic, No, OpenDate, balance) {
		if (balance < Minbalance) {
			cout << "Enter correct balance that is greater than " << Minbalance << " credits.";
		}
	}

	void Deposit(double e) {
		Balance = Balance + e;
	}

	void Withdraw(double w) {
		if (w > Balance) {
			cout << "Insufficient amount of credits persent in your account.";
		}
		else {
			if (w > 50000) {
				Balance = Balance - w - (w*0.003);
			}
			else {
				Balance = Balance - w;
			}
		}
	}

	void CalculateProfit(const double &v) {
		Balance = Balance + (Balance*(v / 100));
	}

	void print() {
		Account::Print();
	}

	~SavingsAccount() {
		Minbalance = 0;
		cout << "Removing Account " << endl;
	}
};

class CurrentAccount :public Account {
public:
	static int Minbalance;

	CurrentAccount(char* Holder, int* cnic, int No, char* OpenDate, double balance) : Account(Holder, cnic, No, OpenDate, balance) {}

	void Deposit(double e) {
		Balance = Balance + e;
	}

	void Withdraw(double w) {
		if (w > Balance) {
			cout << "Insufficient amount of credits persent in your account.";
		}
		else {
			if (w > 50000) {
				Balance = Balance - w - (w*0.003);
			}
			else {
				Balance = Balance - w;
			}
		}
	}

	void print() {
		Account::Print();
	}

	~CurrentAccount() {
		Minbalance = 0;
		cout << "Removing Account " << endl;
	}
};

int SavingsAccount::Minbalance = 10000;
int CurrentAccount::Minbalance = 10000;




//Question#2:


class MobilePhone {
protected:
	int Battery;
	float Camera;
	char* OSVersion;
public:

	MobilePhone(int battery = 0, float Cam = 0, const char* OS = NULL) {
		Battery = battery;
		Camera = Cam;
		if (OS != NULL) {
			int size = 0;
			for (int i = 0; OS[i] != '\0'; i++) {
				size++;
			}
			size++;
			OSVersion = new char[size];
			for (int i = 0; i < size; i++) {
				OSVersion[i] = OS[i];
			}
		}
	}

	void InputMobileSpecs(int battery, float Cam, const char* OS) {
		Battery = battery;
		Camera = Cam;
		if (OS != NULL) {
			int size = 0;
			for (int i = 0; OS[i] != '\0'; i++) {
				size++;
			}
			size++;
			OSVersion = new char[size];
			for (int i = 0; i < size; i++) {
				OSVersion[i] = OS[i];
			}
		}
	}

	void print() {
		cout << "Battery: " << Battery << ", Camera: " << Camera << ", OS Version: " << OSVersion << endl;
	}

	~MobilePhone() {
		Battery = 0;
		Camera = 0;
		delete[] OSVersion;
		OSVersion = NULL;
		cout << "Specs erased." << endl;
	}
};

class Android : public  MobilePhone {
	int RAM;
public:

	Android() : MobilePhone() {
		RAM = 0;
	}

	Android(int battery, float Cam, char* OS, int Ram = 0) : MobilePhone(battery, Cam, OS) {
		RAM = Ram;
	}

	float GetCamera() {
		return this->Camera;
	}

	void InputAndroidSpecs(int battery, float Cam, const char* OS, int Ram) {
		MobilePhone::InputMobileSpecs(battery, Cam, OS);
		RAM = Ram;
	}

	void print() {
		cout << "Battery: " << Battery << ", Camera: " << Camera << ", OS Version: " << OSVersion << ", RAM: " << RAM << "\n";
	}

	~Android() {
		RAM = 0;
		cout << "Android mobile destoryed." << endl;
	}
};

void ChangePhones(Android &phone1, Android &phone2) {
	Android temp = phone1;
	phone1 = phone2;
	phone2 = temp;
}

void sortByCamera(Android *&Phones, int noOfmobiles) {
	cout << "Enter Choice:- " << endl;
	cout << "1. To sort by Camera in ascending order." << endl;
	cout << "2. To sort by Camera in descending order." << endl;
	cin.ignore(1, '\n');
	cin.clear();
	int x;
	cin >> x;

	if (x == 1) {
		int i, j;
		for (i = 0; i < noOfmobiles - 1; i++) {
			for (j = 0; j < noOfmobiles - i - 1; j++) {
				if (Phones[j].GetCamera() > Phones[j + 1].GetCamera()) {
					ChangePhones(Phones[j], Phones[j + 1]);
				}
			}
		}
		cout << "List of Android Phones sorted by Camera in ascending order: " << endl;
		for (int p = 0; p < noOfmobiles; p++) {
			Phones[p].print();
		}
	}

	if (x == 2) {
		int i, j;
		for (i = 0; i < noOfmobiles - 1; i++) {
			for (j = 0; j < noOfmobiles - i - 1; j++) {
				if (Phones[j].GetCamera() > Phones[j + 1].GetCamera()) {
					ChangePhones(Phones[j], Phones[j + 1]);
				}
			}
		}
		cout << "List of Android Phones sorted by Camera descending order: " << endl;
		for (int p = 0; p < noOfmobiles; p++) {
			Phones[p].print();
		}
	}
}

class iPhone : public MobilePhone {
	bool AudioJack;
public:

	iPhone() : MobilePhone() {
		AudioJack = false;
	}

	iPhone(int battery, float Cam, char* OS, bool audio = 0) : MobilePhone(battery, Cam, OS) {
		AudioJack = audio;
	}


	void InputiPhoneSpecs(int battery, float Cam, const char* OS, int audio) {
		MobilePhone::InputMobileSpecs(battery, Cam, OS);
		AudioJack = audio;
	}

	void print() {
		cout << "Camera: " << Camera << ", OS Version: " << OSVersion << ", Audio Jack: ";
		if (AudioJack = true) {
			cout << "AudioJack feature is available in the phone." << endl;
		}
		else {
			cout << "AudioJack feature is unavailable in the phone." << endl;
		}
	}

	~iPhone() {
		AudioJack = 0;
		cout << "iPhone mobile destoryed." << endl;
	}
};


int main() {

	//Question#1:

	/*char *name = new char[10] {"Bob"}; 	
	char *date = new char[10] {"Kelver"};
	int *CN1= new int[13] {1,2,3,4,5,6,7,8,9,4,5,6,7};

	Account a(name,CN1, 57, date, (double)0170212.0);
	a.Print();
	CurrentAccount b(name,CN1 , 57, date, (double)70212.0);
	b.print();
	SavingsAccount c(name, CN1, 57, date, (double)70212.0);
	c.print();
	c.CalculateProfit(11);
	c.print();



	//Question - 2

	MobilePhone Mob1;
	MobilePhone Mob2(4500, 12.0, "Nougat");
	Mob1.InputMobileSpecs(5500, 16.25, "Venom");
	Mob1.print();
	Mob2.print();
	Android Adm1;
	char *V1 = new char[11]{ "Oreo" };
	Android Adm2(4000, 18.0, V1, 4);
	Adm1.InputAndroidSpecs(6000, 22.0, "Oreo", 16);
	Adm1.print();
	Adm2.print();
	iPhone ios1;
	char *V2 = new char[11]{ "Oreo" };
	iPhone ios2(3000, 16.0, V2, true);
	ios1.InputiPhoneSpecs(3000, 16.0, "iOS 11.01", true);
	ios1.print();
	ios2.print();
	int noOfAndroidPhones;
	cout << "Enter number of android phones: ";
	cin >> noOfAndroidPhones;
	Android *AndroidPhones = new Android[noOfAndroidPhones];
	cout << "Enter Specs of Phones in format: Battery\\Camera\\OSVersion\\RAM" << endl;
	for (int i = 0; i < noOfAndroidPhones; i++) {
		int j = i + 1;
		int battery = 0, Ram = 0;
		float Cam = 0;
		char* OS = new char[15];
		cout << "Battery\\Camera #" << j << ": " << endl;
		cin >> battery >> Cam;
		cout << "OSVersion #" << j << ": " << endl;
		cin.ignore(1, '\n');
		cin.clear();
		cin.getline(OS, 15, '\n');
		cout << "RAM#" << j << ": " << endl;
		cin >> Ram;

		AndroidPhones[i].InputAndroidSpecs(battery, Cam, OS, Ram);
	}



	sortByCamera(AndroidPhones, noOfAndroidPhones);


	system("pause");

	return 0;
}