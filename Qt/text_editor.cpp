#include "text_editor.h"
#include "ui_text_editor.h"



Text_Editor::Text_Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Text_Editor)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    current_filename="";
    d= new search_dialog(this);  //il parent di d è la mainwindow. Al termine del programma d viene distutta con la distruzione di Text_Editor
}

Text_Editor::~Text_Editor()
{
    delete d;
    d=nullptr;
    delete ui;

}


/** @brief slot eseguito dopo il click su Nuovo:
 *
*/
void Text_Editor::on_actionNuovo_triggered()
{
    QFile file("Nuovo.txt");   //creazione del nuovo file
    current_filename="Nuovo.txt";  //aggiorno l'attributo
    if(file.open(QIODevice::ReadWrite)){
        QTextStream in(&file);  //per menadare il contenuto del file sul textedit

        QString text=in.readAll();
        ui->textEdit->setPlainText(text);
        ui->textEdit->setPlainText("the file has been created");  //stampa di debug
        file.close();
        ui->actionCerca_stringa->setEnabled(true);  //abilito la funzione cerca
}
            else{  //se il file non viene creato correttamente, quindi se non si apre, appare una box con un messaggio di errore
        QMessageBox error_msg;  //la istanzio sullo stack perché non ha senso che eista a livello globale
        error_msg.setText("ERROR");
        error_msg.setInformativeText("impossible to open the file");
        error_msg.exec();

}

}

/** @brief  slot eseguito dopo il click su Apri
 *  */
void Text_Editor::on_actionApri_triggered()
{
    //scelta del file con estensione .txt
     QString filename= QFileDialog::getOpenFileName(this,"Open a file", QDir::currentPath(), "*.txt");  //QDir::currentPath() permette di aprire i file dalla cartella corrente
      //creazione dell'oggetto QFile corrispondente al file selezionato
       QFile file(filename);


       if (!file.open(QIODevice::ReadWrite)) {   //verifco che il file si apra, altrimenti viene mostrato un messaggio di errore.Apro il file sia in scrittura che in lettura poichè devono essere abilitate le modifiche
           std::cerr << "Cannot open file for writing or reading: "
            << qPrintable(file.errorString())
            << std::endl;
       return;
       }
    //se il file si apre:
       current_filename=filename;   //aggiornamento dell'attributo della classe Text_Editor se l'apertura del file ha successo
       //leggo il contenuto del file e lo mando sul textEdit che costituisce parte dell'interfaccia
       QTextStream in(&file);
       QString text=in.readAll();
       ui->textEdit->setText(text);  //spedisco al widget textedit il contenuto del file di testo da aprire
       file.close();
       ui->actionCerca_stringa->setEnabled(true);  //abilito la funzione cerca
}

/** slot eseguito dopo il click su Salva
 *  */
void Text_Editor::on_actionSalva_triggered()
{
    QFile file(current_filename);  //il file da salvare è quello attualmente aperto
    //verifico che il file sia aperto altrimenti non ha senso salvare. Se il file non è aperto appare un messaggio di errore
   if(!file.open((QIODevice::ReadWrite))) {
       std::cerr << "Cannot save the file  "
        << qPrintable(file.errorString())
        << std::endl;
            return;
   }
   QTextStream out(&file);
   QString text=ui->textEdit->toPlainText();
   out << text;
   file.close();

}

/** @brief slot eseguito a seguito del signal (click) ricevuto da Salva con nome
 *         la funzione salva il file aperto permettendo di cambiarne il nome, se l'operazione fallisce viene mostrato un messaggio di errore
 *  */
void Text_Editor::on_actionSalva_con_nome_triggered()
{
  QString new_name = QFileDialog::getSaveFileName(this, "Salva come", QDir::currentPath(), "(*.txt)");   //salvo il file nella directory corrente e impongo che l'estensione sia .txt
  QFile file(new_name);

    current_filename=new_name;  //aggiorno il nome

  //verifico che il file sia aperto, se non lo è appare un messaggio di errore
 if(!file.open((QIODevice::ReadWrite))) {
     std::cerr << "Cannot save as "
      << qPrintable(file.errorString())
      << std::endl;
     return;
 }

 QTextStream out(&file);
 QString text=ui->textEdit->toPlainText();  //ricavo il contenuto dal widget (operazione inversa rispetto ad open)
 out << text;
 file.close();

}


/** @brief  slot lanciato dopo il click su "Cerca stirnga"
 *  la funzione apre la dialog che permette la ricerca di una stringa nel testo
 *
 *  */
