#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe FenetrePrincipale.
 * \param parent Un pointeur sur le widget parent.
 */
FenetrePrincipale::FenetrePrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);

    initialiser_tables();
    creer_especes();
    creer_animaux();

    maj_animaux();
    maj_especes();

    setFixedSize( QSize(600,400) );
}

/** --------------------------------------------------------------------------------------
 * \brief Destructeur de la classe FenetrePrincipale.
 */
FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}

/** --------------------------------------------------------------------------------------
 * \brief Initialise les deux tables.
 */
void FenetrePrincipale::initialiser_tables()
{
    const QStringList headersAnimaux({tr("Nom"), tr("Espèce"), tr("Sexe"), tr("Age"), tr("Est adulte"), tr("Est captif")});
    ui->tableAnimaux->setColumnCount(6);
    ui->tableAnimaux->setHorizontalHeaderLabels(headersAnimaux);
    ui->tableAnimaux->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableAnimaux->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableAnimaux->setColumnWidth(0,150);

    const QStringList headersEspeces({tr("Nom"), tr("Age adulte")});
    ui->tableEspeces->setColumnCount(2);
    ui->tableEspeces->setHorizontalHeaderLabels(headersEspeces);
    ui->tableEspeces->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableEspeces->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableEspeces->setColumnWidth(0,150);
}

/** --------------------------------------------------------------------------------------
 * \brief Affiche l'étape 0.
 */
void FenetrePrincipale::on_action_etape_0_triggered()
{
    QMessageBox message(QMessageBox::Information, "Étape 0",
                        "Bravo ! Le programme s'exécute.\n" \
                        "Passe à l'étape 1 !");
    message.exec();
}

/** --------------------------------------------------------------------------------------
 * \brief Affiche l'étape 1.
 */
void FenetrePrincipale::on_action_etape_1_triggered()
{
    QMessageBox message(QMessageBox::Information, "Étape 1",
                        "1 - Décommenter le code des méthodes creer_especes() et maj_especes().\n" \
                        "2 - Compiler et constater les erreurs.\n" \
                        "3 - Déclarer et coder la classe Espèce pour que le programme s'exécute.\n" \
                        "Résultats attendus : L'espèce s'affiche correctement dans le tableau de l'onglet Espèces.");
    message.exec();
}

/** --------------------------------------------------------------------------------------
 * \brief Affiche l'étape 2.
 */
void FenetrePrincipale::on_action_etape_2_triggered()
{
    QMessageBox message(QMessageBox::Information, "Étape 2",
                        "1 - Décommenter le code des méthodes creer_animaux() et maj_animaux().\n" \
                        "2 - Compiler et constater les erreurs.\n" \
                        "3 - Déclarer et coder la classe Animal pour que le programme s'exécute.\n" \
                        "Résultats attendus : Les deux animaux s'affichent correctement dans le tableau de l'onglet Animaux." );
    message.exec();
}

/** --------------------------------------------------------------------------------------
 * \brief Affiche l'étape 3.
 */
void FenetrePrincipale::on_action_etape_3_triggered()
{
    QMessageBox message(QMessageBox::Information, "Étape 3",
                        "1 - Décommenter la méthode charger_especes.\n" \
                        "2 - Compiler.\n" \
                        "3 - Exécuter et charger le fichier zoo_la_fleche.\n" \
                        "4 - Constater les trois espèces dans l'onglet Espèces.\n" \
                        "5 - En vous aidant de la méthode charger_espece, coder la méthode charger_animaux.\n" \
                        "Résultats attendus : les animaux s'affichent après le chargement du fichier.");
    message.exec();
}

/** --------------------------------------------------------------------------------------
 * \brief Affiche l'étape 4.
 */
void FenetrePrincipale::on_action_etape_4_triggered()
{
    QMessageBox message(QMessageBox::Information, "Étape 4",
                        "1 - Ajouter une caractéristique à Animal.\n" \
                        "2 - Modifier le programme et le fichier zoo_la_fleche pour prendre en compte cette caractéristique."\
                        "Résultats attendus : Les animaux s'affichent correctement dans le tableau de l'onglet Animaux." );
    message.exec();
}

/** --------------------------------------------------------------------------------------
 * \brief Charge un fichier.
 */
void FenetrePrincipale::on_actionCharger_triggered()
{
    QString nom_fichier =
            QFileDialog::getOpenFileName( this, tr("Charger un fichier zoo"),
                                          "../zoo/fichier_zoos/zoos", tr("Fichier zoo (*.zoo);;"));

    if ( ! nom_fichier.isEmpty() )
    {
        QFile file(nom_fichier);

        if (! file.open(QIODevice::ReadOnly))
            QMessageBox::information(this, tr("Impossible d'ouvrir le fichier."), file.errorString());
        else
        {
            QTextStream texte(& file);
            charger_zoo( texte );
        }
    }
}

//========================================================================================
// ETAPE 1

/** --------------------------------------------------------------------------------------
 * \brief Crée les espèces par défaut.
 */
