#include "UserInterface.h"

using namespace std;

//Support-function that prints out some information helping user navigate the text-
//based interface. Moved to a separate function to avoid unnecessary cluttering.

void UserInterface::printHelpText() {
    cout << "C - insert new CD" << endl;
    cout << "F - insert new Fiction book" << endl;
    cout << "N - insert new Non - Fiction book" << endl;
    cout << "J - insert new Journal" << endl;
    cout << "X - remove an object from the library" << endl;
    cout << "H - show this text" << endl;
    cout << "S - search" << endl;
    cout << "B - borrow a object" << endl;
    cout << "R - return an object" << endl;
    cout << "Q - quit the program" << endl;
}


//Function that loads the file (containing all the objects in textual form)
//if the file is not loaded. After that read input from user.

void UserInterface::menu() {

    if (fileLoaded) {

    } else {
        reg.readFile();
        fileLoaded = true;
    }


    char c = initMenu();
    choiceHandler(toupper(c));
}

//Function that reads the users input in the text-based menu and returns the input 
//as a char (which is used in in the switch-based choiceHandler()-function)

char UserInterface::initMenu() {
    char choice;
    bool valid = false;

    //Array containing the valid user inputs
    char validInput [10] = {'X', 'C', 'F', 'N', 'H', 'S', 'B', 'R', 'Q', 'J'};

    cout << "Choose one of X/C/F/N/J/H(Help)/S/B/R/Q" << endl;
    cin >> choice;

    for (int i = 0; i < 10; i++) {
        if (validInput[i] == toupper(choice)) {
            valid = true;
            cout << choice << endl;
            return choice;
        }
    }
    //If the input is not a character defined in the validInput-array print following to user and return to main menu.
    if (!valid) {
        cout << "No command for input " << choice << " please enter a valid command!" << endl;
        initMenu();
    }
}

//Switch-based function that calls relevant function depending on user input.

void UserInterface::choiceHandler(char c) {
    char input;


    switch (c) {
            //Calling function to remove object from library.
        case 'X':
            reg.removeRentalobject();
            break;
            //Search for object
        case 'S':
            cout << "Search by title (T) or author/artist (A)" << endl;

            cin >> input;
            //Switch in switch where T equals searching for object with title as selector
            //and A equals searching for object with Artist/author as selector.
            switch (toupper(input)) {
                case 'T':
                    reg.searchRentalobjectTitle();
                    break;
                case 'A':
                    reg.searchRentalobjectAuthor();
                    break;
                default:
                    //If input is not A or T
                    cout << "Input " << input << " is not valid" << endl;
                    break;
            }

            break;
            //Calling function to borrow object.
        case 'B':
            reg.borrowObject();
            break;
            //Calling function to return object
        case 'R':
            reg.returnBorrowObject();
            break;
            //Calling support-function which prints information about valid inputs
            //in the text-based interface.
        case 'H':
            printHelpText();
            break;
            //Exit program and save all objects in text-based form to file if any changes has been made.
        case 'Q':
            if (reg.changeMade()) {
                reg.writeToFile();
            }
            return;
            //Call function to add a non fictional book to library.
        case 'N':
            reg.addNonfictionBook();
            break;
            //Call function to add fiction book to library.
        case 'F':
            reg.addFictionbook();
            break;
            //Call function to add CD to library.
        case 'C':
            reg.addCD();
            break;
            //Call function to add Journal to library.
        case 'J':
            reg.addJournal();
            break;
    }
    //After finishing called function (except Q which quits program) return to main menu.
    menu();
}
