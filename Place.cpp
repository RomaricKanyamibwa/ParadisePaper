#include "Place.h"

// Constructors/Destructors
//

Place::Place () {
initAttributes();
}

Place::Place(std::string Nom, int xg, int yh, int xd, int yb)
{
    Name = Nom;
    Position.push_back(xg);
    Position.push_back(yh);
    Position.push_back(xd);
    Position.push_back(yb);
}

Place::~Place () { }

//
// Methods
//


// Accessor methods
//


// Other methods
//

void Place::initAttributes () {
}

