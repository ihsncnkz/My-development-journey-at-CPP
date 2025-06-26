#include <iostream>

using namespace std;

int main() {

	// Video 8.45
	
	int array[5];
	array[0] =  12;
	array[1] = 20;
	array[2] = 8;
	array[3] = 45;
	array[4] = 18;

	// cout << array[4] << endl;

	for (int i = 0; i < 5; i++) {
		cout << array[i] << endl;
	}

	cout << "Please, Enter the first index number of array: ";
	cin >> array[1];

	cout << "Secend state" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array[i] << endl;
	}
	

	// Video 8.46
	
	int arr[] = {21, 25, 27};

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	string seasons[] = { "Spring", "Summer", "Autumn", "Winter" };

	for (int i = 0; i < 4; i++) {
		cout << i+1 << ". Seasons: " << seasons[i] << endl;
	}
	cout << endl;

	double arr2[] = { 21.2, 25.8, 27.6, 33 };

	for (int i = 0; i < 4; i++) {
		cout << arr2[i] << endl;
	}
	cout << endl;
	

	// Video 8.47
	
	double quizNotes[4];
	double sumQuizNote = 0.0, avrQuizNote;

	for (int i = 0; i < 4; i++) {
		cout << "Please Enter the " << i + 1 << ". quiz note: ";
		cin >> quizNotes[i];
		sumQuizNote = (double)sumQuizNote + quizNotes[i];
	}

	avrQuizNote = sumQuizNote / 4.0;

	cout << "GPA: " << avrQuizNote << endl;
	

	// Video 8.48
	
	const int size = 4; //It is a must-have variable when writing professional code because when the number of exams changes, we can change the number of exams in the code using this code.
	double quizNotes[size];
	double sumQuizNote = 0.0, avrQuizNote;

	for (int i = 0; i < size; i++) {
		cout << "Please Enter the " << i + 1 << ". quiz note: ";
		cin >> quizNotes[i];
		sumQuizNote = (double)sumQuizNote + quizNotes[i];
	}

	avrQuizNote = (double) sumQuizNote / size;

	cout << "GPA: " << avrQuizNote << endl;
	

	// Video 9.49
	
	const int size = 4;
	double quizNotes[size];
	double quizPercentage[size] = { 0.15, 0.15, 0.30, 0.40 };
	double sumQuizNote = 0, avrQuizNote;

	for (int i = 0; i < size; i++) {
		cout << "Please Enter the " << i + 1 << ". quiz note: ";
		cin >> quizNotes[i];
		sumQuizNote = (double)sumQuizNote + (quizNotes[i] * quizPercentage[i]);
	}

	cout << "GPA: " << sumQuizNote << endl;
	

	// Video 9.50
	
	int arr[2][3] = { {8, 17, 25}, {12, 40, 35} };
	//cout << arr[0][0] << endl;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	

	// Video 9.52
	
	const int size1 = 3;
	const int size2 = 2;

	int arr[size1][size2], arr2[size1][size2], sumArrays[size1][size2] = {0};

	cout << "First array value getter" << endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << "Please, enter the [" << i << "][" << j << "] value: ";
			cin >> arr[i][j];
		}
	}

	cout << "Second array value getter" << endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << "Please, enter the [" << i << "][" << j << "] value: ";
			cin >> arr2[i][j];
		}
	}

	
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			sumArrays[i][j] = arr[i][j] + arr2[i][j];
		}
	}

	cout << "Sum of Array" << endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << sumArrays[i][j] << " ";
		}
		cout << endl;
	}
	

	// Video 9.53

	const int size1 = 3;
	const int size2 = 2;

	int arr[size1][size2], arr2[size1][size2], sumArrays[size1][size2] = { 0 };

	cout << "First array value getter" << endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << "Please, enter the [" << i << "][" << j << "] value: ";
			cin >> arr[i][j];
		}
	}

	cout << "Second array value getter" << endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << "Please, enter the [" << i << "][" << j << "] value: ";
			cin >> arr2[i][j];
		}
	}

	cout << "Sum of Array" << endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			sumArrays[i][j] = arr[i][j] + arr2[i][j];
			cout << sumArrays[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}