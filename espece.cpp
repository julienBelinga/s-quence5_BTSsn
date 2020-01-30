#include "espece.h"
Espece::Espece(){
    m_nom="inconnu";
    m_ageAdulte=0;
}

Espece::Espece(QString nom, int ageAdulte){
    m_nom =nom;
    m_ageAdulte =ageAdulte;
}

void Espece::setNom(const QString &nom)
{
    m_nom = nom;
}

int Espece::getAgeAdulte() const{
    return m_ageAdulte;
}
QString Espece::getNom() const{
    return m_nom;
}

