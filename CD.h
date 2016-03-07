/* 
 * File:   CD.h
 * Author: Adis
 *
 * Created on den 26 februari 2016, 19:15
 */

#ifndef CD_H
#define	CD_H

#include <string>
#include "Rentalobject.h"

using namespace std;

class CD : public Rentalobject {
public:

    CD(string cdArtist, string cdTitle, string cdPlayTime) {
        artist = cdArtist;
        title = cdTitle;
        playTime = cdPlayTime;
    }
    
    string getTitle() {
        return title;
    }
    
    string getAuthor() {
        return artist;
    }

    void print(ostream &outstream) {
        outstream << "CD\n" << artist << "\n" << getTitle() << "\n"  
        << playTime  << "\n" << getId() << "\n" << getRenterId() << endl;
    }

private:
    string artist;
    string title;
    string playTime;

};

#endif	/* CD_H */

