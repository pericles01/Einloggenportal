#include "window.h"

Window::Window():QWidget()
{
    setFont(QFont("arial",20,QFont::Normal,false));
    //tabs
    tab= new QTabWidget(this);
    layout=new QVBoxLayout;

    //tab->setGeometry(30,20,width(),height());
    //pages
    page1=new QWidget;
    page2=new QWidget;
    page3=new QWidget;

    //Elements Page 1
    firstName= new QLineEdit;
    secondName= new QLineEdit;
    age= new QSpinBox;
    age->setValue(20);
    age->setMinimum(10);
    age->setMaximum(100);
    origin=new QLineEdit;
    adress= new QLineEdit;
    countryList= new QComboBox;
    countryList->addItem("Deutschland");
    countryList->addItem("Frankreich");
    countryList->addItem("Großbritanien");
    countryList->addItem("China");
    countryList->addItem("Kamerun");
    countryList->addItem("Belgien");
    countryList->addItem("Netherland");
    countryList->setEditable(true);

    formLayout=new QFormLayout;
    formLayout->addRow("Vorname(n)",firstName);
    formLayout->addRow("Name(n)",secondName);
    formLayout->addRow("Alter",age);
    formLayout->addRow("Staatangehörigkeit",origin);
    formLayout->addRow("Adresse",adress);
    formLayout->addRow("Land",countryList);

    principalLayout1=new QVBoxLayout;
    principalLayout1->addLayout(formLayout);

    buttonSave= new QPushButton;
    buttonSave->setText("Speichern");
    buttonSave->setStyleSheet("background-color:red;");
    QWidget::connect(buttonSave,SIGNAL(clicked()),this,SLOT(openDialog()));
    principalLayout1->addWidget(buttonSave);
    page1->setLayout(principalLayout1);

    //Elements page2
    principalLayout2=new QVBoxLayout;
    pseudo= new QLineEdit;
    email= new QLineEdit;
    password= new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    confirmPassword= new QLineEdit;
    confirmPassword->setEchoMode(QLineEdit::Password);

    formLayout1= new QFormLayout;
    formLayout1->addRow("Pseudo",pseudo);
    formLayout1->addRow("E-Mail Adresse",email);
    formLayout1->addRow("Passwort",password);
    formLayout1->addRow("Passwort bestätigen",confirmPassword);
    principalLayout2->addLayout(formLayout1);

    buttonSave1= new QPushButton;
    buttonSave1->setText("Speichern");
    QWidget::connect(buttonSave1,SIGNAL(clicked()),this,SLOT(openDialog1()));
    principalLayout2->addWidget(buttonSave1);
    page2->setLayout(principalLayout2);
    //Elements page3
    principalLayout3=new QVBoxLayout;

    label= new QLabel;
    label->setText("Profilfoto bearbeiten");
    principalLayout3->addWidget(label);

    buttonFoto=new QPushButton;
    buttonFoto->setText("Foto hochladen");
    QWidget::connect(buttonFoto,SIGNAL(clicked()),this,SLOT(openDialog3()));
    principalLayout3->addWidget(buttonFoto);

    comment= new QTextEdit;
    formLayout2= new QFormLayout;
    formLayout2->addRow("Erzählen Sie mehr über Sie",comment);
    principalLayout3->addLayout(formLayout2);

    buttonSave2=new QPushButton;
    buttonSave2->setText("Speichern");


    QWidget::connect(buttonSave2,SIGNAL(clicked()),this,SLOT(openDialog2()));
    principalLayout3->addWidget(buttonSave2);
    page3->setLayout(principalLayout3);

    //Tabs
    tab->addTab(page1,"Persönlische Daten");
    tab->addTab(page2,"Kontoinformationen");
    tab->addTab(page3,"Profilbearbeitung");
    layout->addWidget(tab);
    setLayout(layout);
}
void Window::openDialog(){
    int reponse=QMessageBox::question(page1,"Speichern bestätigen","Möchten Sie Ihre Eingabe speichern?",QMessageBox::Save|QMessageBox::Cancel);
    if (reponse == QMessageBox::Save)
        {
            QMessageBox::information(page1, "Bestätigung", "Eingabe gespeichert");
        }
        else if (reponse == QMessageBox::Cancel)
        {
            QMessageBox::critical(page1, "Bestätigung", "Speicherung unterbrochen");
        }

}
void Window::openDialog1(){
    int reponse=QMessageBox::question(page2,"Speichern bestätigen","Möchten Sie Ihre Eingabe speichern?",QMessageBox::Save|QMessageBox::Cancel);
    if (reponse == QMessageBox::Save)
        {
            QMessageBox::information(page2, "Bestätigung", "Eingabe gespeichert");
        }
        else if (reponse == QMessageBox::Cancel)
        {
            QMessageBox::critical(page2, "Bestätigung", "Speicherung unterbrochen");
        }

}
void Window::openDialog2(){
    int reponse=QMessageBox::question(page3,"Speichern bestätigen","Möchten Sie Ihre Eingabe speichern?",QMessageBox::Save|QMessageBox::Cancel);
    if (reponse == QMessageBox::Save)
        {
            QMessageBox::information(page3, "Bestätigung", "Eingabe gespeichert");
        }
        else if (reponse == QMessageBox::Cancel)
        {
            QMessageBox::critical(page3, "Bestätigung", "Speicherung unterbrochen");
        }

}
void Window::openDialog3(){
    QString file=QFileDialog::getOpenFileName(page3,"Profilfoto hochladen",QString(),"Images((*.png *.gif *.jpg *.jpeg))");
    QMessageBox::information(page3,"Profilfoto","Sie haben: "+file+" ausgewählt");
}
