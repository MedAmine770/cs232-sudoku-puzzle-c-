#include <iostream>
#include <algorithm>

using namespace std;

//constants
const int COLSIZE = 9; 
const int ROWSIZE = 9;


//function prototypes 
void userInputFill(int arr[ROWSIZE][COLSIZE], int userPar); //switch all the numbers to userPar(row and col)
void resultPuzzle(int arr[ROWSIZE][COLSIZE], int userPar);
void printArray(int arr[ROWSIZE][COLSIZE]);

//global declarations 
int userInput; 
int puzzleContent[ROWSIZE][COLSIZE] = { {5,3,4,0,7,0,9,1,2},
										{6,0,0,1,9,5,0,0,0},
										{0,9,8,0,0,0,0,6,0},
										{8,0,0,0,6,0,0,0,3},
										{4,0,0,8,0,3,0,0,1},
										{7,0,0,0,2,0,0,0,6},
										{0,6,0,0,0,0,2,8,4},
										{2,8,7,4,1,9,0,0,5},
										{3,4,5,0,8,0,0,7,9},
};
int parallelArr[ROWSIZE][COLSIZE] = { {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
									  {0,0,0,0,0,0,0,0,0},
};

int main() { 
	cout << "Enter a number to hash: ";
	cin >> userInput;
	cout << endl;

	//fillingArray(puzzleContent);
	cout << "Cross hatch before:" << endl;
	printArray(parallelArr);
	cout << "Puzzle content:" << endl;
	printArray(puzzleContent);

	userInputFill(puzzleContent, userInput);
	resultPuzzle(puzzleContent, userInput);

	cout << "Cross hatch after:" << endl;
	printArray(puzzleContent);

	return 0;
}

void userInputFill(int arr[ROWSIZE][COLSIZE], int userPar) {
	bool assignedRow[ROWSIZE] = { false };
	bool assignedCol[COLSIZE] = { false };

	// Identify rows and columns that should be marked
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			if (userPar == arr[i][j]) {
				assignedRow[i] = true;
				assignedCol[j] = true;
			}
		}
	}

	// Assign userInput in rows and columns marked as true
	for (int i = 0; i < ROWSIZE; i++) {
		if (assignedRow[i]) {
			for (int j = 0; j < COLSIZE; j++) {
				arr[i][j] = userInput; // Fill the whole row
			}
		}
	}

	for (int j = 0; j < COLSIZE; j++) {
		if (assignedCol[j]) {
			for (int i = 0; i < ROWSIZE; i++) {
				arr[i][j] = userInput; // Fill the whole column
			}
		}
	}
}


void resultPuzzle(int arr[ROWSIZE][COLSIZE], int userPar) {
	for (int i = 0; i < ROWSIZE; i++)
	{
		for (int j = 0; j < COLSIZE; j++)
		{
			if (arr[i][j] == userPar)
				arr[i][j] = 1; 
			else 
				arr[i][j] = 0;
		}
	}
	cout << arr[ROWSIZE][COLSIZE]; 
}

void printArray(int arr[ROWSIZE][COLSIZE]) {
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

