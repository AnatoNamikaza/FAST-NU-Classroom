#include <fstream>
#include "Train.h"
using namespace std;

bool Train::compare(char* P1, char* P2){
	bool res= false;
	int size1=0,size2=0;
	for(int i=0;P1[i]!='\0';i++){
		size1++;
	}
	for(int i=0;P2[i]!='\0';i++){
		size2++;
	}
	if (size1 == size2) {
		for (int i = 0; i < size1; i++) {
			if (P1[i] == P2[i]) {
				res = true;
			} else {
				res = false;
				return res;
			}
		}
	}
	return res;
}

Train::Train() {
		engine = nullptr;
		Bogies = nullptr;
		TBogies = 0;
	}

void Train::TrainMaker(int x) {
	if (x == 0) {
		cout << "No Data in train \n";
	} else if (x == 1) {

		Bogies = new Bogie[1];
		engine = new Bogie[1];

		engine->SetNext(&Bogies[0]);

	} else {
		Bogies = new Bogie[x];
		engine = new Bogie[1];

		engine->SetNext(&Bogies[0]);

		for (int i = 0; i < x-1; i++) {
			Bogies[i].SetNext(&Bogies[i + 1]);
		}
	}
}

void Train::drawTrain(sf::RenderWindow &window) {

	if (engine != nullptr) {
		sf::Texture engineTexture = sf::Texture();
		engineTexture.loadFromFile("Engine.jpeg");
		engineTexture.setSmooth(true);

		sf::RectangleShape Engine;
		Engine.setSize(sf::Vector2f(0.25622255 * window.getSize().x, 0.1953125 * window.getSize().y));
		Engine.setPosition(window.getSize().x * 0.014641288, window.getSize().y - 450);
		Engine.setTexture(&engineTexture);
		window.draw(Engine);
		window.display();

		for (int i = 0; i < TBogies; i++) {

			if (i == 0) {
				sf::Texture texture;
				texture.loadFromFile("Bogie.jpeg");
				texture.setSmooth(true);

				Length = Engine.getSize().x + Engine.getPosition().x;
				sf::RectangleShape bogie;
				bogie.setSize(sf::Vector2f(0.25622255 * window.getSize().x, 0.1953125 * window.getSize().y));
				bogie.setPosition(Length, window.getSize().y - 450);
				bogie.setTexture(&texture);
				window.draw(bogie);
				window.display();
			} else {
				Length += 0.25622255 * window.getSize().x;
				sf::Texture texture;
				texture.loadFromFile("Bogie.jpeg");
				texture.setSmooth(true);

				sf::RectangleShape bogie;
				bogie.setSize(sf::Vector2f(0.25622255 * window.getSize().x, 0.1953125 * window.getSize().y));
				bogie.setPosition(Length, window.getSize().y - 450);
				bogie.setTexture(&texture);
				window.draw(bogie);
				window.display();
			}
		}
	}
}

bool Train::addBogie() {
	int Res = 1;
	int c;

	if (TBogies == 0) {

		Bogies = new Bogie[1];
		Bogies[0].UpdateID();

		TBogies++;

		engine = new Bogie[1];
		engine->SetNext(&Bogies[0]);

		cout << "Would you like to fill Passengers in the new Bogie:- \n";
		cout << "1.Yes, I would. \n";
		cout << "2.No, Maybe later. \n";
		cout << "Enter Choice: \n";

		while (true) {
			cin >> c;
			system("CLS");

			if (c == 1) {
				int x = Bogies[0].AddPassengers();
				if (x == 1) {
					cout << "Passangers have been boarded on the Bogie. \n";
				}
				else if (x == 0) {
					cout << "No Passangers were boarded on the Bogie. \n";
				}
				break;

			}
			else if (c == 2) {
				return Res;
			}
			else {
				cout << "Option is not available. \n";
				cout << "Enter correct choice: \n";
			}
		}
	}
	else {
		Bogie *temp;
		int size = TBogies;

		temp = new Bogie[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i].BogieCopy(this->Bogies[i]);
		}

		temp[size].UpdateID();
		temp[size - 1].SetNext(&temp[size]);

		cout << "Would you like to fill Passengers in the new Bogie:- \n";
		cout << "1.Yes, I would. \n";
		cout << "2.No, Maybe later. \n";
		cout << "Enter Choice: \n";

		while (true) {
			cin >> c;
			system("CLS");

			if (c == 1) {
				int x = temp[size].AddPassengers();
				if (x == 1) {
					cout << "Passangers have been boarded on the Bogia. \n";
				}
				else if (x == 0) {
					cout << "No Passangers were boarded on the Bogia. \n";
				}

				break;

			}
			else if (c == 2) {
				break;
			}
			else {
				cout << "Option is not available. \n";
				cout << "Enter correct choice: \n";
			}
		}

		delete[] Bogies;
		Bogies = new Bogie[size + 1];

		for (int i = 0; i < size + 1; i++) {
			Bogies[i].BogieCopy(temp[i]);
		}
		TBogies = size + 1;

		delete[] temp;
		temp = nullptr;

	}

	return Res;
}