// une espèce a un nom et un age de passage à l'age adulte
void FenetrePrincipale::creer_especes()
{

    Espece e1(QString("Lion"), 4);
    m_especes.push_back( e1 );

}

/** --------------------------------------------------------------------------------------
 * \brief Met à jour la vue des espèces.
 */
void FenetrePrincipale::maj_especes()
{

    ui->tableEspeces->clearContents();
    ui->tableEspeces->setRowCount(0);

    for ( int i = 0; i != m_especes.size(); ++i )
    {
        ui->tableEspeces->insertRow(i);
        ui->tableEspeces->setItem(i,0, new QTableWidgetItem( m_especes.at(i).getNom() ) );
        ui->tableEspeces->setItem(i,1, new QTableWidgetItem( QString::number( m_especes.at(i).getAgeAdulte() ) ) );
        ui->tableEspeces->item(i,1)->setTextAlignment( Qt::AlignCenter );
    }

}

//========================================================================================
// ETAPE 2

/** --------------------------------------------------------------------------------------
 * \brief Crée les animaux par défaut.
 */
// un animal est d'une espèce, a un nom, un sexe et un age
void FenetrePrincipale::creer_animaux()
{
    Animal a1( m_especes.at(0), QString("Jacques"), QString("Male"), 8);
    m_animaux.push_back( a1 );

    Animal a2( m_especes.at(0), QString("Bernadette"), QString("Femelle"), 3);
    m_animaux.push_back( a2 );
}

/** --------------------------------------------------------------------------------------
 * \brief Met à jour la vue des animaux.
 */
void FenetrePrincipale::maj_animaux()
{
    ui->tableAnimaux->clearContents();
    ui->tableAnimaux->setRowCount(0);

    for ( int i = 0; i != m_animaux.size(); ++i )
    {
        ui->tableAnimaux->insertRow(i);
        ui->tableAnimaux->setItem(i,0, new QTableWidgetItem( m_animaux.at(i).getNom() ) );
        ui->tableAnimaux->setItem(i,1, new QTableWidgetItem( m_animaux.at(i).getEspece()->getNom() ) );
        ui->tableAnimaux->setItem(i,2, new QTableWidgetItem( QString( m_animaux.at(i).getSexe() ) ) );
        ui->tableAnimaux->item(i,2)->setTextAlignment( Qt::AlignCenter );
        ui->tableAnimaux->setItem(i,3, new QTableWidgetItem( QString::number( m_animaux.at(i).getAge() ) ) );
        ui->tableAnimaux->item(i,3)->setTextAlignment( Qt::AlignCenter );
        if ( m_animaux.at(i).estAdulte() )
            ui->tableAnimaux->setItem(i,4, new QTableWidgetItem( "Oui" ) );
        else
            ui->tableAnimaux->setItem(i,4, new QTableWidgetItem( "Non" ) );
        ui->tableAnimaux->item(i,4)->setTextAlignment( Qt::AlignCenter );
        ui->tableAnimaux->item(i,3)->setTextAlignment( Qt::AlignCenter );
        if ( m_animaux.at(i).estCaptif() )
            ui->tableAnimaux->setItem(i,5, new QTableWidgetItem( "Oui" ) );
        else
            ui->tableAnimaux->setItem(i,5, new QTableWidgetItem( "Non" ) );
    }
}

//========================================================================================
// ETAPE 3 et 4

/** --------------------------------------------------------------------------------------
 * \brief Charge le zoo à partir de son texte.
 * \param texte le texte descriptif du zoo.
 */
void FenetrePrincipale::charger_zoo(QTextStream & texte)
{
    m_especes.clear();
    m_animaux.clear();

    charger_especes(texte);
    charger_animaux(texte);

    m_especes[0].setNom( "Tigre" );

    maj_animaux();
    maj_especes();
}

/** --------------------------------------------------------------------------------------
 * \brief Charge les espèces du zoo à partir de son texte.
 * \param texte le texte descriptif du zoo.
 */
void FenetrePrincipale::charger_especes(QTextStream& texte)
{
    int nb_especes;
    texte >> nb_especes;

    for ( int i = 0; i != nb_especes; ++i )
    {
        QString nom;
        int age_adulte;

        texte >> nom >> age_adulte;

        Espece e(nom, age_adulte);
        m_especes.push_back( e );
    }
}

/** --------------------------------------------------------------------------------------
 * \brief Charge les animaux du zoo à partir de son texte.
 * \param texte le texte descriptif du zoo.
 */
void FenetrePrincipale::charger_animaux(QTextStream& texte)
{
    int nb_animaux;
    texte>>nb_animaux;

    for(int i(0); i!=nb_animaux; ++i){
        QString nom;
        Espece espece;
        QString sexe;
        int age;
        int typeEspece;
        int captif;

        texte >> nom >> typeEspece >> sexe >> age >> captif;

        Animal a(m_especes.at(typeEspece), nom, sexe, age, captif);
        m_animaux.push_back( a );
    }
}

