#include "animal.h"
#include "espece.h"
#include <QString>

//========================================================================================
// ETAPE 2

Animal::Animal()
{

}

Animal::Animal(const Espece &e, const QString &nom, QString sexe, int age)
{
  m_nom = nom;
  m_sexe = sexe;
  m_especes = e;
  m_age = age;
}

QString Animal::getNom() const
{
    return m_nom;
}

Espece Animal::getEspece() const
{
    return m_especes;
}

QString Animal::getSexe() const
{
    return m_sexe;
}

int Animal::getAge() const
{
    return m_age;
}

bool Animal::estAdulte() const
{
    if (m_age > m_especes.getAgeAdulte())
    {
        return true;
    }
    else
    {
        return false;
    }
}
