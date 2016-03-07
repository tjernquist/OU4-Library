/* 
 * File:   Register.h
 * Author: Adis
 *
 * Created on den 26 februari 2016, 19:37
 */

#ifndef REGISTER_H
#define	REGISTER_H

#include "Rentalobject.h"
#include "Journal.h"
#include "CD.h"
#include "Fictionbook.h"
#include "NonFictionBook.h"

#include <vector>
#include <string>
#include <algorithm> 
#include <fstream>
#include <sstream>


using namespace std;

class Register {
public:

    void searchRentalobjectAuthor();

    void searchRentalobjectTitle();

    void borrowObject();

    void returnBorrowObject();

    void removeRentalobject();

    void readFile();
    
    void writeToFile();

    void addNonfictionBook();

    void addCD();

    void addJournal();

    void addFictionbook();


private:
    vector<Rentalobject*> objectRegister;
};

#endif	/* REGISTER_H */

