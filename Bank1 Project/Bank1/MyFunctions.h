#pragma once

#include <iostream>
#include <string>


using namespace std;

namespace MyFunctions {

	string Sentence() {

		string sentence;

		cout << "Enter The Sentence : ";
		getline(cin, sentence);
		return sentence;
	}

	void ToUpper(string sent) {

		for (int i = 0; i < sent.length(); i++) {

			if (sent[i] != ' ' && int(sent[i]) >= 97 && int(sent[i]) <= 122) {

				sent[i] = char(int(sent[i]) - 32);

			}

		}

		cout << endl << sent << endl;
	}

	string ToLower(string sent) {

		string lower;

		for (int i = 0; i < sent.length(); i++) {

			if (sent[i] != ' ' && int(sent[i]) >= 65 && int(sent[i]) <= 90) {

				lower += char(int(sent[i]) + 32);

			}
			else {

				lower += char(int(sent[i]));
			}



		}
		return lower;
	}

	char GetCharacter() {

		char Ch;

		cout << "Enter The Character : ";
		cin >> Ch;

		return Ch;
	}

	char InvertLetterCase(char Ch) {

		return isupper(Ch) ? tolower(Ch) : toupper(Ch);

	}

	string InvertString(string Sentence) {

		for (int i = 0; i < Sentence.length();i++) {

			Sentence[i] = MyFunctions::InvertLetterCase(Sentence[i]);

		}
		return Sentence;
	}

	short CountsmalLtters(string Sentence) {
		short Count = 0;
		for (int i = 0; i < Sentence.length(); i++) {
			if (islower(Sentence[i])) {
				Count++;
			}
		}
		return Count;
	}

	short CountCapitalLtters(string Sentence) {
		short Count = 0;
		for (int i = 0; i < Sentence.length(); i++) {
			if (isupper(Sentence[i])) {
				Count++;
			}
		}
		return Count;
	}

	short LetterCountSensetive(string Sentence, char Letter) {

		short Counter = 0;

		for (int i = 0; i < Sentence.length();i++) {

			if (Sentence[i] == Letter) {

				Counter++;
			}

		}

		return Counter;

	} // Count sensetive captital or Lower 

	short LetterCountInverst(string Sentence, char Letter, char Inverst) {

		short Counter = 0;
		for (int i = 0; i < Sentence.length();i++) {

			if (Sentence[i] == Letter || Sentence[i] == Inverst) {

				Counter++;
			}

		}

		return Counter;

	}

	bool CheckVoilChar(char Letter) {

		char voils[] = { 'a', 'e', 'i', 'o', 'u' };

		for (int i = 0; i < 6; i++) {

			if (tolower(Letter) == tolower(voils[i])) {

				return true;

			}

		}
		return false;

	}

	short CountVoils(string Sentence) {
		short Count = 0;
		for (int i = 0; i < Sentence.length();i++) {
			if (MyFunctions::CheckVoilChar(Sentence[i])) {
				Count++;
			}
		}
		return Count;
	}

	void PrintEachWordFromSentence(string Sentence) {

		string delim = " ";
		cout << "\nYour string words are: \n\n";
		short pos = 0;
		string Word;

		while ((pos = Sentence.find(delim)) != std::string::npos) {

			Word = Sentence.substr(0, pos);

			if (Word != "") {

				cout << Word << endl;
			}

			Sentence.erase(0, pos + delim.length());


		}

		if (Sentence != "") {

			cout << Sentence;

		}

	}

	short CountEachWordInString(string Sentence) {

		short count = 0;

		string delim = " ";
		cout << "\nYour string words are: \n\n";
		short pos = 0;
		string Word;

		while ((pos = Sentence.find(delim)) != std::string::npos) {

			Word = Sentence.substr(0, pos);

			if (Word != "") {

				count++;
			}

			Sentence.erase(0, pos + delim.length());


		}

		if (Sentence != "") {

			count++;

		}
		return count;
	}

	vector <string> SplitString(string Sentence, string Seperator) {

		vector <string> Words;

		short pos = 0;
		string Word;

		while ((pos = Sentence.find(Seperator)) != std::string::npos) {

			Word = Sentence.substr(0, pos);

			if (Word != "") {

				Words.push_back(Word);

			}

			Sentence.erase(0, pos + Seperator.length());

		}

		if (Sentence != "") {

			Words.push_back(Sentence);

		}

		return Words;

	}

