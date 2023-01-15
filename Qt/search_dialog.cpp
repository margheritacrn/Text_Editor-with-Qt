#include "search_dialog.h"
#include "ui_search_dialog.h"
#include <iostream>


search_dialog::search_dialog(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::search_dialog)
{
    ui->setupUi(this);



}

/** @brief funzione per rendere fruibile il pulsante find
 */
void search_dialog::updateFind(){
    ui->find_button->setEnabled(true);

}
search_dialog::~search_dialog()
{
    delete ui;
}

/**
 * @brief slot lanciato a seguito dell'inserimento di una stringa nella line edit
 *         permette di abilitare il pulsante find, così come di disabilitarlo se la lineEdit ritorna vuota. Nel metodo, se viene inserito del testo nella line edit viene chiamato il metodo updateFind()
 * @param arg1
 */
void search_dialog::on_lineEdit_textChanged(const QString &arg1)
{
   if(arg1!="") {   //se viene inserito del testo nella lineEdit viene abilitato il pulsante find
   updateFind();
   if(ui->find_button->isEnabled()){
     QObject::connect(this,SIGNAL(lineEditText_changed_signal()),this,SLOT(set_label_invisible()));  //una volta cercata una parola (quindi nel mentre find è abilitato)che non viene trovata se si desidera effettuare una nuova
     //ricerca, quando la parola non trovata viene cancellata, la label di errore sparisce
     QObject::connect(this,SIGNAL(check_box_changed_signal()),this,SLOT(set_label_invisible())); //se una parola non viene trovata con il match case è possibile che venga trovata senza match case, quindi disabilito la label se il matchcase viene disattivato.


     emit lineEditText_changed_signal(); // in Text_Editor my_undo() deve essere chiamata dopo che una stringa è stata cercata, dunque quando find è abilitato, ecco perché ho messo qui il segnale
}
   }
   else{
       ui->find_button->setEnabled(false);  //se la lineEdit rimane vuota il pulsante find non è abilitato
   }
}

bool search_dialog::match(){ //metodo per permettere all'editor di sapere se c'è il match o meno
    return ui->checkBox->isChecked();
}
QString search_dialog::lineEdit_content(){  //metodo per passare all'editor la stringa da cercare
    return ui->lineEdit->text();
}

//slot lanciato quando viene premuto il tasto find
//la funzione lancia un segnale che scatena la connect nello slot dopo il click su cerca in text_editor.cpp, inoltre invia a textedit il testo della lineEdit
void search_dialog::on_find_button_clicked()
{
    emit find_button_clicked(ui->lineEdit->text());

}

void search_dialog::label_visible(){  //slot chiamato nella funzione find del text editor quando nessuna stringa viene trovata. La label di errore viene resa visibile
    ui->error_label->setEnabled(true);
    ui->error_label->setVisible(true);


}
void search_dialog::set_label_invisible(){
    ui->error_label->setEnabled(false);
    ui->error_label->setVisible(false);

}


/** lo slot seguente, quando viene chiusa la search_dialog emette un segnale, catturato dal text editor in modo che vengano annullate le evidenziature. Inoltre viene cancellato il testo precedente.
 */
void search_dialog::on_close_clicked()
{
    ui->lineEdit->setText("");
    ui->error_label->setVisible(false);
    ui->error_label->setEnabled(false);
    emit dialog_closed();
}


void search_dialog::on_checkBox_stateChanged()   //quando viene attivato/disattivato il match case viene emesso un segnale
{   if(!(ui->lineEdit->text().isEmpty()))
    emit check_box_changed_signal();
}

