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
};

class Student {
private:
	char studentName[50];
	char studentID[10];

public:
	void add_student();
	void show_info();


};
//************************************************
//        ORDINARY FUNCTIONS PROTOTYPES
//************************************************
void register_student();
void gotoxy(int x, int y);
void intro();
void admin_Control_Panel();
void admin_Menu();

//************************************************
//       GLOBAL VARIABLES AND OBJECTS
//************************************************
std::ifstream readObject;
std::ofstream writeObject;
Student student;
Book book;

//************************************************
//       MEMEBERS FUNCTIONS DEFINITIONS
//************************************************

void Book::create_Book() {
	std::cout << "PLEASE ENTER THE BOOK NAME : ";
	std::cin.getline(bookName, 50);
	std::cout << "ENTER THE AUOTHER NAME: ";
	std::cin.getline(author, 50);
	std::cout << "ENTER THE PUBLISH YEAR: ";
	std::cin >> publishYear;
}

void Student::add_student() {
	std::cout << "Enter Student Name : ";
	std::cin >> studentName;
	std::cout << "Enter Student ID : ";
	std::cin >> studentID;
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
void Student::show_info() {
	readObject.open("Students.dat", std::ios::in);
	while (readObject.read((char*)&student, sizeof(Student))) {
		std::cout << studentName << std::endl;
		std::cout << studentID << std::endl;

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
			break;
		case'2':
			student.show_info();
			break;
		case'3':
			admin_Control_Panel();
			break;
		case'4':
			return 0;
			break;

		default:
			std::cout << "PLEASE CHOOSE NUMBERS FROM THE MENU" << std::endl;
		}
		std::cin.get();
		std::cin.ignore();
	} while (option != '4');

}

//************************************************
//        FUNCTION TO CREATE NEW STUDENETS
//************************************************

void register_student() {
	writeObject.open("Students.dat", std::ios::app | std::ios::out);
	student.add_student();
	writeObject.write((char*)&student, sizeof(Student));
	writeObject.close();
}


//************************************************
//       FUNCTION FOR ADMIN OPERATIONS
//************************************************

void admin_Control_Panel() {
	char option = '1';
	do {
		admin_Menu();
		option = _getche();
		option = toupper(option);
		switch (option) {
		case 'A':
			write_book();
			break;
		case 'B':
			break;

		case 'C':
			break;

		case 'D':
			break;

		case 'E':
			break;

		case 'F':
			break;

		case 'G':
			break;

		case 'H':
			break;
		case 'I':
			break;
		case 'J':
			break;
		case 'K':
			std::cout << "YOU ARE LEAVING THE ADMIN CONTROL PANNEL IN 5 SECONDS, PLEASE WAIT...";
			Sleep(3000);
			break;
		default:
			std::cout << "Wrong Input,Please Enter Your choice <A - K>";
			break;
		}
	} while (option != 'K');

}
//************************************************
//      FUNCTION FOR PRENETING THE ADMIN PAGE
//************************************************

void admin_Menu() {
	system("CLS");
	std::cout << "\n\n\n\tADMINISTRATOR MENU";
	std::cout << "\n\n\tA.CREATE STUDENT RECORD";
	std::cout << "\n\n\tB.DISPLAY ALL STUDENTS RECORD";
	std::cout << "\n\n\tC.DISPLAY SPECIFIC STUDENT RECORD ";
	std::cout << "\n\n\tD.MODIFY STUDENT RECORD";
	std::cout << "\n\n\tE.DELETE STUDENT RECORD";
	std::cout << "\n\n\tF.CREATE BOOK ";
	std::cout << "\n\n\tG.DISPLAY ALL BOOKS ";
	std::cout << "\n\n\tH.DISPLAY SPECIFIC BOOK ";
	std::cout << "\n\n\tI.MODIFY BOOK ";
	std::cout << "\n\n\tJ.DELETE BOOK ";
	std::cout << "\n\n\tK.BACK TO MAIN MENU";
	std::cout << "\n\n\tPlease Enter Your Choice <A-K> ";
}

//************************************************
//       FUNCTION FOR CONTROLLING THE CURSOR
//************************************************

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}