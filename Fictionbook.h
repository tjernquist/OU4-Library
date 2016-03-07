/* 
 * File:   Fictionbook.h
 * Author: Adis
 *
 * Created on den 26 februari 2016, 22:43
 */

#ifndef FICTIONBOOK_H
#define	FICTIONBOOK_H

#include <string>
#include "Book.h"

using namespace std;

class Fictionbook : public Book {
public:

    Fictionbook(string bookTitle, string bookAuthor) {
        title = bookTitle;
        author = bookAuthor;
    }

    string getTitle() {
        return title;
    }

    void print(ostream &outstream) {
        outstream << "Fiction\n" << author << "\n" << getTitle() 
        << "\n" << getId() << "\n" << getRenterId() << endl ;
    }

private:
    string title;

};


#endif	/* FICTIONBOOK_H */

