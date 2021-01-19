#ifndef WINDOW_H
#define WINDOW_H
#include <QtWidgets/QApplication>
#include <QtWidgets>

class Window: public QWidget
{
    Q_OBJECT
    public:
        Window();
    public slots:
        void openDialog();
        void openDialog1();
        void openDialog2();
        void openDialog3();
    private:
        //Tabs
        QTabWidget *tab;
        //Pages
        QWidget *page1;
        QWidget *page2;
        QWidget *page3;
        //Layout pages
        QVBoxLayout *layout;
        QVBoxLayout *principalLayout1;
        QVBoxLayout *principalLayout2;
        QVBoxLayout *principalLayout3;
        //Elements Page 1
        QLineEdit *firstName;
        QLineEdit *secondName;
        QSpinBox *age;
        QLineEdit *adress;
        QLineEdit *origin;
        QComboBox *countryList;
        QFormLayout *formLayout;
        QPushButton *buttonSave;

        //Elements Page 2
        QLineEdit *pseudo;
        QLineEdit *email;
        QLineEdit *password;
        QLineEdit *confirmPassword;
        QFormLayout *formLayout1;
        QPushButton *buttonSave1;
        //Elements Page 3
        QLabel *label;
        QTextEdit *comment;
        QPushButton *buttonSave2;
        QPushButton *buttonFoto;
        QFormLayout *formLayout2;




};

#endif // WINDOW_H
