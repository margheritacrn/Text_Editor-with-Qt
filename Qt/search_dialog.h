#ifndef SEARCH_DIALOG_H
#define SEARCH_DIALOG_H

#include <QDialog>



namespace Ui {
class search_dialog;
}

class search_dialog : public QDialog
{
    Q_OBJECT
    friend class Text_Editor;  //dichiaro friend text_editor in modo che possa accedere ai metodi della classe search_dialog
public:
    explicit search_dialog(QWidget *parent = nullptr);
    ~search_dialog();



signals:
   void find_button_clicked(QString);
   void dialog_closed();
   void lineEditText_changed_signal();
   void check_box_changed_signal();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_find_button_clicked();

    void on_close_clicked();
     void label_visible();  //slot per rendere visibile la label di errore, chiamato dalla connect nel metodo find di Text_Editor

     void on_checkBox_stateChanged();
     void set_label_invisible(); // slot che nasconde nuovamente il messaggio di errore

private:
    Ui::search_dialog *ui;

    bool match();
   QString lineEdit_content();

   void updateFind();


};


#endif // SEARCH_DIALOG_H
