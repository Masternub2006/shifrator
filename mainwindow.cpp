#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sohr = ui->pushButton;
    mena = ui->pushButton_2;
    SohrVFile = ui->checkBox;
    rus = ui->radioButton;
    eng = ui->radioButton_2;
    this->setWindowTitle("Shifrovik");
    rus->setChecked(true);
    ui->textEditVih->setReadOnly(true);
    connect(sohr, &QPushButton::clicked, [=] {this->Zapis();}); //this, Cezar("qoindm", 8));
    connect(mena, &QPushButton::clicked, [=] {this->Menyai();});
    connect(SohrVFile, &QCheckBox::stateChanged, [=] {this->Adres();});
    connect(rus, &QRadioButton::toggled, [=] {this->Perevod(true);});
    connect(eng, &QRadioButton::toggled, [=] {this->Perevod(false);});
    Perevod(true);
}

int MainWindow::Adres()
{
    adres = ui->lineEdit;
    nazv = ui->lineEdit_2;
    if(adres->isReadOnly()&&nazv->isReadOnly())
    {
        adres->setReadOnly(false);
        nazv->setReadOnly(false);
    }
    else
    {
        adres->setReadOnly(true);
        nazv->setReadOnly(true);
        adres->clear();
        nazv->clear();
    }
    return 0;
}

int MainWindow::Menyai()
{
    vih = ui->textEditVih;
    vh = ui->textEditVh;
    QString a = vih->toPlainText();
    vih->setText(vh->toPlainText());
    vh->setText(a);
    filebol=false;
    return 0;
}

int MainWindow::Zapis()
{
    shifrovka *vizov;
    vih = ui->textEditVih;
    vh = ui->textEditVh;
    Kl = ui->textEditKl;
    vibor = ui->comboBox;
    if(ui->checkBox_2->isChecked())
    {
        if(filebol)
        {
            FileText *filek;
            vh->setText(filek->Vsyat(filetextov));
        }
        else
        {
            FileText *filek;
            filetextov = vh->toPlainText();
            vh->setText(filek->Vsyat(filetextov));
            filebol=true;
        }
    }
    if(ui->radioButton->isChecked())
    {
        switch (vibor->currentIndex())
        {
        case 0://Cezar Rus
        {
            int klu = Kl->toPlainText().toInt();
            if (klu<0||klu>26)
            {
                vih->setText("Error");
            }
            else
            {
                vih->setText(vizov->CezarRus(vh->toPlainText(), klu));
            }
            break;
        }
        case 2://Vizher Rus
        {
            QString klu = Kl->toPlainText();
            if(klu.length()==0)
            {
                vih->setText("Error");
            }
            else
            {
                vih->setText(vizov->VizherRus(vh->toPlainText(), klu));
            }
            break;
        }
        case 4://Morze Rus
        {
            vih->setText(vizov->MorzeRus(vh->toPlainText()));
            break;
        }
        case 6://Polibi Rus
        {
            vih->setText(vizov->PolibiRus(vh->toPlainText()));
            break;
        }
        case 1://Cezar Rus Dec
        {
            int klu = Kl->toPlainText().toInt();
            if (klu<0||klu>26)
            {
                vih->setText("Error");
            }
            else
            {
                vih->setText(vizov->CezarDecRus(vh->toPlainText(), klu));
            }
            break;
        }
        case 3://Vizher Rus Dec
        {
            QString klu = Kl->toPlainText();
            if(klu.length()==0)
            {
                vih->setText("Error");
            }
            else
            {
                vih->setText(vizov->VizherDecRus(vh->toPlainText(), klu));
            }
            break;
        }
        case 5://Morze Rus Dec
        {
            vih->setText(vizov->MorzeDecRus(vh->toPlainText()));
            break;
        }
        case 7://Polibi Rus Dec
        {
            vih->setText(vizov->PolibiDecRus(vh->toPlainText()));
            break;
        }
        case 8:
        {
            vih->setText("It can only be in English");
            break;
        }
        case 9:
        {
            vih->setText("It can only be in English");
            break;
        }
        default:
        {
            vih->setText("Error");
            break;
        }
        }
    }
    else
    {
        switch (vibor->currentIndex())
        {
        case 0://Cezar en
        {
            int klu = Kl->toPlainText().toInt();
            if (klu<0||klu>26)
            {
                vih->setText("Error");
            }
            else
            {
                vih->setText(vizov->Cezar(vh->toPlainText(), klu));
            }
            break;
        }
        case 2://Vizher en
        {
            QString klu = Kl->toPlainText();
            if(klu.length()==0)
            {
                vih->setText("Enter the correct key");
            }
            else
            {
                vih->setText(vizov->Vizher(vh->toPlainText(), klu));
            }
            break;
        }
        case 4://Morze en
        {
            vih->setText(vizov->Morze(vh->toPlainText()));
            break;
        }
        case 6://Polibi en
        {
            vih->setText(vizov->Polibi(vh->toPlainText()));
            break;
        }
        case 1://Cezar en Dec
        {
            int klu = Kl->toPlainText().toInt();
            if (klu<0||klu>26)
            {
                vih->setText("Error");
            }
            else
            {
                vih->setText(vizov->CezarDec(vh->toPlainText(), klu));
            }
            break;
        }
        case 3://Vizher en Dec
        {
            QString klu = Kl->toPlainText();
            if(klu.length()==0)
            {
                vih->setText("Error");
            }
            else
            {
                vih->setText(vizov->VizherDec(vh->toPlainText(), klu));
            }
            break;
        }
        case 5://Morze en Dec
        {
            vih->setText(vizov->MorzeDec(vh->toPlainText()));
            break;
        }
        case 7://Polibi en Dec
        {
            vih->setText(vizov->PolibiDec(vh->toPlainText()));
            break;
        }
        case 8://Secret
        {
            break;
        }
        case 9://Secret
        {
            break;
        }
        default:
        {
            vih->setText("Error");
            break;
        }
        }
    }
    adres = ui->lineEdit;
    nazv = ui->lineEdit_2;
    if(ui->checkBox->isChecked())
    {
        if(adres->text()=="Gaster"&&nazv->text()=="Blaster"&&!SecretKey)
        {
            vibor->addItem("Windings encryption");
            vibor->addItem("Windings decoding");
            SecretKey=1;
        }
        else
        {
            FileText *filek;
            vih->setText(filek->Zapisat(vih->toPlainText(), adres->text(), nazv->text()));
            vh->setText(filetextov);
        }
    }
    return 0;
}