void Text_Editor::on_actionCerca_stringa_triggered(){


    d->show();  //appare la search dialog

    QObject::connect(d, SIGNAL(find_button_clicked(QString)),this,SLOT(find(QString)));  //se il pulsante find viene premuto  lo slot che
   //permette di evidenziare le stringhe viene preso in carico dal text editor
//(sicuramente se find viene premuto c'è del testo sia nel textEdit che nella LineEdit perché altrimenti il pulsante è disabilitato)

}
/** @brief slot emesso dopo un click sul pulsante find della dialog
 */
void Text_Editor::find(QString){

   QString searching_for=d->lineEdit_content();// stringa da cercare
   QString text=ui->textEdit->toPlainText();  //testo del file aperto




   int size=searching_for.size();  //lunghezza della stringa

    QString current_string;   //stringa che permetterà di scorrere il testo
    QTextCursor cursor = ui->textEdit->textCursor();  //cursore nel textEdit per selezionare la stinga che verà poi evidenziata cambiando il char format con fmt
    QTextCharFormat fmt;
    fmt.setBackground(Qt::yellow);
    QStringMatcher s;  //sfrutto i metodi di tale oggetto per cercare tutte le occorrenze della stringa inserita nella lineEdit

    if((d->match()&&text.count(searching_for,Qt::CaseSensitive)!=0)||((!d->match())&&text.count(searching_for, Qt::CaseInsensitive)!=0)){  //verifico che nel testo ci sia la stringa da cercare (non entro nell'if se la stringa non c'è sia con il case sensitive che senza)


        if(d->match()){  //se c'è il match case la ricerca deve essere case sensitive
            s.setCaseSensitivity((s.caseSensitivity()));
        }
        else{
            searching_for=searching_for.toLower(); //se la ricerca non deve essere case sensitive metto minuscole tutte le lettere e lo stesso farò per la stringa che permette di scorrere il testo nel ciclo for sotto.
        }


         s.setPattern(searching_for);  //inserisco nel matcher la stringa da cercare

    int j=0, k=0;  // j rappresenta l'indice della stringa current_string in corrispondenza del quale si trova il primo carattere della stringa da cercare, ritornato dal metodo indexIn()
    //k è un indice che serve per aggiornare current_string dopo che un'occorrenza di serching_for è stata trovata
    //current_string deve ripartire da text[k], che rappresenta il carattere di text successivo alla fine della stringa seraching_for trovata nel testo

    for(int i=0; i<text.size(); ++i){
       current_string+=(text[i]);
       if(!d->match()){
           current_string=current_string.toLower();  //se il match case non è attivato metto tutti i caratteri minuscoli


       }

       j= s.indexIn(current_string);  //primo indice della stringa pattern all'interno di current_string, ritorna -1 se current_string non contiene la stringa cercata

        if(j!=-1){


            cursor.setPosition(j+k, QTextCursor::MoveAnchor);  //seleziono tramite il cursore la stringa cercata e la evidenzio


            cursor.setPosition(j+ k+size, QTextCursor::KeepAnchor);
            cursor.setCharFormat(fmt);

            k+=j+size+1;

            current_string.clear(); // current_string=""; //resetto la stringa che scorre il testo
            if(k<text.size()-1)  // l'if serve una delle occorrenze della stringa è l'ultima parola del testo
            current_string+=(text[k]);
            i=k;  //aggiorno i perché la ricerca deve riprtire da text[k]

        }
    }
     QObject::connect(d,SIGNAL( lineEditText_changed_signal()), this, SLOT(my_undo()));   //se dopo la prima ricerca si cambia la stringa da cercare il file viene ripulito dalle precedenti evidenziature
     //con lo slot my_undo()
      QObject::connect(d,SIGNAL(check_box_changed_signal()),this, SLOT(my_undo()));  //se viene messo il match case le modifiche vengono annullate
      //così come quando la dialog viene chiusa
      QObject::connect(d,SIGNAL(dialog_closed()),this,SLOT(my_undo()));


}
 else{  //se la stringa non c'è deve essere reso visibile il messaggio di errore contenuto nella search_dialog, uso una connect ed emetto un segnale che verrà ricevuto da search_dialog

    QObject::connect(this,SIGNAL(string_not_found()),d,SLOT(label_visible()));
    emit string_not_found();


    }


}

void Text_Editor::my_undo(){  //per annullare le evidenziature evidenzio tutto il testo del textEdit di bianco
  QString text=ui->textEdit->toPlainText();
  QTextCharFormat fmt;
  fmt.setBackground(Qt::white);
    QTextCursor cursor(ui->textEdit->textCursor());
    cursor.setPosition(0,QTextCursor::MoveAnchor);
    cursor.setPosition(text.size(), QTextCursor::KeepAnchor);
    cursor.setCharFormat(fmt);


}




