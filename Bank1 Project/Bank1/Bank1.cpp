#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const string FileName = "Clients.txt";

void ShowMainMenu();

enum enMenuOption {Show = 1 , Add = 2 , Del = 3 , Upd = 4 , Find = 5 , Exit = 6};

struct sClients {

	string AccountName;
	string PinCode;
	string ClientName;
	string Phone;
	double balance = 0;
	bool Mark = false;

};

/*Show Client*/

vector <string> SplitSentence(string Line , string Superator) {

	vector <string> Words;

	short pos = 0;
	string Word;

	while ((pos = Line.find(Superator)) != std::string::npos) {

		Word = Line.substr(0, pos);

		if (Word != "") {

			Words.push_back(Word);

		}


		Line.erase(0, pos + Superator.length());


	}

	if (Line != "") {

		Words.push_back(Line);

	}

	return Words;

}

sClients LineToRecord(string Line , string Superator) {

	sClients Client;

	vector <string> Words = SplitSentence(Line, Superator);

	Client.AccountName = Words[0];
	Client.PinCode = Words[1];
	Client.ClientName = Words[2];
	Client.Phone = Words[3];
	Client.balance = stod(Words[4]);

	return Client;

}

vector <sClients> LoadDataInVector(string Superator) {

	vector <sClients> vsClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		string Line;
		sClients Client;

		while (getline(MyFile, Line)) {

			Client = LineToRecord(Line, Superator);

			vsClients.push_back(Client);

		}

		MyFile.close();
	}

	return vsClients;
}

void PrintHeader(vector <sClients>& vsClients) {

	cout << "\n                                                Client List (" << vsClients.size() << ") Client(s).\n";



}

void ClientList() {

	string superator = "#//#";
	vector <sClients> vsClients = LoadDataInVector(superator);
	
	PrintHeader(vsClients);

	cout << "____________________________________________________________________________________________________________________\n\n";
	cout << "|  " << setw(15) << left << "Account Number" << " |  " << setw(10) << left << "Pin Code" << " |  " 
		<< setw(40) << left << "Client Name" << " |  " << setw(12) << left << "Phone" << " |  " << setw(10) << left << "Balance";

	cout << "\n____________________________________________________________________________________________________________________\n\n";



	for (sClients& Client : vsClients) {


		cout << "|  " << setw(15) << left << Client.AccountName << " |  " << setw(10) << left << Client.PinCode << " |  "
			<< setw(40) << left << Client.ClientName << " |  " << setw(12) << left << Client.Phone << " |  " << setw(10) << left << Client.balance << endl;


	}

	cout << "\n\n____________________________________________________________________________________________________________________\n\n";

}


/*Add New Client */

bool CheckAccountNumber(vector <sClients>& vsClients, string AccountNumber) {

	for (sClients& C : vsClients) {

		if (C.AccountName == AccountNumber) {

			return false;

		}


	}

	return true;


}

sClients Client(vector <sClients>& vsClients) {

	sClients Client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountName);

	while (!(CheckAccountNumber(vsClients, Client.AccountName))) {

		cout << "\n\nClient with [" << Client.AccountName << "] already exists, Enter another Account Number ? ";
		getline(cin >> ws, Client.AccountName);

	}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.ClientName);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.balance;

	return Client;

}

string RecordToLine(sClients& Client, string superator) {

	string Line = "";

	Line += Client.AccountName + superator;
	Line += Client.PinCode + superator;
	Line += Client.ClientName + superator;
	Line += Client.Phone + superator;
	Line += to_string(Client.balance);

	return Line;
}

void AddClientToFile(string Line) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);


	if (MyFile.is_open()) {

		MyFile << Line << endl;


		MyFile.close();
	}
}

void AddClient(vector <sClients>& vsClients, string superator) {


	sClients C;
	C = Client(vsClients);
	vsClients.push_back(C);

	AddClientToFile(RecordToLine(C, superator));

}

void AddClients() {

	string superator = "#//#";
	vector <sClients> vsClients = LoadDataInVector(superator);

	cout << "\n--------------------------------------------\n";
	cout << "            Add New Clients Screen";
	cout << "\n--------------------------------------------\n";
	cout << "Adding New Client:\n\n";

	char Ask = 'n';
	do {

		AddClient(vsClients, superator);

		cout << "\n\nClient Added Successfully, do you want to add more Clients? Y/N?";
		cin >> Ask;

	} while (toupper(Ask) == 'Y');

}

void PrintClient(sClients& Client) {

	cout << "\nAccount Number : " << Client.AccountName;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nClient Name : " << Client.ClientName;
	cout << "\nPhoneNumber : " << Client.Phone;
	cout << "\nAccountBalance : " << Client.balance;

}

/*Delete Client*/

bool SearchClientByAccountNumber(vector <sClients>& vsClients, string AccountNumber , sClients& client) {

	for (sClients& C : vsClients) {

		if (AccountNumber == C.AccountName) {

			client = C;
			return true;
		}
	}

	return false;

}

bool MarkTheUSerforDelte(vector <sClients>& vsClients , string AccountNumber) {

	for (sClients& Client : vsClients) {

		if (Client.AccountName == AccountNumber) {

			Client.Mark = true;
			return true;
		}

	}

	return false;

}

vector <sClients> SaveClientsinFile(vector <sClients>& vsClients , string superator) {

	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		string Line;

		for (sClients& client : vsClients) {

			if (client.Mark == false) {

				Line = RecordToLine(client, superator);
				MyFile << Line << endl;

			}

		}
		MyFile.close();
	}

	return vsClients;
}

