#include "Multinational.h"

// Constructors/Destructors
//

Multinational::Multinational () {
initAttributes();
}

Multinational::~Multinational () { }

//
// Methods
//


// Accessor methods
//


/**
 * Add a Societes_Ecran object to the m_societes_ecranVector List
 */
void Multinational::addSocietes_Ecran (Country add_object) {
  m_societes_ecranVector.push_back(add_object);
}

/**
 * Remove a Societes_Ecran object from m_societes_ecranVector List
 */
void Multinational::removeSocietes_Ecran (Country remove_object) {
  int i, size = m_societes_ecranVector.size();
  for (i = 0; i < size; ++i) {
  	Country item = m_societes_ecranVector.at(i);
  	if(item == remove_object) {
  		std::vector<Country>::iterator it = m_societes_ecranVector.begin() + i;
  		m_societes_ecranVector.erase(it);
  		return;
  	}
   }
}

/**
 * Get the list of Societes_Ecran objects held by m_societes_ecranVector
 * @return std::vector<Country *> list of Societes_Ecran objects held by
 * m_societes_ecranVector
 */
std::vector<Country> Multinational::getSocietes_EcranList () {
  return m_societes_ecranVector;
}

// Other methods
//

void Multinational::initAttributes () {
  //m_continent = new Continent();
}

