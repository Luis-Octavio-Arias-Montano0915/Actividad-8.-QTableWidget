#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qfiledialog.h>
#include <QDebug>
#include <QTableWidgetItem>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    void printList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
};

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->Res->setText(QString::number(ui->Id->value()));

    ui->Res->setText(QString::number(ui->Voltaj->value()));

    ui->Res->setText(QString::number(ui->PosicionX->value()));

    ui->Res->setText(QString::number(ui->PosicionY->value()));

    ui->Res->setText(QString::number(ui->Red->value()));

    ui->Res->setText(QString::number(ui->Green->value()));

    ui->Res->setText(QString::number(ui->Blue->value()));
}


void MainWindow::on_actionGuardar_triggered()
{
    std::cout<<"Guardar"<<std::endl;
    QString Filename= QFileDialog::getOpenFileName(this, "Guardar archivo", ".", "imagenes (*.jpg)");
    std::string file= Filename.toStdString();
    std::cout<<file<<std::endl;
}


void MainWindow::on_actionAbrir_triggered()
{
    std::cout<<"Abrir"<<std::endl;
    QString Filename= QFileDialog::getOpenFileName(this, "Abrir archivo", ".", "imagenes (*.jpg)");
    std::string file= Filename.toStdString();
    std::cout<<file<<std::endl;
}




void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->setColumnCount(7);
    QStringList headers = {"Id", "Voltaje", "Posicion X", "Posicion Y", "Red", "Green", "Blue" };
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(10);
    QTableWidgetItem *id = new QTableWidgetItem("1");
    QTableWidgetItem *V = new QTableWidgetItem("150");
    QTableWidgetItem *X = new QTableWidgetItem("55");
    QTableWidgetItem *Y = new QTableWidgetItem("60");
    QTableWidgetItem *re = new QTableWidgetItem("70");
    QTableWidgetItem *gr = new QTableWidgetItem("150");
    QTableWidgetItem *bl = new QTableWidgetItem("66");


    ui->tableWidget->setItem(0,1,id);
    ui->tableWidget->setItem(0,1,V);
    ui->tableWidget->setItem(0,2,X);
    ui->tableWidget->setItem(0,3,Y);
    ui->tableWidget->setItem(0,4,re);
    ui->tableWidget->setItem(0,5,gr);
    ui->tableWidget->setItem(0,6,bl);

    ui->tableWidget->setItem(1,1,id);
    ui->tableWidget->setItem(1,1,V);
    ui->tableWidget->setItem(1,2,X);
    ui->tableWidget->setItem(1,3,Y);
    ui->tableWidget->setItem(1,4,re);
    ui->tableWidget->setItem(1,5,gr);
    ui->tableWidget->setItem(1,6,bl);

}

