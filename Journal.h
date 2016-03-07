/* 
 * File:   Journal.h
 * Author: Adis
 *
 * Created on den 26 februari 2016, 19:13
 */

#ifndef JOURNAL_H
#define	JOURNAL_H

#include <string>
#include "Rentalobject.h"

using namespace std;


class Journal : public Rentalobject {
public:

    Journal(string journalTitle, string journalVolume) {
        title = journalTitle;
        volume = journalVolume;
    }

    void print(ostream &outstream) {
        outstream << "Journal\n" << getTitle() << "\n" << volume 
        << "\n" << getId() << "\n" << getRenterId() << endl;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return title;
    };


private:
    string title;
    string volume;
};

#endif	/* JOURNAL_H */

