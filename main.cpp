#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to add a student's result
void addResult() {
    ofstream file("results.txt", ios::app);
    string name, addno;
    float marks;

    system("cls");
    cout << "Enter student's name: ";
    cin >> name;
    cout << "Enter Admission number: ";
    cin >> addno;
    cout << "Enter marks: ";
    cin >> marks;

    file << name << " " << addno << " " << marks << "\n";
    cout << "Recorded Added!" << endl;
    system("pause");
    file.close();
}

// Function to display all results
void displayResults() {
    fstream file;
    string name, addno;
	float marks;
   
	system("cls");
	file.open("results.txt", ios::in);
	if (!file)
	{
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Student Name\t\tAdmission Number\t\tMarks" << endl;
		file >> name >> addno >> marks; 
		while(!file.eof()) {
			cout << name << "\t\t\t" << addno << "\t\t\t" << marks << endl; 
			file >> name >> addno >> marks;
		}
		system("pause");
		file.close();
	}
}

// Function to search a student's result
void searchResult() {
    fstream file;
    string addno, addno, name;
    float marks;
    int count = 0;
    system("cls");
    file.open("results.txt", ios::in);
	if (!file) {
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Enter Admission number to search: ";
    	cin >> addno;
		file >> name >> addno >> marks; 
		while(!file.eof()) {
			if (addno == addno) {
				cout << "Name: " << name << ", Admission No: " << addno << ", Marks: " << marks << "\n\n";
				count = 1;
				break;
			}
			file >> name >> addno >> marks; 
		}
		if (count == 0) {
			cout << "Record Not Found!" << endl;
		}
		system("pause");
		file.close();
	}

}

int main() {
    int choice;

    while (true) {
        system("cls");
		cout << "1. Add Result\n";
        cout << "2. Display All Results\n";
        cout << "3. Search Result\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addResult();
                break;
            case 2:
                displayResults();
                break;
            case 3:
                searchResult();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
