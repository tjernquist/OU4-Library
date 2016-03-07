#include "Rentalobject.h"

using namespace std;

int Rentalobject::current_id = 0;


Rentalobject::Rentalobject() {
    id = current_id++;
    //Initialize the object with RenterID 0, i.e. object is NOT borrowed out.
    renterID = 0;
}

