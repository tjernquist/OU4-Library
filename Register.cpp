#include "Register.h"

using namespace std;

//Function to add CD in library with parameters set as input by the user.
void Register::addCD() {

    string artist, title, playTime;
    cout << "Artist: " << endl;
    cin >> artist;
    cout << "Title: " << endl;
    cin >> title;
    cout << "Playtime: " << endl;
    cin >> playTime;

    CD *c = new CD(artist, title, playTime);
        libraryChanged = true;
    objectRegister.push_back(c);
}

//Function to add fictional book in library with parameters set as input by the user.
void Register::addFictionbook() {

    string title, author;
    cout << "Title: " << endl;
    cin >> title;
    cout << "Author: " << endl;
    cin >> author;

    Fictionbook *f = new Fictionbook(title, author);
    libraryChanged = true;
    objectRegister.push_back(f);
}

//Function to add journal in library with parameters set as input by the user.

void Register::addJournal() {

    string title, volume;
    cout << "Title: " << endl;
    cin >> title;
    cout << "Volume: " << endl;
    cin >> volume;

    Journal *j = new Journal(title, volume);
    libraryChanged = true;
    objectRegister.push_back(j);
}

//Function to add Non-fictional in library with parameters set as input by the user.
void Register::addNonfictionBook() {

    string category, author;
    cout << "Category: " << endl;
    cin >> category;
    cout << "Author: " << endl;
    cin >> author;

    NonFictionBook *n = new NonFictionBook(category, author);
    libraryChanged = true;
    objectRegister.push_back(n);
}

