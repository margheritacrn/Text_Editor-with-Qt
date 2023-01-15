#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>   //per aprire e salvare con nome i file
#include <iostream>
#include <QDir>  //per ottenere la directory corrente
#include <QTextStream>
#include <QColor>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QStringMatcher>
#include <QMessageBox>
#include "search_dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Text_Editor; }
QT_END_NAMESPACE

class Text_Editor : public QMainWindow
{
    Q_OBJECT


public:
    Text_Editor(QWidget *parent = nullptr);
    ~Text_Editor();


signals:
    void string_not_found();
    void check_box_changed(); //segnale che serve per ripulire
private slots:
    void on_actionNuovo_triggered();

    void on_actionApri_triggered();

    void on_actionSalva_triggered();

    void on_actionSalva_con_nome_triggered();

    void on_actionCerca_stringa_triggered();

    void find(QString);  //slot per iniziare la ricerca della stringa inserita nella label della dialog che quando viene premuto find lancia un segnale.
    void my_undo();  //slot per annullare le eventuali evidenziature



private:
    Ui::Text_Editor *ui;
    QString current_filename; //nome del file corrente
    search_dialog *d;  //puntatore alla dialog che permette la funzione cerca





};
#endif // TEXT_EDITOR_H
