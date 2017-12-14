#include "Pays.h"

// Constructors/Destructors
//

Pays::Pays () {
initAttributes();
}

Pays::Pays(std::string Nom, int xg, int yh, int xd, int yb): Place(Nom, xg, yh, xd, yb)
{
}


Pays::~Pays () { }

//
// Methods
//


// Accessor methods
//


// Other methods
//

void Pays::initAttributes () {
}

