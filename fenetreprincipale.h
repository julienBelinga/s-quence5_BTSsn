#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include <QTextStream>

#include "espece.h"
#include "animal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FenetrePrincipale; }
QT_END_NAMESPACE

/**
  * \class FenetrePrincipale
  * \brief Classe représentant la fenètre principale du projet zoo.
  * \author Sébastien Angibaud
 */
class FenetrePrincipale : public QMainWindow
{
        Q_OBJECT

    public:
        FenetrePrincipale(QWidget *parent = nullptr);
        ~FenetrePrincipale();

    private slots:
        void on_action_etape_1_triggered();
        void on_actionCharger_triggered();
        void on_action_etape_2_triggered();
        void on_action_etape_3_triggered();
        void on_action_etape_4_triggered();
        void on_action_etape_0_triggered();

        void on_actionImporter_triggered();

private:
        void initialiser_tables();
        void creer_especes();
        void creer_animaux();

        void maj_animaux();
        void maj_especes();

        void charger_zoo( QTextStream & texte );
        void charger_especes( QTextStream & texte );
        void charger_animaux( QTextStream & texte );

    private:
        Ui::FenetrePrincipale *ui;

        QList<Espece> m_especes;
        QList<Animal> m_animaux;
};
#endif // FENETREPRINCIPALE_H
