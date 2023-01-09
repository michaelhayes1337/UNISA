#include <QCoreApplication>
#include "coordinate.h"
#include <iostream>
#include <QChar>
#include <QTextStream>
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Code Start
    //QT Utility
    QTextStream cout(stdout);
    QStringList list;
    QString line;
    QString after;
    //Initialisation variables
    int deg = 0;
    int min = 0;
    int sec = 0;
    QChar dir;
    //QDialog
    int answer = 0;
    int feedback = 0;
    bool ok = true;
    //Verification
    bool verifiedNum = true;
    bool verifiedChar = false;
    QString directions("N,E,S,W");
    QStringList verifyDir = directions.split(",");

    do {
        //Get User Inout
        line = QInputDialog::getText(0, "Coordinator","Enter the coordinate:", QLineEdit::Normal,"", &ok);
        list = line.split(" ");
        //parse through input
        for(int i = 0 ; i < list.size(); i ++){
            switch (i) {
                case 0:
                    deg = list.at(i).toInt();
                    break;
                case 1:
                    min = list.at(i).toInt();
                    break;
                case 2:
                    sec = list.at(i).toInt();
                    break;
                case 3:
                    dir = list.at(i)[0];
                    break;
                default:
                    break;
            }
        }
        //Verify input
        if(deg < 0 || deg > 179){
            verifiedNum = false;
        }
        if(min < 0 || min > 59){
            verifiedNum = false;
        }
        if(sec < 0 || sec > 59){
            verifiedNum = false;
        }
        for(int i = 0 ; i < verifyDir.size(); i ++){
            if(QString::compare(dir, verifyDir.at(i)[0], Qt::CaseInsensitive) == 0){
                verifiedChar = true;
            }
        }
        if(verifiedNum == true && verifiedChar == true){
            Coordinate c1(deg,min,sec,dir);
            QString converted = c1.toString() + "\n" + QString::number(c1.toDecimal()) ;
            verifiedChar = false;
            feedback = QMessageBox::question(0, "Coordinator", converted , QMessageBox::Ok);
        }else{
            verifiedChar = false;
            verifiedNum = true;
            feedback = QMessageBox::question(0, "Coordinator", "invalid Input" , QMessageBox::Ok);
        }
        answer = QMessageBox::question(0, "Coordinate Created", "Do you have more coordinates ?", QMessageBox::Yes | QMessageBox::No);
    } while (answer == QMessageBox::Yes);

    return a.exec();
}