void Train::removeBogie(sf::RenderWindow &window, tgui::Gui &gui) {

	tgui::Theme theme{"themes/Black.txt"};
	tgui::Theme::setDefault(&theme);

	tgui::ChildWindow::Ptr child = tgui::ChildWindow::create("Bogie ID");
	child->setRenderer(theme.getRenderer("ChildWindow"));
	child->setSize({"50%", "25%"});
	child->setPosition("25%", "30%");
	gui.add(child);

	tgui::EditBox::Ptr BogieID = tgui::EditBox::create();
	BogieID->setSize({"70%", "20%"});
	BogieID->setPosition({"15%", "25%"});
	BogieID->setDefaultText("Enter Bogie_ID:");
	child->add(BogieID);
	BogieID->setFocused(true);

	tgui::Button::Ptr button = tgui::Button::create("Ok");
	button->setSize({"30%", "20%"});
	button->setPosition({"35%", "70%"});
	child->add(button);

	int VB = 0;
	button->connect("pressed", [&](){
		if ( BogieID->getText() != std::string("") ){
			if (SearchBogie(stoi(BogieID->getText().toAnsiString()))){
				VB = stoi(BogieID->getText().toAnsiString());
				child->close();
			}
			else {
				tgui::Label::Ptr WarningText = tgui::Label::create("Enter another bogie ID");
				WarningText->setPosition({"28%, 70%"});
				WarningText->setTextSize(18);
				WarningText->getRenderer()->setTextColor(sf::Color::Red);
				child->add(WarningText);
				sf::Clock clock1;
				while(clock1.getElapsedTime()<=sf::seconds(2.0f)){
					gui.draw();
					window.display();
				}
				BogieID->setText(""), BogieID->setFocused(true);
				gui.draw();
				window.display();
				child->remove(WarningText);
			}
		}
	});

	gui.draw();
	window.display();

	while( child->isFocused() ){
		sf::Event event = sf::Event();

		while (window.pollEvent(event))
			gui.handleEvent(event);

		window.clear(sf::Color::White);
		gui.draw();
		window.display();
	}

	int x = SearchBogie(VB);
	if (x == 1) {
		if (TBogies > 1) {

			Bogie *temp;
			temp = new Bogie[TBogies];

			for (int i = 0; i < TBogies; i++) {
				temp[i].BogieCopy(Bogies[i]);
			}

			for (int i = 0; i < TBogies; i++) {
				if (Bogies[i].GetID() == VB) {
					int j = i;
					for (; j < TBogies; j++) {
						if (j != TBogies - 1) {
							temp[j].BogieCopy(Bogies[j + 1]);
						}
					}
					break;
				}
			}

			delete[] Bogies;
			Bogies = new Bogie[TBogies - 1];

			for (int i = 0; i < TBogies - 1; i++) {
				Bogies[i].BogieCopy(temp[i]);
			}
			TBogies--;

			delete[] temp;
			temp = nullptr;

		}
		else {
			delete[] Bogies;
			Bogies = nullptr;

			TBogies--;
		}
	}
}

