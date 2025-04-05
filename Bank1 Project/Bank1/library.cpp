


//int MaxNumFromArray(int arr[100], int Length) {
//
//	int Max = 0;
//
//	for (int i = 0; i < Length; i++) {
//
//		if (arr[i] > Max) {
//			Max = arr[i];
//		}
//
//	}
//
//	return Max;
//
//}
//
//int MinNumFromArray(int arr[100], int Length) {
//
//	int Min = arr[0];
//
//	for (int i = 0; i < Length; i++) {
//
//		
//		if (arr[i] <  Min) {
//			Min = arr[i];
//		}
//
//	}
//
//	return Min;
//
//}
//
//int SumOfArray(int arr[100], int Length) {
//
//	int Sum = 0;
//
//	for (int i = 0; i < Length; i++) {
//		
//		Sum += arr[i];
//	}
//
//	return Sum;
//
//}
//
//float AverageOfArray(int arr[100], int Length) {
//
//	 return float(SumOfArray(arr, Length)) / Length;
// 
// 
// int RandomNumber(int From , int To) {
//int RandNum = rand() % (To - From + 1) + From;
//return RandNum;
//
//}
// void ShuffleArray(int arr[100] , int Length) {

//for (int i = 0; i < Length; i++) {
//
//	Swap(arr[RandomNumber(0, Length - 1)], arr[RandomNumber(0, Length - 1)]);
//
//}
//
//}
// 
// 
// 
//}

/*
/*

string randWord(int Size) {

	string word;

	for (int i = 0; i < Size; i++) {

		word += char(RandomNumber(65, 90));
	}
	return word;
}

string Keys(int Size) {

	string Key = "";

	for (int i = 0; i < 3; i++) {

		Key += randWord(Size) + "-";
	}

	Key += randWord(Size);

	return Key;
}


void CopyArray(int Copyarr[100], int arr[100], int Length) {

	for (int i = 0; i < Length; i++) {

		Copyarr[i] = arr[Length - 1 - i];

	}

}

////////////////

short SearchByIndex(int arr[100], int Length , int& Search) {

	for (int i = 0; i < Length; i++) {

		if (Search == arr[i]) {

			return 1;
		}

	}

	return -1;

}

bool CheckNumInArray(int number , int Search) {

	if (number != -1) {

		return true;

	}
	return false;

}


*/


/*

int GetNumber(string message) {

	int num;

	do {

		cout << message << endl;
		cin >> num;
	} while (num < 0);

	return num;
}

short SearchByIndex(int arr[100], int Length, int& Search) {

	for (int i = 0; i < Length; i++) {

		if (Search == arr[i]) {

			return i;
		}

	}

	return -1;

}

bool IsNumberInArray(int Search, int arr[100], int Length) {

	return SearchByIndex(arr, Length, Search) != -1;
}

void PrintArray(int arr[100], int Length) {

	for (int i = 0; i < Length; i++) {
		cout << arr[i] << " ";
	}

}

void AddArrayElements(int number, int arr[100], int& Length) {

	arr[Length] = number;
	Length++;

}

void CopyArr(int arr[100], int copyarr[100] , int Length , int& CopyLength) {

	for (int i = 0; i < Length; i++) {

		if (!IsNumberInArray(arr[i] , copyarr , CopyLength)) {

			AddArrayElements(arr[i], copyarr, CopyLength);

		}

	}

}


*/


/*

int OddLength(int arr[100] , int Length) {

	int OddLength = 0;

	for (int i = 0; i < Length; i++) {

		if (arr[i] % 2 != 0) {
			OddLength++;
		}

	}
	return OddLength;
}

int EvenLength(int arr[100] , int Length) {

	int EvenLength = 0;

	for (int i = 0; i < Length; i++) {

		if (arr[i] % 2 == 0) {
			EvenLength++;
		}

	}
	return EvenLength;
}

int PositiveLength(int arr[100] , int Length) {

	int Positive = 0;

	for (int i = 0; i < Length; i++) {

		if (arr[i] > 0) {
			Positive++;
		}

	}
	return Positive;
}


int NegativeLength(int arr[100] , int Length) {

	int Negative = 0;

	for (int i = 0; i < Length; i++) {

		if (arr[i] < 0) {
			Negative++;
		}

	}
	return Negative;
}



*/