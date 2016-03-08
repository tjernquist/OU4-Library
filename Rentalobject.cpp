#include "Rentalobject.h"

using namespace std;

int Rentalobject::current_maxid = 0;


Rentalobject::Rentalobject() {
    id = current_maxid++;
    //Initialize the object with RenterID 0, i.e. object is NOT borrowed out.
    renterID = 0;
}

