#include <iostream>
#include <string>
#include <vector>
#include <ostream>

using namespace std;

int itr=0;
string cN[20];
string cA[20];
long cC[20];

/*
 *    Class: Person
 */

class person{
	public:
		string name;
		string address;
		long ccNum;

		person();
		person(string _name, string _address, long _ccNum);
		string getName();
		string getAddress();
		long getCC();
};


person::person()
{
	name = "";
	address = "";
	ccNum = 0;
}

person::person(string _name, string _address, long _ccNum)
{
	name = _name;
	address = _address;
	ccNum = _ccNum;
}

string person::getName()
{
	return name;
}
		
string person::getAddress()
{
	return address;
}
		
long person::getCC()
{
	return ccNum;
}


/*
 *    Class: Book
 */

class book{
	public:
	 	string name;
		string author;
	 	string isbn;
	 	float price;
	 	int stock;

	 	book();
	 	book(string _name, string _author, string _isbn, float _price, int _stock);
	 	void setName(string s);
	 	void setAuthor(string s);
	 	void setIsbn(string s);
	 	void setPrice(float s);
	 	void setStock(int s);
	 	string getName();
	 	string getAuthor();
	 	string getIsbn();
	 	float getPrice();
	 	int getStock();
};

book::book()
{
	name = "void";
	author = "";
	isbn = "";
	price = 0;
	stock = 0;
}

book::book(string _name, string _author, string _isbn, float _price, int _stock)
{
	name = _name;
	author = _author;
	isbn = _isbn;
	price = _price;
	stock = _stock;
}
	 	
void book::setName(string s)
{
	name = s;
}
	 	
void book::setAuthor(string s)
{
	author = s;
}
	 	
void book::setIsbn(string s)
{
	isbn = s;
}
	 	
void book::setPrice(float s)
{
	price = s;
}
	 	
void book::setStock(int s)
{
	stock = s;
}

string book::getName()
{
	return name;
}

string book::getAuthor()
{
	return author;
}

string book::getIsbn()
{
	return isbn;
}

float book::getPrice()
{
	return price;
}

int book::getStock()
{
	return stock;
}
	

/*
 *    Class: Store
 */


class store{
	public:
		book* getLOTR();
		book* getHobbit();
		book* getHPSS();
		book* getHPCS();
		book* getHPOP();
		book* getWAP();
		book* getAK();
		book* getHF();
		void sell(string bk);
		void update();

	book LOTR = book("Lord of the Rings", "Tolkien", "1212", 30.12, 10);
	book Hobbit = book("The Hobbit", "Tolkien", "1314", 12.78, 20);
	book HPSS = book("Harry Potter and the Sorcerer's Stone", "Rowling", "1108", 19.99, 11);
	book HPCS = book("Harry Potter and the Chamber of Secrets", "Rowling", "1013", 11.90, 3);
	book HPOP = book("Harry Potter and the Order of the Phoenix", "Rowling", "1212", 9.99,2);
	book WAP = book("War and Peace", "Tolstio", "1011", 7.77, 25);
	book AK = book("Anna Karenina", "Tolstoi", "0901", 2.23, 12);
	book HF = book("The Adventures of Huckleberry Finn", "Twain", "0999", 123.45, 75);
};

store bookStore = store();

book* store::getLOTR()
{
	return &LOTR;
}

book* store::getHobbit()
{
	return &Hobbit;
}

book* store::getHPSS()
{
	return &HPSS;
}

book* store::getHPCS()
{
	return &HPCS;
}

book* store::getHPOP()
{
	return &HPOP;
}

book* store::getWAP()
{
	return &WAP;
}

book* store::getAK()
{
	return &AK;
}

book* store::getHF()
{
	return &HF;
}


void store::sell(string bk)
{
	book* temp;
	if(bk == "LOTR")
		temp = bookStore.getLOTR();
	else if(bk == "Hobbit")
		temp = bookStore.getHobbit();
	else if(bk == "HPSS")
		temp = bookStore.getHPSS();
	else if(bk == "HPCS")
		temp = bookStore.getHPCS();
	else if(bk == "HPOP")
		temp = bookStore.getHPOP();
	else if(bk == "WAP")
		temp = bookStore.getWAP();
	else if(bk == "AK")
		temp = bookStore.getAK();
	else if(bk == "HF")
		temp = bookStore.getHF();

	temp->setStock(temp->getStock() - 1);
}

