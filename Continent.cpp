#include "Continent.h"

// Constructors/Destructors
//

Continent::Continent () {
}


Continent::Continent(std::string Nom, int xg, int yh, int xd, int yb): Place(Nom, xg, yh, xd, yb)
{};

Continent::Continent(std::string Nom, int xg, int yh, int xd, int yb,std::vector<Country>& countries)
:Place(Nom, xg, yh, xd, yb),countries(countries)
{};


Continent::~Continent () { }

//
// Methods
//


// Accessor methods
//


// Other methods
//


