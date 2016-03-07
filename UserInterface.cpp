#include "UserInterface.h"

using namespace std;

void UserInterface::menu() {


    if (fileLoaded) {

    } else {
        reg.readFile();
        fileLoaded = true;
    }

    char c = initMenu();
    choiceHandler(toupper(c));
}

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

char UserInterface::initMenu() {
    char choice;
    bool valid = false;

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

    if (!valid) {
        cout << "No command for input " << choice << " please enter a valid command!" << endl;
        initMenu();
    }
}

void UserInterface::choiceHandler(char c) {
    char input;


    switch (c) {
        case 'X':
            reg.removeRentalobject();
            break;
        case 'S':
            cout << "Search by title (T) or author/artist (A)" << endl;

            cin >> input;

            switch (toupper(input)) {
                case 'T':
                    reg.searchRentalobjectTitle();
                    break;
                case 'A':
                    reg.searchRentalobjectAuthor();
                    break;
                default:
                    cout << "Input " << input << " is not valid" << endl;
                    break;
            }

            break;

        case 'B':
            reg.borrowObject();
            break;
        case 'R':
            reg.returnBorrowObject();
            break;
        case 'H':
            printHelpText();
            break;

        case 'Q':
            reg.writeToFile();
            return;
        case 'N':
            reg.addNonfictionBook();
            break;
        case 'F':
            reg.addFictionbook();
            break;
        case 'C':
            reg.addCD();
            break;
        case 'J':
            reg.addJournal();
            break;



    }

    menu();
}