void Train::printTrain() { //print only the Bogie_ID of all bogies
		if (Bogies != nullptr) {
			for (int i = 0; i < TBogies; i++) {
				cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
				cout << "Info of Bogie #" << i + 1 << ": \n";
				cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
				Bogies[i].Print();
			}
		}
		else {
			cout << "No Bogies are attached with the Train at the moment. \n";
			cout << "Please wait for the Train to get ready. \n";
		}
	}

bool Train::SearchBogie(int ID) {//search the particular bogie
		int Res = 0;
		if (Bogies != nullptr) {
			for (int i = 0; i < TBogies; i++) {
				if (Bogies[i].GetID() == ID) {
					cout << "The Bogie has been found. \n";
					Res = 1;
					return Res;
				}
				else {
					cout << "The Bogie was not found. \n";
				}
			}
		}
		cout << "No Bogies are attached with the Train at the moment. \n";
		cout << "Please wait for the Train to get ready. \n";

		return Res;
	}

void Train::ViewBogie() {
		int c;
		int VB;
		cout << "Do You want to search Bogie:- \n";
		cout << "1.ID \n";
		cout << "2.Bogie No \n";
		cout << "Enter Choice:";

		while (true) {
			cin >> c;
			system("CLS");

			if (c == 1) {
				cout << "Enter Bogie_ID: \n";
				cin >> VB;
				system("CLS");

				int x = SearchBogie(VB);

				if (x == 1) {
					for (int i = 0; i < TBogies; i++) {
						if (Bogies[i].GetID() == VB) {
							Bogies[i].Print();
							break;
						}
					}
				}
				else if (x == 0) {
					cout << "Bogie not found. \n";
				}

				break;
			}
			else if (c == 2) {
				cout << "Enter Bogie_No: \n";
				cin >> VB;
				system("CLS");

				Bogies[VB - 1].Print();

				break;
			}
			else {
				cout << "Option is not available. \n";
				cout << "Enter correct choice: \n";
			}
		}
	}

void Train::addPassengers() {
	int VB;
	cout << "Enter Bogie ID in which Passangers must be added:- \n";

	while (true) {
		cin >> VB;
		system("CLS");

		int x = SearchBogie(VB);

		if (x == 1) {
			for (int i = 0; i < TBogies; i++) {
				if (Bogies[i].GetID() == VB) {
					Bogies[i].AddNewPassengers();
					break;
				}
			}
			break;
		}
		else if (x == 0) {
			cout << "Bogie not found. \n";
		}
	}
}

void Train::removePassengers() {
	int VB;
	cout << "Enter Bogie ID in which Passangers must be added:- \n";

	while (true) {
		cin >> VB;
		system("CLS");

		int x = SearchBogie(VB);

		if (x == 1) {
			for (int i = 0; i < TBogies; i++) {
				if (Bogies[i].GetID() == VB) {
					Bogies[i].RemovePassengers();
					break;
				}
			}
			break;
		}
		else if (x == 0) {
			cout << "Bogie not found. \n";
		}
	}
}

void Train::viewPassengers() {
	int VB;
	char Name[30]{0};
	char NIC[20]{0};
	cout << "Enter Bogie ID in which the Passanger is present:- \n";

	while (true) {
		cin >> VB;
		system("CLS");

		int x = SearchBogie(VB);

		if (x == 1) {
			for (int i = 0; i < TBogies; i++) {
				if (Bogies[i].GetID() == VB) {
					int k=0;
					cout << "Enter Passanger's Name:- \n";
					cin.getline(Name,30,'\n');
					cout << "Enter Passanger's NIC:- \n";
					cin.getline(NIC,20,'\n');
					cout << "Is the Passanger an Adult or a Kid:- \n";
					cout << "1. Adult || 2. Kid:- \n";
					cin>>k;
					if(k==1) {
						for(int a=0;i<Bogies[i].GetAdultsNo();a++){
							Adult *AdulTs = reinterpret_cast<Adult *>(Bogies[i].GetAdultsP(a));	cout << endl;
							if(compare(AdulTs->GetName(), Name) && compare(AdulTs->GetNIC(), NIC)){
								AdulTs->printData();
							}
						}
					} else if (k==2){
						for(int j=0;i<Bogies[i].GetkidsNo();j++){
							kid *kiDs = reinterpret_cast<kid *>(Bogies[i].GetkidsP(j));	cout << endl;
							if(compare(kiDs->GetName(), Name) && compare(kiDs->GetB_form_number(), NIC)){
							kiDs->printData();
							}
						}
					}else{
						cout<<"Option Unavailable. \n";
					}
					break;
				}
			}
			break;
		}
		else if (x == 0) {
			cout << "Bogie not found. \n";
		}
	}
}

