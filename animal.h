#ifndef ANIMAL_H
#define ANIMAL_H

#include "espece.h"
#include <iostream>
#include <QString>
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
        Animal(const Espece & especes, const QString & nom, QString sexe, int age);
        QString getNom() const ;
        QString getSexe() const ;
        Espece getEspece() const;
        int getAge() const;
        bool estAdulte() const;

    private:
      Espece m_especes;
      QString m_sexe;
      QString m_nom;
      int m_age;
};

#endif // ANIMAL_H
