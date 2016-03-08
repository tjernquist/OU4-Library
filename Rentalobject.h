/* 
 * File:   Rentalobject.h
 * Author: Adis
 *
 * Created on den 26 februari 2016, 19:03
 */

#ifndef RENTALOBJECT_H
#define	RENTALOBJECT_H

#include <iostream>

using namespace std;


//Base class that defines the general functionality of all the lendable objects in the library
class Rentalobject {
public:

    Rentalobject();

    const int getId() {
        return id;
    }

    void registerObjectAsBorrowed(int borrowerId) {
        renterID = borrowerId;
    }

    void returnObject() {
        renterID = 0;
    }

    const int getRenterId() {
        return renterID;
    }

    static const int getMaxId() {
        return current_maxid;
    }

    static void setMaxId(int i) {
        current_maxid = i;
    }

    virtual void print(ostream &) {};
    virtual string getTitle() = 0;
    virtual string getAuthor() = 0;

private:
        //Static variable that keeps track of the current highest renter ID
    static int current_maxid;
    //ID of the rentable object.
    int id;
    //Variable that keeps track of the ID of the borrower.
    int renterID;
};


#endif	/* RENTALOBJECT_H */