void Train::DataExtraction() {
	ifstream fin;

	fin.open("Test1.txt");
	fin >> TBogies;
	TrainMaker(TBogies);

	if ( TBogies != 0 ){
		std::string text;
		char ch;
		char name[30]{0};
		int age = 0;
		for ( int i = 0; i < TBogies; i++ ) {
			fin >> text;
			Bogies[i].SetID(std::stoi(text));
			fin >> text;
			Bogies[i].SetMaxPassengersNo(std::stoi(text));
			fin >> text;
			Bogies[i].SetMaxAdultsNo(std::stoi(text));
			fin >> text;
			Bogies[i].SetMaxkidsNo(std::stoi(text));
			fin >> text;
			Bogies[i].SetPassengersNo(std::stoi(text));
			fin >> text;
			Bogies[i].SetAdultsNo(std::stoi(text));
			Person **Adults = new Person *[Bogies[i].GetAdultsNo()];
			fin >> text;
			Bogies[i].SetkidsNo(std::stoi(text));
			Person **kids = new Person *[Bogies[i].GetkidsNo()];
			fin >> text;
			Bogies[i].SetfamilyName(text.data());

			for (int j = 0; j < Bogies[i].GetkidsNo(); j++) {
				fin.ignore(1,'\n');
				fin.getline(name, 30, '\n');
				kids[j] = new kid;
				kids[j]->SetName(name);
				fin >> age;
				kids[j]->SetAge(age);
				fin >> text;
				kids[j]->SetGender(text.data());
				fin >> text;
				kid *kiDs = reinterpret_cast<kid *>(kids[j]);
				kiDs->SetB_form_number(text.data());
			}

			for (int j = 0; j < Bogies[i].GetAdultsNo(); j++) {
				fin.ignore(1,'\n');
				fin.getline(name, 30, '\n');
				Adults[j] = new Adult;
				Adults[j]->SetName(name);
				fin >> age;
				Adults[j]->SetAge(age);
				fin >> text;
				Adults[j]->SetGender(text.data());
				Adult *AdulTs = reinterpret_cast<Adult *>(Adults[j]);
				fin >> text;
				AdulTs->SetNIC(text.data());
				fin >> text;
				AdulTs->SetQualification(text.data());
				fin >> text;
				AdulTs->SetOccupation(text.data());
			}
			Bogies[i].SetAdults(Adults);
			Bogies[i].Setkids(kids);
		}

	}
}

void Train::DataSaving() {
	ofstream fout;

	fout.open("Train SData.txt");
	if(!fout.is_open()){
		cout<<"Not Found"<<endl;
	}

	fout << TBogies << "\n";
	for (int i = 0; i < TBogies; i++) {
		fout << Bogies[i].GetID() << "\n";
		fout << Bogies[i].GetMaxPassengersNo() << "\n";
		fout << Bogies[i].GetMaxAdultsNo() << "\n";
		fout << Bogies[i].GetMaxkidsNo() << "\n";
		fout << Bogies[i].GetPassengersNo() << "\n";
		fout << Bogies[i].GetAdultsNo() << "\n";
		fout << Bogies[i].GetkidsNo() << "\n";
		if (Bogies[i].GetfamilyName() == nullptr) {
			fout << "0 \n";
		} else if (Bogies[i].GetfamilyName() != nullptr) {
			char *temp = Bogies[i].GetfamilyName();
			fout << temp << "\n";
		}

		for (int j = 0; j < Bogies[i].GetkidsNo(); j++) {
			kid *kiDs = reinterpret_cast<kid *>(Bogies[i].GetkidsP(j));
			if (kiDs->GetName() != nullptr) {
				fout << kiDs->GetName() << "\n" << kiDs->GetAge() << "\n" << kiDs->GetGender() << "\n"
				     << kiDs->GetB_form_number() << "\n";
			}
		}

		for (int j = 0; j < Bogies[i].GetAdultsNo(); j++) {
			Adult *AdulTs = reinterpret_cast<Adult *>(Bogies[i].GetAdultsP(j));
			if (AdulTs->GetName() != nullptr) {
				fout << AdulTs->GetName() << "\n" << AdulTs->GetAge() << "\n" << AdulTs->GetGender() << "\n"
				     << AdulTs->GetNIC() << "\n" << AdulTs->GetQualification() << "\n" << AdulTs->GetOccupation()
				     << "\n";
			}
		}
	}
	fout << "~ \n";
	fout << endl;
}

