#ifndef BOOK_H
#define	BOOK_H



#include <string>
#include "Rentalobject.h"
#include "Fictionbook.h"
#include <iostream>

using namespace std;

//Parent-class to the different categories of books available at the library.
class Book : public Rentalobject {
public:
    virtual void print(ostream &o) {};
    virtual string getTitle() = 0;
    string getAuthor() {
        return author;
    }
    
protected:
    string author;

};

#endif	/* BOOK_H */