void store::update()
{
	book *tempBook;
	int tempA;
	string tempB;

	cout << "(1) Lord of the Rings" << endl;
	cout << "(2) The Hobbit" << endl;
	cout << "(3) Harry Potter and the Sorcerer's Stone" << endl;
	cout << "(4) Harry Potter and the Chamber of Secrets" << endl;
	cout << "(5) Harry Potter and the Order of the Phoenix" << endl;
	cout << "(6) War and Peace" << endl;
	cout << "(7) Anna Karenina" << endl;
	cout << "(8) The Adventures of Huckleberry Finn" << endl;
	cout << "Please enter the number of the book you would like to update" << endl;
	cin >> tempA;


	if(tempA == 1)
		tempBook = bookStore.getLOTR();
	else if(tempA == 2)
		tempBook = bookStore.getHobbit();
	else if(tempA == 3)
		tempBook = bookStore.getHPSS();
	else if(tempA == 4)
		tempBook = bookStore.getHPCS();
	else if(tempA == 5)
		tempBook = bookStore.getHPOP();
	else if(tempA == 6)
		tempBook = bookStore.getWAP();
	else if(tempA == 7)
		tempBook = bookStore.getAK();
	else if(tempA == 8)
		tempBook = bookStore.getHF();
	else{
		cout << "Invalid name" << endl;
		return;
	}

	cout << "What would you like to update?" << endl;
	cin >> tempB;

	if(tempB == "name"){
		string tname;
		cout << "Please enter a new name" << endl;
		cin >> tname;
		tempBook->setName(tname);
		cout << "The books name has now been changed to " << tname << endl;
	}else if(tempB == "author"){
		string tauthor;
		cout << "Please enter a new author" << endl;
		cin >> tauthor;
		tempBook->setAuthor(tauthor);
		cout << "The books author has now been changed to " << tauthor << endl;
	}else if(tempB == "isbn"){
		string tisbn;
		cout << "Please enter a new isbn" << endl;
		cin >> tisbn;
		tempBook->setIsbn(tisbn);
		cout << "The books ISBN has now been changed to " << tisbn << endl;
	}else if(tempB == "price"){
		float tprice;
		cout << "Please enter a new price" << endl;
		cin >> tprice;
		tempBook->setPrice(tprice);
		cout << "The books price has now been changed to " << tprice << endl;
	}else if(tempB == "stock"){
		int tstock;
		cout << "Please enter a new stock" << endl;
		cin >> tstock;
		tempBook->setStock(tstock);
		cout << "The books stock has now been changed to " << tstock << endl;
	}else{
		cout << "Invalid name" << endl;
		return;
	}

	
}

/*
 *    Class: Client
 */


class client: public person{
	public:
		void buy(); //can we just make this a person function?

		client(); 
};

client::client()
{
	person();
}

