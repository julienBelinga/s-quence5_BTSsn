#ifndef ANIMAL_H
#define ANIMAL_H

#include "espece.h"

//========================================================================================
// ETAPE 2

/**
  * \class Animal
  * \brief Classe représentant un animal.
 */
class Animal
{
public:
    Animal();
    Animal(const Espece &espece,const QString &nom, QString sexe, int age);
    Animal(const Espece &espece,const QString &nom, QString sexe, int age, int captif);
    QString getNom() const;
    Espece getEspece() const;
    QString getSexe() const;
    int getAge() const;
    bool estAdulte() const;
    bool estCaptif()const;

private:
    Espece m_espece;
    QString m_nom;
    QString m_sexe;
    int m_age;
    int m_captif;
};

#endif // ANIMAL_H
