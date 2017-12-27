#include "Country.h"

// Constructors/Destructors
//

Country::Country () {
initAttributes();
}

Country::Country(std::string Nom, int xg, int yh, int xd, int yb): Place(Nom, xg, yh, xd, yb)
{
}


Country::~Country () { }

//
// Methods
//


// Accessor methods
//


// Other methods
//

void Country::initAttributes () {
}