	string TrimLeft(string Sentence) {

		for (short i = 0; i < Sentence.length(); i++) {

			if (Sentence[i] != ' ')

				return Sentence.substr(i, Sentence.length() - 1);

		}

		return "";

	}

	string TrimRight(string Sentence) {

		for (short i = Sentence.length() - 1; i >= 0; i--) {

			if (Sentence[i] != ' ')

				return Sentence.substr(0, i + 1);

		}

		return "";

	}

	string Trim(string& Sentence) {

		return TrimRight(TrimLeft(Sentence));

	}

	string joinString(vector <string > words, string Seperator) {

		string Sentence;


		for (string& word : words) {

			Sentence += word;

			if (word != words[words.size() - 1]) {

				Sentence += Seperator;


			}
		}

		return Sentence;

	}

	string reverseString(string Sentence) {
		vector <string> words;
		string StringReversed;
		string Seperator = " ";

		words = MyFunctions::SplitString(Sentence, " ");

		vector <string>::iterator iter = words.end();

		while (iter != words.begin()) {

			--iter;

			StringReversed += *iter + Seperator;
		}

		StringReversed = StringReversed.substr(0, StringReversed.length() - Seperator.length());

		return StringReversed;

	}

	string ReplaceString(string Sentence, string word, string NewWord) {

		short pos = Sentence.find(word);

		while (pos != std::string::npos) {

			Sentence.replace(pos, word.length(), NewWord);
			pos = Sentence.find(word);

		}
		return Sentence;
	}

	string ReplaceStringNotSensetive(string Sentence, string word, string NewWord) {

		vector <string> words = MyFunctions::SplitString(Sentence, " ");

		string newSentence;

		for (int i = 0; i < words.size(); i++) {

			if (MyFunctions::ToLower(words[i]) == MyFunctions::ToLower(word)) {

				newSentence += NewWord + " ";


			}
			else {

				newSentence += words[i] + " ";

			}


		}

		newSentence = newSentence.substr(0, newSentence.length() - 1);

		return newSentence;

	}

	string RemovePunctuations(string Sentence) {

		string NewSentence;

		for (int i = 0; i < Sentence.length(); i++) {

			if (!ispunct(Sentence[i])) {

				NewSentence += Sentence[i];

			}


		}

		return NewSentence;

	}

	float ReadNumber(string message)
	{
		float Number;
		cout << message;
		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}

	struct sClients {

		string AccountNumber;
		string PinCode;
		string FullName;
		string PhoneNumber;
		float Balance = 0;

	};

	sClients FillInfos() {

		sClients Info;

		cout << "\nAdding New Client : \n";

		cout << "\nEnter Account Number : ";
		getline(cin >> ws, Info.AccountNumber);

		cout << "\nEnter PinCode : ";
		getline(cin, Info.PinCode);

		cout << "\nEnter Your FullName : ";
		getline(cin, Info.FullName);

		cout << "\nEnter Your PhoneNumber : ";
		getline(cin, Info.PhoneNumber);

		Info.Balance = ReadNumber("\nEnter Your Account Balance : ");

		return Info;
	}

	string RecordToLine(string Superator) {

		sClients Info = FillInfos();
		string Line = "";

		Line += Info.AccountNumber + Superator;
		Line += Info.PinCode + Superator;
		Line += Info.FullName + Superator;
		Line += Info.PhoneNumber + Superator;
		Line += to_string(Info.Balance);

		return Line;

	}