int MainWindow::Perevod(bool radiobut)
{
    vibor = ui->comboBox;
    //int shifr = vibor->currentIndex();
    bool a = false;
    if(radiobut) //русский
    {
        if(!pere)
        {
            pere=true; //сделал русский
            ui->label->setText("Ключ:");
            ui->label_2->setText("Ввод:");
            ui->label_3->setText("Вывод:");
            ui->label_4->setText("Название файла:");
            ui->checkBox->setText("Сохранить в файл:");
            ui->checkBox_2->setText("Взять из файла");
            ui->pushButton->setText("Зашифровать");
            ui->pushButton_2->setText("Поменять местами");
            vibor->addItem("Шифрование с помощью шифра Цезаря");
            vibor->addItem("Дешифрование с помощью шифра Цезаря");
            vibor->addItem("Шифрование с помощью шифра Вижинера");
            vibor->addItem("Дешифрование с помощью шифра Вижинера");
            vibor->addItem("Шифрование азбукой Морзе");
            vibor->addItem("Дешифрование азбукой Морзе");
            vibor->addItem("Шифрование квадратом Полибия");
            vibor->addItem("Дешифрование квадратом Полибия");
            vibor->setCurrentIndex(vibor->currentIndex()+8);
            if (SecretKey)
            {
                vibor->addItem("Шифр Виндингс (только на англ)");
                vibor->addItem("Расшифровка Виндингс (только на англ)");
                vibor->setCurrentIndex(vibor->currentIndex()+2);
                vibor->removeItem(0);
                vibor->removeItem(0);
            }
            for(int i = 0; i<8; i++)
            {
                vibor->removeItem(0);
            }
        }
    }
    else //english
    {
        if(pere)
        {
            pere=false; //сделал английский
            ui->label->setText("Key:");
            ui->label_2->setText("Input:");
            ui->label_3->setText("Output:");
            ui->label_4->setText("File name:");
            ui->checkBox->setText("Save to a file:");
            ui->checkBox_2->setText("Take from the file");
            ui->pushButton->setText("Encrypt");
            ui->pushButton_2->setText("Swap");
            vibor->addItem("The Caesar cipher encryption");
            vibor->addItem("The Caesar cipher decoding");
            vibor->addItem("The Vizhiner cipher encryption");
            vibor->addItem("The Vizhiner cipher decoding");
            vibor->addItem("Morse code encryption");
            vibor->addItem("Morse code decoding");
            vibor->addItem("Polybius square encryption");
            vibor->addItem("Polybius square decoding");
            vibor->setCurrentIndex(vibor->currentIndex()+8);
            if (SecretKey)
            {
                vibor->addItem("Windings encryption");
                vibor->addItem("Windings decoding");
                vibor->setCurrentIndex(vibor->currentIndex()+2);
                vibor->removeItem(0);
                vibor->removeItem(0);
            }
            for(int i = 0; i<8; i++)
            {
                vibor->removeItem(0);
            }
        }
    }
    return 0;
}



MainWindow::~MainWindow()
{
    delete ui;
    delete sohr;
    delete vih;
}