void Register::borrowObject() {
    int bookId, borrowerId;
    bool found = false;

    cout << "ID:" << endl;
    cin >> bookId;
    cout << "Borrower:" << endl;
    cin >> borrowerId;

    for (int i = 0; i < objectRegister.size(); i++) {
        if (objectRegister[i]->getId() == bookId) {
            if (objectRegister[i]->getRenterId() != 0) {
                cout << "Book is already borrowed" << endl;
                found = true;
            } else {
                objectRegister[i]->registerObjectAsBorrowed(borrowerId);
                libraryChanged = true;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Book with ID " << bookId << " not found." << endl;
    }
}

//Function to remove object from library with input from user. Selector here is the ID of the book.
void Register::removeRentalobject() {
    int id;
    bool removed = false;

    cout << "Enter the ID of the object you want to remove:" << endl;
    cin >> id;

    for (int i = 0; i < objectRegister.size(); i++) {
        if (objectRegister[i]->getId() == id) {
            //Using the erase-remove idiom to remove the object that matches the ID from the vector. 
            objectRegister.erase(std::remove(objectRegister.begin(), objectRegister.end(), objectRegister[i]), objectRegister.end());
            cout << "Object with id " << id << " has been removed" << endl;
            libraryChanged = true;
            removed = true;
        }
    }
    //If a object with the ID could not be found, following is printed to the user.
    if (!removed) {
        cout << "No object with ID " << id << " found" << endl;
    }
}

//Function to read file and create objects from the containing lines.
void Register::readFile() {
    ifstream inFile;
    //Open file name test.txt containing the objects in the library in text-form.
    inFile.open("test.txt");

    //Read line from the test.txt-file.
    if (inFile) {
        string c;
        while (getline(inFile, c)) {
            //If line is Journal, use the following lines as input and create a journal-object.
            if (c == "Journal") {

                int id, borrowerId;
                string title, volume;
                getline(inFile, title);
                getline(inFile, volume);

                inFile >> id >> borrowerId;

                if (id > Rentalobject::getMaxId()) {
                    Rentalobject::setMaxId(id);
                }

                //Create object with the input from file
                Journal *journal = new Journal(title, volume);

                if (borrowerId != 0) {
                    journal->registerObjectAsBorrowed(borrowerId);
                }

                //Add the created object to vector
                objectRegister.push_back(journal);
            }
            //If line is CD, use the following lines as input and create a CD-object.
            if (c == "CD") {

                int id, borrowerId;
                string artist, title, playtime;
                getline(inFile, artist);
                getline(inFile, title);
                getline(inFile, playtime);

                inFile >> id >> borrowerId;

                if (id > Rentalobject::getMaxId()) {
                    Rentalobject::setMaxId(id);
                }
                //Create object with the input from file
                CD *cd = new CD(artist, title, playtime);

                if (borrowerId != 0) {
                    cd->registerObjectAsBorrowed(borrowerId);
                }

                //Add the created object to vector
                objectRegister.push_back(cd);
            }
            //If line is NonFiction, use the following lines as input and create a Non fictional book-object.
            if (c == "NonFiction") {

                int id, borrowerId;
                string artist, title;
                getline(inFile, artist);
                getline(inFile, title);

                inFile >> id >> borrowerId;

                if (id > Rentalobject::getMaxId()) {
                    Rentalobject::setMaxId(id);
                }

                //Create object with the input from file
                Book *nonfictionbook = new NonFictionBook(title, artist);

                if (borrowerId != 0) {
                    nonfictionbook->registerObjectAsBorrowed(borrowerId);
                }

                //Add the created object to vector
                objectRegister.push_back(nonfictionbook);
            }
            //If line is Fiction, use the following lines as input and create a fictional book-object.
            if (c == "Fiction") {

                int id, borrowerId;
                string artist, title;
                getline(inFile, artist);
                getline(inFile, title);

                inFile >> id >> borrowerId;

                if (id > Rentalobject::getMaxId()) {
                    Rentalobject::setMaxId(id);
                }

                //Create object with the input from file
                Book *fictionbook = new Fictionbook(title, artist);

                if (borrowerId != 0) {
                    fictionbook->registerObjectAsBorrowed(borrowerId);
                }

                //Add the created object to vector
                objectRegister.push_back(fictionbook);
            }
        }
        //finally close the opened file.
        inFile.close();
    } else {
        //Write out following if the file test.txt was not found.
        cout << "File not found" << endl;
    }
}

//Function to return borrowed object, i.e. set Renter ID to 0.
void Register::returnBorrowObject() {
    int bookId;

    //Get input from user which book to be returned.
    cout << "ID:" << endl;
    cin >> bookId;

    for (int i = 0; i < objectRegister.size(); i++) {
        if (objectRegister[i]->getId() == bookId) {
            //If book is not borrowed
            if (objectRegister[i]->getRenterId() == 0) {
                cout << "Book can not be returned since its not loaned out." << endl;
            } else {
                objectRegister[i]->returnObject();
                libraryChanged = true;
            }
        }
    }
}

//Search for object using Author/Creator as selector
void Register::searchRentalobjectAuthor() {

    string objectCreator;
    bool found = false;

    cout << "Search string:";

    //Get input from user
    cin >> objectCreator;

    cout << endl;

    for (int i = 0; i < objectRegister.size(); i++) {
        //Using string.find() and string::npos to partially search string
        if (objectRegister[i]->getAuthor().find(objectCreator) != string::npos) {
            objectRegister[i]->print(cout);
            found = true;
        }
    }

    if (!found) {
        cout << "Theres no object with author: " << objectCreator << endl;
    }
}

//Search for object using object title as selector
void Register::searchRentalobjectTitle() {

    string objectTitle;
    bool found = false;

    cout << "Search string: ";

    //Get input from user
    cin >> objectTitle;
    cout << objectTitle;

    cout << endl;

    for (int i = 0; i < objectRegister.size(); i++) {
        //Using string.find() and string::npos to partially search string
        if (objectRegister[i]->getTitle().find(objectTitle) != string::npos) {
            objectRegister[i]->print(cout);
            found = true;
        }
    }
    if (!found) {
        cout << "Theres no object with title: " << objectTitle << endl;
    }
}

//Write all objects in vector to file in text-format.
void Register::writeToFile() {
    ofstream outfile;
    outfile.open("test.txt");

    for (int i = 0; i < objectRegister.size(); i++) {
        objectRegister[i]->print(outfile);
    }
    outfile.close();
}

bool Register::changeMade() {
    return libraryChanged;
}
