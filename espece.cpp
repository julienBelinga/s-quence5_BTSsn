#include "espece.h"

//========================================================================================
// ETAPE 1

Espece::Espece(): m_nom(), m_ageAdulte(0)
{

}

Espece::Espece(const QString nom, int age)
{
    m_nom = nom;
    m_ageAdulte = age;
}
QString Espece::getNom() const
{
 return m_nom;
}

int Espece::getAgeAdulte() const
{
    return m_ageAdulte;
}

