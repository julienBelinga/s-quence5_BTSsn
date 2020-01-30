#ifndef ESPECE_H
#define ESPECE_H

#include <QString>
using namespace std;

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
        Espece(const QString nom, int ageAdulte);
        QString getNom() const;
        int getAgeAdulte() const;

private:
        QString m_nom;
        int m_ageAdulte;
};

#endif // ESPECE_H
