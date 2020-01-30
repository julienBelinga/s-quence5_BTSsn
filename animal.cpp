#include "animal.h"

Animal::Animal(const Espece &espece, const QString &nom, QString sexe, int age){
    m_espece = espece;
    m_nom = nom;
    m_sexe = sexe;
    m_age = age;
}

Animal::Animal(const Espece &espece, const QString &nom, QString sexe, int age, int captif){
    m_espece = espece;
    m_nom = nom;
    m_sexe = sexe;
    m_age = age;
    m_captif = captif;
}

QString Animal::getNom() const{
    return m_nom;
}
Espece Animal::getEspece() const{
    return m_espece;
}
QString Animal::getSexe() const{
    return m_sexe;
}
int Animal::getAge() const{
    return m_age;
}

bool Animal::estAdulte() const{
    if (m_espece.getAgeAdulte() < m_age)
        return (false);
    else
        return (true);
}

bool Animal::estCaptif() const{
    if (m_captif == 1)
        return (false);
    else
        return (true);
}
