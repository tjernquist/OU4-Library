/* 
 * File:   UserInterface.h
 * Author: Adis
 *
 * Created on den 5 mars 2016, 14:48
 */

#ifndef USERINTERFACE_H
#define	USERINTERFACE_H

#include "Register.h"

class UserInterface {
public:
    char initMenu();
    void choiceHandler(char c);
    void menu();
    void printHelpText();

private:
    Register reg;
    bool fileLoaded = false;
};

#endif	/* USERINTERFACE_H */

