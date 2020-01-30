#ifndef ESPECE_H
#define ESPECE_H

#include <QString>

//========================================================================================
// ETAPE 1


/**
  * \class Espece
  * \brief Classe représentant une espèce d'animal.
 */
class Espece
{
public:
    Espece();
    Espece(QString nom, int ageAdulte);

private :
    QString m_nom;
    int m_ageAdulte;

public:
    QString getNom()const;
    int getAgeAdulte()const;
    void setNom(const QString &nom);
};

#endif // ESPECE_H
