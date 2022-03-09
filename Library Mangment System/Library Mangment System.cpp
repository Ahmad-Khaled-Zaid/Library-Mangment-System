#include<iostream>
#include<windows.h> //gotoxy() , Sleep() functions
#include<conio.h> // getche() function //console input/output
#include<fstream> // for writing and reading from files
#include<string> // for getline function


class Book {
private:
	char bookName[50];
	char author[50];
	int publishYear;
public:
	void create_Book();
	void show_info();
};

class Student {
private:
	char studentName[50];
	char studentID[10];

public:

};

//global objects and variables
std::ifstream readObject;
std::ofstream writeObject;
Student student;
Book book;

void Book::create_Book() {
	std::cout << "PLEASE ENTER THE BOOK NAME : ";
	std::cin.getline(bookName, 50);
	std::cout << "ENTER THE AUOTHER NAME: ";
	std::cin.getline(author, 50);
	std::cout << "ENTER THE PUBLISH YEAR: ";
	std::cin >> publishYear;
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void intro()
{
	system("cls");
	gotoxy(35, 11);
	std::cout << "LIBRARY";
	gotoxy(35, 14);
	std::cout << "MANAGEMENT";
	gotoxy(35, 17);
	std::cout << "SYSTEM";
	//_getch();
}
void write_book() {
	book.create_Book();
	writeObject.open("Books.dat", std::ios::app | std::ios::out);
	writeObject.write((char*)&book, sizeof(Book));
	writeObject.close();
}
void Book::show_info() {
	readObject.open("Books.dat", std::ios::in);
	while (readObject.read((char*)&book, sizeof(Book))) {
		std::cout << bookName << " " << author << " " << publishYear;
	}
	readObject.close();

}
int main() {
	char option;
	intro();
	Sleep(1000);
	std::cout << "\n\nLoading system..." << std::endl;
	Sleep(2000);

	do {
		system("cls");
		std::cout << "\n\n\n\tMAIN MENU";
		std::cout << "\n\n\t01. BOOK ISSUE";
		std::cout << "\n\n\t02. BOOK DEPOSIT";
		std::cout << "\n\n\t03. ADMINISTRATOR MENU";
		std::cout << "\n\n\t04. EXIT";
		std::cout << "\n\n\tPlease Select Your Option (1-4) ";
		option = _getche();
		system("cls");
		switch (option) {
		case'1':
			write_book();
			break;
		case'2':
			book.show_info();
			std::cin.get();
			std::cin.ignore();
			break;
		case'3':
			break;
		case'4':
			return 0;
			break;

		default:
			std::cout << "PLEASE CHOOSE NUMBERS FROM THE MENU" << std::endl;
		}
	} while (option != '4');

}
