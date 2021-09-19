#include<iostream>
#include<string.h>
#include<string>
#include <fstream>
#include "ArrayList.h"
using namespace std;
class Human
{
public:
	Human(int id, bool gender, char firstName[30], char lastName[30], int day, int month, int year);
	Human();
	void setGender(bool gender);
	void setFirstName(char fisrtName[30]);
	void setLastName(char lastName[30]);
	void setId(int id);
	int getId() { return id; }
	char* getFirstName() { return firstName; }
	char* getLastName() { return lastName; }
	char* getFullName() {
		strcpy(this->fullName, this->firstName);
		strcat(this->fullName, this->lastName);
		return fullName;
	}
	bool getGender() { return gender; }
	void toString();
	struct BirthDate
	{
		int day;
		int month;
		int year;
	}BirthDate;
private:

	int id;
	bool gender;
	char firstName[30];
	char lastName[30];
	char fullName[40];
};
void Human::toString() {
	cout << "ID:" <<id << endl;
	cout << "Name: " << getFullName() << endl;
	cout << "First Name: " << getFirstName() << endl;
	cout << "Last Name: " << getLastName() << endl;
	cout << "Gender " << (getGender() == true ? "Male" : "Female") << endl;
	cout << "BirthDay: " << BirthDate.day << "/" << BirthDate.month << "/" << BirthDate.year << endl;;

}
void Human::setId(int id) {
	this->id = id;
}
Human::Human(int id, bool gender, char firstName[30], char lastName[30], int day, int month, int year)
{
	this->id = id;
	this->gender = gender;
	strcpy(this->firstName, firstName);
	strcpy(this->lastName, lastName);
	strcpy(this->fullName, firstName);
	strcat(this->fullName, lastName);
	BirthDate.day = day;
	BirthDate.year = year;
	BirthDate.month = month;
}
Human::Human() {
	this->id = 0;
	this->gender = true;
	strcpy(this->firstName,"");
	strcpy(this->lastName, "");
	strcpy(this->fullName, this->firstName);
	strcat(this->fullName, this->lastName);
}
void Human::setFirstName(char firstName[30]) {
	strcpy(this->firstName, firstName);
}
void Human::setLastName(char lastName[30]) {
	strcpy(this->lastName, lastName);
}
void Human::setGender(bool gender) {
	this->gender = gender;
}
class StudentManager {
public :
	StudentManager();
	void addHuman(Human human);
	Human get(int index);
	void sortHumanByNameUsingBubble();
	void printListHuman();
	Human* Listhuman;
	Human* copyList;
	void swap(Human &human1,Human &human2);
	void copy();
	void sortHumanByNameUsingSelect();
	void sortHumanByNameUsingInsert();
	int size;
	int n;
};
StudentManager::StudentManager() {
	Listhuman = new Human[10];
	copyList = new Human[10];
	size = 0;
	n = 0;
}
void StudentManager::addHuman(Human human) {
	Listhuman[size] = human;
	size++;
	n = size;

}
Human StudentManager::get(int index) {
	return Listhuman[index];
}
void StudentManager::swap(Human &human1, Human &human2) {
	Human human = human1;
	human1 = human2;
	human2 = human;
}
void StudentManager::printListHuman() {
	for (int i = 0; i < size; i++) {
		Listhuman[i].toString();
	}
}
void StudentManager::copy() {  
	for (int i = 0; i < size; i++) {
		copyList[i] = Listhuman[i];
	}
}