void Train::RecordSaving() {
	ofstream fout;

	fout.open("Train Records.txt");
	fout << TBogies << "\n";
	if(TBogies!=0) {
		fout << engine->GetNext() << "\n";

		for (int i = 0; i < TBogies; i++) {
			fout << "Info of Bogie #" << i + 1 << ": \n";
			fout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
			fout << "(Bogie ID: " << Bogies[i].GetID() << ") \n";
			fout << "(Next: " << Bogies[i].GetNext() << ") \n";
			fout << "(Total Passangers: " << Bogies[i].GetPassengersNo() << ") \n";
			fout << "(Total Adults: " << Bogies[i].GetAdultsNo() << ") \n";
			fout << "(Total kids: " << Bogies[i].GetkidsNo() << ") \n";

			if (Bogies[i].GetfamilyName() != nullptr) {
				char *temp = Bogies[i].GetfamilyName();
				fout << "(FamilyName: " << temp << ") \n";
			}
			fout << "List of All Kids present in the Bogie: \n";
			fout << "_____________________________________ \n";
			if (Bogies[i].GetkidsNo() == 0) {
				fout << ".......................................................................................... \n";
				fout << "No kids found in the Bogie. \n";
				fout << ".......................................................................................... \n";

			}

			for (int j = 0; j < Bogies[i].GetkidsNo(); j++) {
				kid *kiDs = reinterpret_cast<kid *>(Bogies[i].GetkidsP(j));
				fout << ".......................................................................................... \n";
				if (kiDs->GetName() != nullptr) {
					fout << "( Name: " << kiDs->GetName() << ", Age: " << kiDs->GetAge() << ", Gender: "
					     << kiDs->GetGender() << " ) \n";
					fout << "( B_form_number: " << kiDs->GetB_form_number() << " ) \n";

				} else {
					fout << "No data found." << endl;
				}
				fout << ".......................................................................................... \n";
			}

			fout << "List of All Adults present in the Bogie: \n";
			fout << "_______________________________________ \n";
			if (Bogies[i].GetAdultsNo() == 0) {
				fout << ".......................................................................................... \n";
				fout << "No Adults found in the Bogie. \n";
				fout << ".......................................................................................... \n";

			}

			for (int j = 0; j < Bogies[i].GetAdultsNo(); j++) {
				Adult *AdulTs = reinterpret_cast<Adult *>(Bogies[i].GetAdultsP(j));
				fout << ".......................................................................................... \n";
				if (AdulTs->GetName() != nullptr) {
					fout << "( Name: " << AdulTs->GetName() << ", Age: " << AdulTs->GetAge() << ", Gender: "
					     << AdulTs->GetGender() << " ) \n";
					fout << "( NIC: " << AdulTs->GetNIC() << ", Qualification: " << AdulTs->GetQualification()
					     << ", Occupation: " << AdulTs->GetOccupation() << " ) \n";
				} else {
					fout << "No data found." << endl;
				}
				fout << ".......................................................................................... \n";
			}
		}
	}
	else{
			fout<< "No data found. \n" ;
		}
	fout << endl;
}

Train::~Train() {
	if (Bogies != nullptr) {
		delete[] Bogies;
		Bogies = nullptr;
	}
}


