#include "text_editor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Text_Editor w;
    w.showMaximized();  //mostro l'editor a schermo intero
    w.show();
    return a.exec();
}
