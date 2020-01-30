#include "fenetreprincipale.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QFile File("../zoo/stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    QApplication a(argc, argv);
    a.setStyleSheet(StyleSheet);

    FenetrePrincipale w;

    w.show();
    return a.exec();
}
