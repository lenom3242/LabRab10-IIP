#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <stdlib.h>  
using namespace std;
struct Animal {
	string name="Petr Petrovich", nickname="Murka", breed ="Dark", age="10";
};
void SearchDB()
{
	string temp;
	string choice;
	string word;
	int counter = 0;
	system("cls");
	cout << "Please enter the name of file:\n";
	cin >> choice;
	ifstream inpf(choice);
	if (!inpf)
	{
		cout << "Error while opening file";
		inpf.close();
	}
	
	else
	{
		cout << "Please specify colour:\n";
		cin >> word;
		while (getline(inpf, temp)) {
			counter++;
		}
		inpf.close();
		ifstream inpf(choice);
		Animal* p_animal = new Animal[counter];
		for (int i = 0; i < counter; i++) {
			getline(inpf, p_animal[i].name);
			getline(inpf, p_animal[i].nickname);
			getline(inpf, p_animal[i].breed);
			getline(inpf, p_animal[i].age);
		}
		for (int i = 0; i < counter; i++) {
			if (p_animal[i].breed == word) {
				cout << p_animal[i].name << endl;
				cout << p_animal[i].nickname << endl;
				cout << p_animal[i].breed << endl;
				cout << p_animal[i].age << endl;
			}
		}

	}
	inpf.close();
}
void CreateDB(Animal *local, int choice){
	system("cls");
	cout << "List of generated animals:\n";
	for (int i = 0; i < choice;i++)
	{
		if (rand() % 3 + 1 == 1)
			local[i].breed = "Red";
		if (rand() % 3 + 1 == 2)
			local[i].breed = "Yellow";
		if (rand() % 3 + 1 == 3)
			local[i].breed = "Blue";
	}
	for (int i=0;i<choice;i++)
		cout << local[i].name << " " << local[i].nickname << " " << local[i].breed << " " << local[i].age << endl;
	cout << "Sorting and saving file...\n";
	for (int i = 0; i < choice; i++)
	{
		if (local[i].breed != local[i+1].breed)
		for (int j = i+2; j < choice; j++)
		{
			if (local[i].breed == local[j].breed)
				swap(local[j], local[i + 1]);
		}
	}
	ofstream outf("DB.txt"); 
	for (int i = 0; i < choice; i++)
		outf << local[i].name << endl << local[i].nickname << endl << local[i].breed << endl << local[i].age << endl;
	outf.close();
	cout << "Do you wish to open output file? 1/0\n";
	cin >> choice;
	if (choice == 1)
		system("notepad DB.txt");
}
void main()
{	
	
	int choice;
	cout << "Please enter number:\n" << "1)To create DB with animals\n" << "2)To search for animals\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		{
		system("cls");
		cout << "Please enter the number of animals:\n";
		cin >> choice;
		Animal* p_animal = new Animal[choice];
		CreateDB(p_animal, choice);
		break;
		}
	case 2:
		{
		SearchDB();
		}
	}
		
	
}