	void AddnewClient() {

		fstream MyFile;

		string Line = RecordToLine("#//#");
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << Line << endl;
			MyFile.close();

		}



	}

	void AddClients() {

		char Ask = 'Y';

		do {

			system("cls");
			AddnewClient();

			cout << "\n\nClient Added Successfully , do you want to add more clients? : ";
			cin >> Ask;

		} while (Ask == 'Y' || Ask == 'y');

	}

	struct sClients {

		string AccountNumber;
		string PinCode;
		string ClientName;
		string Phone;
		float Balance = 0;

	};

	void PrintHeader(short& Counter) {

		cout << "\n                                          Client List (" << Counter << ") Client(s).";

	}

	void Titles() {

		cout << "\n__________________________________________________________________________________________________________________\n\n";
		cout << "|  " << setw(15) << left << "Account Number" << " |  " << setw(10) << left << "Pin Code" << " |  " << setw(40) << left << "Client Name" << " |  " << setw(12) << left << "Phone" << " |  " << setw(10) << left << "Balance";
		cout << "\n__________________________________________________________________________________________________________________\n";

	}

	void PrintClientRecord(sClients& Info) {

		cout << "\n|  " << setw(15) << left << Info.AccountNumber << " |  " << setw(10) << left << Info.PinCode << " |  " << setw(40) << left << Info.ClientName << " |  " << setw(12) << left << Info.Phone << " |  " << setw(10) << left << Info.Balance;


	}

	vector <string> SplitString(string Sentence, string Seperator) {

		vector <string> Words;

		short pos = 0;
		string Word;

		while ((pos = Sentence.find(Seperator)) != std::string::npos) {

			Word = Sentence.substr(0, pos);

			if (Word != "") {

				Words.push_back(Word);

			}

			Sentence.erase(0, pos + Seperator.length());

		}

		if (Sentence != "") {

			Words.push_back(Sentence);

		}

		return Words;

	}

	sClients ConvertLinetoRecord(string Line) {

		sClients Info;
		vector <string> Words;

		Words = SplitString(Line, "#//#");

		Info.AccountNumber = Words[0];
		Info.PinCode = Words[1];
		Info.ClientName = Words[2];
		Info.Phone = Words[3];
		Info.Balance = stod(Words[4]);

		return Info;
	}

	vector <sClients> LoadCleintsDataFromFile(string FileName) {

		vector <sClients> vClients;

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open()) {

			string Line;
			sClients Client;

			while (getline(MyFile, Line)) {

				Client = ConvertLinetoRecord(Line);
				vClients.push_back(Client);

			}


		}

		return vClients;

	}

	short NumberOfClients(string FileName) {

		short Counter = 0;

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				Counter++;

			}


		}
		return Counter;

	}

	void PrintAllClientsData() {

		vector <sClients> vsClients = LoadCleintsDataFromFile("Clients.txt");

		for (sClients Client : vsClients) {

			PrintClientRecord(Client);
		}

	}

	void ReadClients() {

		short Counter = NumberOfClients("Clients.txt");

		PrintHeader(Counter);

		Titles();

		PrintAllClientsData();

		cout << "\n\n__________________________________________________________________________________________________________________";

	}

	/*Find User By her Account Number*/


	struct sClients {

		string AccountNumber;
		string PinCode;
		string ClientName;
		string Phone;
		float Balance = 0;

	};

	vector <string> SplitString(string Sentence, string Seperator) {

		vector <string> Words;

		short pos = 0;
		string Word;

		while ((pos = Sentence.find(Seperator)) != std::string::npos) {

			Word = Sentence.substr(0, pos);

			if (Word != "") {

				Words.push_back(Word);

			}

			Sentence.erase(0, pos + Seperator.length());

		}

		if (Sentence != "") {

			Words.push_back(Sentence);

		}

		return Words;

	}

	sClients ConvertLinetoRecord(string Line) {

		sClients Info;
		vector <string> Words;

		Words = SplitString(Line, "#//#");

		Info.AccountNumber = Words[0];
		Info.PinCode = Words[1];
		Info.ClientName = Words[2];
		Info.Phone = Words[3];
		Info.Balance = stod(Words[4]);

		return Info;
	}

	vector <sClients> LoadCleintsDataFromFile(string FileName) {

		vector <sClients> vClients;

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open()) {

			string Line;
			sClients Client;

			while (getline(MyFile, Line)) {

				Client = ConvertLinetoRecord(Line);
				vClients.push_back(Client);

			}


		}

		return vClients;

	}

	void PrintCardClient(sClients& Client) {

		cout << "\n\nThe following Are the client Details : \n\n";

		cout << "Account Number : " << Client.AccountNumber << endl;
		cout << "Pin Code : " << Client.PinCode << endl;
		cout << "Name : " << Client.ClientName << endl;
		cout << "Phone : " << Client.Phone << endl;
		cout << "Balance : " << Client.Balance;


	}

	bool SearchClientByAccountNumber(string AccNumber, sClients& Client) {


		vector <sClients> vsClients = LoadCleintsDataFromFile(FileName);

		for (sClients C : vsClients) {

			if (C.AccountNumber == AccNumber) {

				Client = C;
				return true;

			}

		}

		return false;

	}

	string ReadAccNumber() {

		string AccNumber = "";
		cout << "Please Enter AccountNumber ? : ";
		cin >> AccNumber;

		return AccNumber;
	}

	int main() {

		string AccNumber = ReadAccNumber();

		sClients Client;

		if (SearchClientByAccountNumber(AccNumber, Client)) {

			PrintCardClient(Client);


		}
		else {

			cout << "\nClient with Account Number (" << AccNumber << ") is Not Found!";

		}


		system("pause>0");

		return 0;
	}

	/*Delete The User*/


	bool MarkUserForDelete(string AccNumber, vector <sClients>& vsClients) {

		for (sClients& C : vsClients) {

			if (C.AccountNumber == AccNumber) {

				C.Mark = true;
				return true;

			}


		}

		return false;

	}

	vector <sClients> SaveCleintsDataToFile(string FileName, vector <sClients>& vsClients) {

		fstream MyFile;

		MyFile.open(FileName, ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (sClients& Client : vsClients) {

				if (Client.Mark == false) {

					DataLine = RecordToLine("#//#", Client);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

		return vsClients;

	}

	bool DeleteUserFromFile(string AccNumber, vector <sClients>& vsClients) {

		sClients Client;

		char Answare = 'n';

		if (SearchClientByAccountNumber(AccNumber, Client, vsClients)) {

			PrintCardClient(Client);

			cout << "\n\nAre you sure you wantd delete the user : ? (Y / N)";
			cin >> Answare;

			if (Answare == 'Y' || Answare == 'y') {

				MarkUserForDelete(AccNumber, vsClients);
				SaveCleintsDataToFile(FileName, vsClients);

				vsClients = LoadCleintsDataFromFile(FileName);

				cout << "\n\nThe User is Deleted Succussfuly :) ";
				return true;
			}


		}
		else {

			cout << "\n\nClient With Number (" << AccNumber << ") is not Found :(";
			return false;

		}


	}


	/*Update The User*/

	sClients ChangeClientRecord(string AccNumber) {

		sClients Client;

		Client.AccountNumber = AccNumber;

		cout << "\n\nEnter PinCode : ";
		getline(cin >> ws, Client.PinCode);

		cout << "\nEnter Name : ";
		getline(cin, Client.ClientName);

		cout << "\nEnter Phone : ";
		getline(cin, Client.Phone);

		cout << "\nEnter Account Balance : ";
		cin >> Client.Balance;

		return Client;

	}

	vector <sClients> SaveCleintsDataToFile(string FileName, vector <sClients>& vsClients) {

		fstream MyFile;
		sClients UpdateInfos;

		MyFile.open(FileName, ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (sClients& Client : vsClients) {

				if (Client.Mark == false) {

					DataLine = RecordToLine("#//#", Client);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

		return vsClients;

	}

	bool UpdateUserInFile(string AccNumber, vector <sClients>& vsClients) {

		sClients Client;

		char Answare = 'n';

		if (SearchClientByAccountNumber(AccNumber, Client, vsClients)) {

			PrintCardClient(Client);

			cout << "\n\nDo you want Update the user :  (Y / N) ? ";
			cin >> Answare;

			if (Answare == 'Y' || Answare == 'y') {

				for (sClients& C : vsClients) {

					if (C.AccountNumber == AccNumber) {

						C = ChangeClientRecord(AccNumber);
						break;
					}


				}



				SaveCleintsDataToFile(FileName, vsClients);

				vsClients = LoadCleintsDataFromFile(FileName);

				cout << "\n\nThe User is Updated Succussfuly :) \n";
				return true;
			}


		}
		else {

			cout << "\n\nClient With Number (" << AccNumber << ") is not Found :(";
			return false;

		}


	}


//srand((unsigned)time(NULL));



	struct sClients {

		string AccountNumber;
		string PinCode;
		string ClientName;
		string Phone;
		float Balance = 0;
		bool Mark = false;

	};

	string RecordToLine(string Superator, sClients Info) {

		string Line = "";

		Line += Info.AccountNumber + Superator;
		Line += Info.PinCode + Superator;
		Line += Info.ClientName + Superator;
		Line += Info.Phone + Superator;
		Line += to_string(Info.Balance);

		return Line;

	}

	vector <string> SplitString(string Sentence, string Seperator) {

		vector <string> Words;

		short pos = 0;
		string Word;

		while ((pos = Sentence.find(Seperator)) != std::string::npos) {

			Word = Sentence.substr(0, pos);

			if (Word != "") {

				Words.push_back(Word);

			}

			Sentence.erase(0, pos + Seperator.length());

		}

		if (Sentence != "") {

			Words.push_back(Sentence);

		}

		return Words;

	}

	sClients ConvertLinetoRecord(string Line) {

		sClients Info;
		vector <string> Words;

		Words = SplitString(Line, "#//#");

		Info.AccountNumber = Words[0];
		Info.PinCode = Words[1];
		Info.ClientName = Words[2];
		Info.Phone = Words[3];
		Info.Balance = stod(Words[4]);

		return Info;
	}

	vector <sClients> LoadCleintsDataFromFile(string FileName) {

		vector <sClients> vClients;

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open()) {

			string Line;
			sClients Client;

			while (getline(MyFile, Line)) {

				Client = ConvertLinetoRecord(Line);
				vClients.push_back(Client);

			}


		}

		return vClients;

	}

	void PrintCardClient(sClients& Client) {

		cout << "\n\nThe following Are the client Details : \n\n";

		cout << "Account Number : " << Client.AccountNumber << endl;
		cout << "Pin Code : " << Client.PinCode << endl;
		cout << "Name : " << Client.ClientName << endl;
		cout << "Phone : " << Client.Phone << endl;
		cout << "Balance : " << Client.Balance;


	}

	bool SearchClientByAccountNumber(string AccNumber, sClients& Client, vector <sClients>& vsClients) {


		for (sClients C : vsClients) {

			if (C.AccountNumber == AccNumber) {

				Client = C;
				return true;

			}

		}

		return false;

	}

	string ReadAccNumber() {

		string AccNumber = "";
		cout << "Please Enter AccountNumber ? : ";
		cin >> AccNumber;

		return AccNumber;
	}

	sClients ChangeClientRecord(string AccNumber) {

		sClients Client;

		Client.AccountNumber = AccNumber;

		cout << "\n\nEnter PinCode : ";
		getline(cin >> ws, Client.PinCode);

		cout << "\nEnter Name : ";
		getline(cin, Client.ClientName);

		cout << "\nEnter Phone : ";
		getline(cin, Client.Phone);

		cout << "\nEnter Account Balance : ";
		cin >> Client.Balance;

		return Client;

	}

	vector <sClients> SaveCleintsDataToFile(string FileName, vector <sClients>& vsClients) {

		fstream MyFile;
		sClients UpdateInfos;

		MyFile.open(FileName, ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (sClients& Client : vsClients) {

				if (Client.Mark == false) {

					DataLine = RecordToLine("#//#", Client);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

		return vsClients;

	}

	bool UpdateUserInFile(string AccNumber, vector <sClients>& vsClients) {

		sClients Client;

		char Answare = 'n';

		if (SearchClientByAccountNumber(AccNumber, Client, vsClients)) {

			PrintCardClient(Client);

			cout << "\n\nDo you want Update the user :  (Y / N) ? ";
			cin >> Answare;

			if (Answare == 'Y' || Answare == 'y') {

				for (sClients& C : vsClients) {

					if (C.AccountNumber == AccNumber) {

						C = ChangeClientRecord(AccNumber);
						break;
					}


				}



				SaveCleintsDataToFile(FileName, vsClients);

				vsClients = LoadCleintsDataFromFile(FileName);

				cout << "\n\nThe User is Updated Succussfuly :) \n";
				return true;
			}


		}
		else {

			cout << "\n\nClient With Number (" << AccNumber << ") is not Found :(";
			return false;

		}


	}