/* 
 * File:   NonFiction.h
 * Author: Adis
 *
 * Created on den 26 februari 2016, 22:45
 */

#ifndef NONFICTION_H
#define	NONFICTION_H

#include <string>
#include "Book.h"

using namespace std;

class NonFictionBook : public Book {
public:

    NonFictionBook(string bookCategory, string bookAuthor) {
        category = bookCategory;
        author = bookAuthor;
    }

    string getTitle() {
        return category;
    }

    void print(ostream &outstream) {
        outstream << "NonFiction\n" << author << "\n" << getTitle() 
        << "\n" << getId() << "\n" << getRenterId() << endl;
    }

private:
    string category;

};

#endif	/* NONFICTION_H */