void client::buy()
{
	string cName;
	string cAddress;
	long cCC;
	bool flag = false;
	int bookNum;

	cout << "Please enter your name" << endl;
	cin >> cName;

	for (int i = 0; i < 20; i ++){
		if (cName == cN[i]){
	    	person tempClient(name, cA[i], cC[i]);
	    	flag = true;
	    	cout << "Welcome back " << cName << endl;
	    }
	}

	if(flag==false){
		cout << "Please enter your address" << endl;
		cin >> cAddress;
		cout << "Please enter your credit card number" << endl;
		cin >> cCC;
		cN[itr] = cName;
		cA[itr] = cAddress;
		cC[itr] = cCC;
		itr++;
	}

 	cout << endl << "Which book would you like to purchase?" << endl << endl;
	cout << "(1) Lord of the Rings" << endl;
	cout << "(2) The Hobbit" << endl;
	cout << "(3) Harry Potter and the Sorcerer's Stone" << endl;
	cout << "(4) Harry Potter and the Chamber of Secrets" << endl;
	cout << "(5) Harry Potter and the Order of the Phoenix" << endl;
	cout << "(6) War and Peace" << endl;
	cout << "(7) Anna Karenina" << endl;
	cout << "(8) The Adventures of Huckleberry Finn" << endl;
	cout << "Please enter the number of the book you would like to purchase" << endl;

	cin >> bookNum;
	string bookName;


	if(bookNum == 1){
		bookStore.sell("LOTR");
		bookName="Lord of the Rings";
	}else if(bookNum == 2){
		bookStore.sell("Hobbit");
		bookName="The Hobbit";
	}else if(bookNum == 3){
		bookStore.sell("HPSS");
		bookName="Harry Potter and the Sorcerer's Stone";
	}else if(bookNum == 4){
		bookStore.sell("HPCS");
		bookName="Harry Potter and the Chamber of Secrets";
	}else if(bookNum == 5){
		bookStore.sell("HPOP");
		bookName="Harry Potter and the Order of the Phoenix";
	}else if(bookNum == 6){
		bookStore.sell("WAP");
		bookName="War and Peace";
	}else if(bookNum == 7){
		bookStore.sell("AK");
		bookName="Anna Karenina";
	}else if(bookNum == 8){
		bookStore.sell("HF");
		bookName="The Adventures of Huckleberry Finn";
	}else{
		cout << "Invalid Entry";
		return;
	}

	cout << "Congradulations you purchased " << bookName << endl;

}

/*
 *    Class: person
 */

class owner: public client{
	public:
		void changePrice();
		void inventory();
};

void owner::changePrice()
{
	bookStore.update();
}

void owner::inventory()
{
	book *tempBook;


	tempBook = bookStore.getLOTR();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

	tempBook = bookStore.getHobbit();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

	tempBook = bookStore.getHPSS();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

	tempBook = bookStore.getHPCS();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

	tempBook = bookStore.getHPOP();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

	tempBook = bookStore.getWAP();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

	tempBook = bookStore.getAK();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

	tempBook = bookStore.getHF();
	cout << "Name:" << tempBook->getName();
	cout << "  Author:" << tempBook->getAuthor();
	cout << "  ISBN:" << tempBook->getAuthor();
	cout << "  Price:" << tempBook->getPrice();
	cout << "  Stock:" << tempBook->getStock() << endl;

}

/*
 *    Start of Main
 */


int main()
{

	string pass;
	int choice;

	


	cout << "Hello welcome to BookStore!" << endl;
	cout << "If you are a owner please enter the password now" << endl; //password is owner
	cout << "If you are not please enter the word CLIENT" << endl;

	cin >> pass;

	while(1)
	{
		if(pass == "owner"){
			owner tempO;

			cout << "Welcome owner" << endl;
			while(1)
			{
				cout << "Would you like to:" << endl << "(1) Change stock" << endl;
				cout << "(2) Print inventory" << endl << "(3) Buy a book" << endl;
				cout << "(4) Quit" << endl;
				cin >> choice;


				if(choice == 1)
					tempO.changePrice();
				else if(choice == 2)
					tempO.inventory();
				else if(choice == 3)
					tempO.buy();
				else if(choice == 4)
					return 1;
				else{
					cout << "Please enter a valid number" << endl;
				}
				cout << "Main menu" << endl;
			}
		}else if(pass == "CLIENT"){
			client tempC;

			while(1){
				cout << "Would you like to:" << endl << "(1) Buy a book" << endl;
				cout << "(2) Quit" << endl;
				cin >> choice;
				if(choice == 1)
					tempC.buy();
				else if(choice == 2)
					return 1;
				else{
					cout << "Please enter a valid number" << endl;
					cin >> choice;
				}
				cout << "Main menu" << endl;
			}
		}else{
			cout << "Password incorrect" << endl;
			cout << "If you are a owner please enter the password now" << endl; //password is owner
			cout << "If you are not please enter the word CLIENT" << endl;
			cin >> pass;
		}
	}
}