void StudentManager::sortHumanByNameUsingBubble() {

	int i, j;
	bool check = false;
	char firstHuman[30];
	char secondHuman[30];
	for (i = 0; i < size; i++) {
		strcpy(firstHuman,Listhuman[i].getFirstName());
		for (j = i+1; j < size; j++) {
			strcpy(secondHuman, Listhuman[j].getFirstName());
			if (strcmp(firstHuman, secondHuman) > 0) {
				swap(Listhuman[i], Listhuman[j]);
				check == true;
			}
		}
		if (check == false)break;
	}
	cout << "--------------Bubble sort------------" << endl;
	printListHuman();
}
void StudentManager::sortHumanByNameUsingSelect() {
	int minIndex;
	char firstHuman[30];
	char secondHuman[30];
	for (int i= 0; i < size; i++) {
		minIndex = i;
		strcpy(firstHuman, Listhuman[minIndex].getFirstName());
		for (int j = i + 1; j < size; j++) {
			strcpy(secondHuman, Listhuman[j].getFirstName());
			if (strcmp(firstHuman, secondHuman)>0) {
				minIndex = j;
			}
			swap(Listhuman[minIndex],Listhuman[i]);
		}

	}
	cout << "--------------Select sort------------" << endl;
	printListHuman();
}
void StudentManager::sortHumanByNameUsingInsert() {
	char firstHuman[30];
	char secondHuman[30];
	if (size <= 1) {
		size = n;
		printListHuman();
		return;
	}
	else {
		int k = size - 1;
		Human human = Listhuman[k];
		int j = k-1;
		strcpy(firstHuman, human.getFirstName());
		strcpy(secondHuman,Listhuman[j].getFirstName());
		while (j>=0&&(strcmp(firstHuman, secondHuman) < 0)) {
			Listhuman[j + 1] = Listhuman[j];
			j--;
		}
		Listhuman[j + 1] = human;
	}
	size--;
	 sortHumanByNameUsingInsert();
}
void saveFile(string file,StudentManager listHuman) {

    ofstream fileOutput(file);

	if (fileOutput.fail())
	{
		std::cout << "Cannot open file at " << file << std::endl;
		return;
	}
	int i = listHuman.size-1;
	while (i >=0) {
		fileOutput << listHuman.Listhuman[i].getId()<<"," << listHuman.Listhuman[i].getFirstName() << "," << listHuman.Listhuman[i].getLastName() << ","
			<< listHuman.Listhuman[i].getFullName() << "," << (listHuman.Listhuman[i].getGender() == true) ? "Male" : "Female";
		fileOutput << listHuman.Listhuman[i].BirthDate.day<<"/"<< listHuman.Listhuman[i].BirthDate.month <<"/"<< listHuman.Listhuman[i].BirthDate.year;
		fileOutput << endl;
		i--;
	}
}
Human inputHuman() {
	int id, day, month, year;
	char firstName[30], lastName[30];
	int gender;
	cout << "ID: "; cin >> id; cin.ignore();
	cout << "First Name: "; cin.getline(firstName,30);
	cout << "Last Name: "; cin.getline(lastName,30);
	cout << "Gender (1:Male,2:Female): "; cin >> gender;
	cout << "Date:  "; cin >> day;
	cout << "Month: "; cin >> month;
	cout << "Year: "; cin >> year;
	Human human = Human(id, (gender==1)?true:false,firstName, lastName,day,month,year);
	return human;
}
void menu(StudentManager listHuman) {
	int choose;
	char fileName[30];
	do {
		cout << "1.Import Human:\n " ;
		cout << "2.Print List Human \n ";
		cout << "3.Bubbler Sort \n";
		cout << "4.Select Sort \n";
		cout << "5.Insert Sort \n";
		cout << "6.Save to File \n";
		cout << "Choose: "; cin >> choose;
		switch (choose) {
		case 1:
			listHuman.addHuman(inputHuman());
			break;
		case 2:
			listHuman.printListHuman();
			break;
		case 3:
			listHuman.sortHumanByNameUsingBubble();
			break;
		case 4:
			listHuman.sortHumanByNameUsingSelect();
			break;
		case 5 :
			listHuman.sortHumanByNameUsingInsert();
			break;
		case 6:
			cin.ignore();
			cout << "FileName:";
			cin.getline(fileName,30);
			saveFile(fileName, listHuman);
			break;
		}
	} while (choose != 0);
}
int main() {
	StudentManager listHuman;
	menu(listHuman);
	return 0;
	
}

