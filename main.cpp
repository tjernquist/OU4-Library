/* 
 * File:   main.cpp
 * Author: Adis
 *
 * Created on den 26 februari 2016, 18:36
 */

#include <cstdlib>
#include <iostream>
#include "Rentalobject.h"
#include "Fictionbook.h"
#include "NonFictionBook.h"
#include "CD.h"
#include "Journal.h"
#include "UserInterface.h"

using namespace std;

int main(int argc, char** argv) {
    
    UserInterface u;
    
    u.menu();

    return 0;
}