bool DeleteUserFromFile() {

	string superator = "#//#";
	sClients client;
	vector <sClients> vsClients = LoadDataInVector(superator);

	cout << "\n-----------------------------------------------------\n";
	cout << "                 Delete Client Screen";
	cout << "\n-----------------------------------------------------\n";
	
	
	char Ask = 'n';
	string AccountNumber = "";
	cout << "\nPlease Enter Account Number ? ";
	cin >> AccountNumber;

	if (SearchClientByAccountNumber(vsClients , AccountNumber, client)) {

		cout << "\nthe following are the client details : \n";
		cout << "----------------------------------";
		PrintClient(client);
		cout << "\n---------------------------------\n";

		cout << "\n\nAre You sure you want delete this user ? Y/N ? ";
		cin >> Ask;

		if (toupper(Ask) == 'Y') {

			MarkTheUSerforDelte(vsClients, AccountNumber);
			SaveClientsinFile(vsClients, superator);
			
			vsClients = LoadDataInVector(superator);

			cout << "\n\nClient Deleted Successfully.\n";
			return true;
		}

	}
	else {

		cout << "\n\nClient With Number (" << AccountNumber << ") is Not Found! ";
		return false;
	}

}

/*Update Client Info*/

sClients ChangeClientRecord(string AccNumber) {

	sClients Client;

	Client.AccountName = AccNumber;

	cout << "Enter Pin Code? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.ClientName);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.balance;

	return Client;
}

bool UpdateUserinFile() {

	string superator = "#//#";
	sClients client;
	vector <sClients> vsClients = LoadDataInVector(superator);

	cout << "\n-----------------------------------------------------\n";
	cout << "                 Update Client Screen";
	cout << "\n-----------------------------------------------------\n";


	char Ask = 'n';
	string AccountNumber = "";
	cout << "\n\nPlease Enter Account Number ? ";
	cin >> AccountNumber;

	if (SearchClientByAccountNumber(vsClients, AccountNumber, client)) {

		cout << "\nthe following are the client details : \n";
		cout << "----------------------------------";
		PrintClient(client);
		cout << "\n---------------------------------\n";

		cout << "\n\nAre You sure you want delete this user ? Y/N ? ";
		cin >> Ask;

		if (toupper(Ask) == 'Y') {

			for (sClients& C : vsClients) {
			
				if (C.AccountName == AccountNumber) {

					sClients Client = ChangeClientRecord(AccountNumber);
					C = Client;
					break;
				}
			
			}

			SaveClientsinFile(vsClients, superator);

			vsClients = LoadDataInVector(superator);

			cout << "\n\nClient Deleted Successfully.\n";

			
			return true;
		}

	}
	else {

		cout << "\n\nClient With Number (" << AccountNumber << ") is Not Found! ";
		return false;
	}




}

/*Find User*/

void FindUser() {

	string superator = "#//#";
	sClients client;
	vector <sClients> vsClients = LoadDataInVector(superator);

	cout << "\n-----------------------------------------------------\n";
	cout << "                 Find Client Screen";
	cout << "\n-----------------------------------------------------\n";


	string AccountNumber;
	cout << "\n\nPlease Enter Account Number ? ";
	cin >> AccountNumber;

	if (SearchClientByAccountNumber(vsClients, AccountNumber, client)) {

		cout << "\nthe following are the client details : \n";
		cout << "----------------------------------";
		PrintClient(client);
		cout << "\n---------------------------------\n";

	}
	else {

		cout << "\n\nClient With Number (" << AccountNumber << ") is Not Found! ";

	}



}

/*Exit FUNCTION*/

void exit() {


	cout << "\n-----------------------------------------------------\n";
	cout << "                 End Program";
	cout << "\n-----------------------------------------------------\n";



}

/*Chec User Sel */

void GoBackToShowMainMenu() {

	cout << "\n\nPress any key to go back to Main Menu...";

	system("pause>0");

	ShowMainMenu();
}

void PerfromShowMainMenueOption(enMenuOption ShowMainMenuOption) {

	
	switch (ShowMainMenuOption) {

	case enMenuOption::Show:
		system("cls");
		ClientList();
		GoBackToShowMainMenu();
		break;

	case enMenuOption::Add:

		system("cls");
		AddClients();
		GoBackToShowMainMenu();
		break;

	case enMenuOption::Del:

		system("cls");
		DeleteUserFromFile();
		GoBackToShowMainMenu();
		break;

	case enMenuOption::Upd:

		system("cls");
		UpdateUserinFile();
		GoBackToShowMainMenu();
		break;

	case enMenuOption::Find:

		system("cls");
		FindUser();
		GoBackToShowMainMenu();
		break;

	case enMenuOption::Exit:

		system("cls");
		exit();
		break;
	}
}

short ReadShowMainMenuOption() {

	short Choose;

	cout << "Choose What do you want to do? [1 to 6] ? ";
	cin >> Choose;

	return Choose;

}

void ShowMainMenu() {

	system("cls");


	cout << "===============================================\n";
	cout << "                Main Menue Screen\n";
	cout << "===============================================\n";
	cout << "        [1] Show Client List.\n";
	cout << "        [2] Add New Client.\n";
	cout << "        [3] Delete Client.\n";
	cout << "        [4] Update Client Info.\n";
	cout << "        [5] Find Client.\n";
	cout << "        [6] Exit.\n";
	cout << "===============================================\n";

	PerfromShowMainMenueOption((enMenuOption)ReadShowMainMenuOption());

}

int main() {
	
	ShowMainMenu();
	system("pause>0");
	return 0;
}
