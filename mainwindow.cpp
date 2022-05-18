#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string>
#include <vector>

using std::stoi, std::stof;

#include <QHeaderView>

#include "Pastry.h"
#include "Controller.h"

void MainWindow::filltable(QTableWidget *table, vector<Pastry> all)
{
    table->clearContents();
    table->setRowCount(all.size());
    table->setHorizontalHeaderLabels({"ID","Name","Stock","Price","Sugar","Type"});
    table->horizontalHeader()->setStyleSheet("::section { background-color: #FF5733; color: white; border: none}");
    table->verticalHeader()->setVisible(false);
    for(unsigned int i=0; i < all.size(); i++)
    {
        table->takeVerticalHeaderItem(i);
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(all.at(i).getId())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(all.at(i).getName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(all.at(i).getStock())));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(all.at(i).getPrice())));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(all.at(i).getSugar())));
        table->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(all.at(i).getTypeStr())));
    }

    //we make the tabel respond
    table->resizeColumnToContents(0);
    table->resizeColumnToContents(1);
    table->resizeColumnToContents(2);
    table->resizeColumnToContents(3);
    table->resizeColumnToContents(4);
    table->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::handleAdd()
{
    QString IdQString = m_IdLineEdit->text();
    std::string IdStdString = IdQString.toStdString();

    QString nameQString = m_nameLineEdit->text();
    std::string nameStdString = nameQString.toStdString();

    QString StockQString = m_StockLineEdit->text();
    std::string StockStdString = StockQString.toStdString();
    int StockValue = 0;
    try{
        StockValue = stoi(StockStdString);
    }catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
         return;
    }

    QString PriceQString = m_PriceLineEdit->text();
    std::string PriceStdString = PriceQString.toStdString();
    float PriceValue = 0.0;
    try{
        PriceValue = stof(PriceStdString);
    } catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
         return;
    }

    QString SugarQString = m_SugarLineEdit->text();
    std::string SugarStdString = SugarQString.toStdString();
    float SugarValue = 0.0;
    try{
        SugarValue = stof(SugarStdString);
    }catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
         return;
    }

    QString TypeQString = m_TypeLineEdit->text();
    std::string TypeStdString = TypeQString.toStdString();

    if(nameStdString == "" || IdStdString == "" || TypeStdString == "")
       { QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
        return;
          }

    try{
         this->ctrl->add(Pastry(IdStdString,nameStdString,StockValue,PriceValue,SugarValue,TypeStdString));
    }catch(const RepoException &re)
   {
       QMessageBox::critical(nullptr, "Critical error!", "This element already exists, consider Updating It", QMessageBox::Ok );
    }
    filltable(m_TableWidget, this->ctrl->GetContent());
    filltable(m_SortedTable, this->ctrl->GetContent());
}

void MainWindow::handleUpdate()
{
    QString IdQString = m_IdLineEdit->text();
    std::string IdStdString = IdQString.toStdString();

    QString nameQString = m_nameLineEdit->text();
    std::string nameStdString = nameQString.toStdString();

    QString StockQString = m_StockLineEdit->text();
    std::string StockStdString = StockQString.toStdString();
    int StockValue = 0;
    try{
        StockValue = stoi(StockStdString);
    }catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
         return;
    }

    QString PriceQString = m_PriceLineEdit->text();
    std::string PriceStdString = PriceQString.toStdString();
    float PriceValue = 0.0;
    try{
        PriceValue = stof(PriceStdString);
    } catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
         return;
    }

    QString SugarQString = m_SugarLineEdit->text();
    std::string SugarStdString = SugarQString.toStdString();
    float SugarValue = 0.0;
    try{
        SugarValue = stof(SugarStdString);
    }catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
         return;
    }

    QString TypeQString = m_TypeLineEdit->text();
    std::string TypeStdString = TypeQString.toStdString();

    if(nameStdString == "" || IdStdString == "" || TypeStdString == "")
       { QMessageBox::critical(nullptr, "Critical error!", "Fill all the fields before submiting", QMessageBox::Ok );
        return;
          }

    try{
         this->ctrl->update(Pastry(IdStdString,nameStdString,StockValue,PriceValue,SugarValue,TypeStdString));
    }catch(const RepoException &re)
   {
       QMessageBox::critical(nullptr, "Critical error!", "This element doesn't already exists, consider Adding It", QMessageBox::Ok );
    }
    filltable(m_TableWidget, this->ctrl->GetContent());
    filltable(m_SortedTable, this->ctrl->GetContent());
}

void MainWindow::handleRemove()
{

    if(m_TableWidget->selectedItems().isEmpty())
       {
        QMessageBox::critical(nullptr, "Critical error!", "Select Elements from the Table first", QMessageBox::Ok );
        return;
    }

    if(m_TableWidget->selectedItems().length() > 7)
    {
     QMessageBox::critical(nullptr, "Critical error!", "Select just one Element", QMessageBox::Ok );
     return;
    }

    int i =0;
    i = m_TableWidget->currentRow();
    QTableWidgetItem* m_currentElement = m_TableWidget->item(i,0);

    QString currentID = m_currentElement->text();
    std::string ID = currentID.toStdString();

    this->ctrl->del(Pastry(ID,"name",1,1,1,"sweet"));

    filltable(m_TableWidget, this->ctrl->GetContent());
    filltable(m_SortedTable, this->ctrl->GetContent());
}

void MainWindow::handleUndo()
{
    try{this->ctrl->undo();
        this->filltable(m_TableWidget, this->ctrl->GetContent());
        this->filltable(m_SortedTable, this->ctrl->GetContent());
        }catch(const RepoException &re)
         {
             QMessageBox::critical(nullptr, "Critical error!", "Can't Undo Anymore", QMessageBox::Ok );
         }
}

void MainWindow::handleRedo(){
    try{this->ctrl->redo();
        this->filltable(m_TableWidget, this->ctrl->GetContent());
        this->filltable(m_SortedTable, this->ctrl->GetContent());
        }catch(const RepoException &re)
         {
             QMessageBox::critical(nullptr, "Critical error!", "Can't Redo Anymore", QMessageBox::Ok );
         }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    int k = event->key();
    switch (k)
    {
    case Qt::Key_Z:
         qDebug() << "Z Key";
        try{this->ctrl->undo();
            this->filltable(m_TableWidget, this->ctrl->GetContent());
            this->filltable(m_SortedTable, this->ctrl->GetContent());
            }catch(const RepoException &re)
             {
                 QMessageBox::critical(nullptr, "Critical error!", "Can't Undo Anymore", QMessageBox::Ok );
             }
        break;
    case Qt::Key_Y:
        qDebug() << "Y Key";
        try{this->ctrl->redo();
            this->filltable(m_TableWidget, this->ctrl->GetContent());
            this->filltable(m_SortedTable, this->ctrl->GetContent());
            }catch(const RepoException &re)
             {
                 QMessageBox::critical(nullptr, "Critical error!", "Can't Redo Anymore", QMessageBox::Ok );
             }
        break;
    }
}

void MainWindow::handleSortID(){
    filltable(m_SortedTable, this->ctrl->GetContent());
}
void MainWindow::handleSortName(){
    filltable(m_SortedTable, this->ctrl->SortByName());
}
void MainWindow::handleSortStock()
{
    filltable(m_SortedTable, this->ctrl->SortByStock());
}
void MainWindow::handleSortPrice()
{
    filltable(m_SortedTable, this->ctrl->SortByPrice());
}
void MainWindow::handleSortSugar()
{
    filltable(m_SortedTable, this->ctrl->SortBySugar());
}
void MainWindow::handleSortType()
{
    filltable(m_SortedTable, this->ctrl->SortByType());
}

void MainWindow::handleFilterName(){
    QString nameQString = m_FNameineEdit->text();
    std::string nameStdString = nameQString.toStdString();

    if(nameStdString == "")
       { QMessageBox::critical(nullptr, "Critical error!", "Fill the Name field before Filtering by Name", QMessageBox::Ok );
        return;
          }
    filltable(m_SortedTable, this->ctrl->FilterByName(nameStdString));
}

void MainWindow::handleFilterStock()
{
    QString StockQString = m_FStockLineEdit->text();
    std::string StockStdString = StockQString.toStdString();
    int StockValue = 0;
    try{
        StockValue = stoi(StockStdString);
    }catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill the Stock Field before Filtering by Stock", QMessageBox::Ok );
         return;
    }
    filltable(m_SortedTable, this->ctrl->FilterByStock(StockValue));
}
void MainWindow::handleFilterPrice()
{
    QString PriceQString = m_FPriceLineEdit->text();
    std::string PriceStdString = PriceQString.toStdString();
    float PriceValue = 0.0;
    try{
        PriceValue = stof(PriceStdString);
    } catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill the Price Field before Filtering by Price", QMessageBox::Ok );
         return;
    }
   filltable(m_SortedTable, this->ctrl->FilterByPrice(PriceValue));
}
void MainWindow::handleFilterSugar()
{
    QString SugarQString = m_FSugarLineEdit->text();
    std::string SugarStdString = SugarQString.toStdString();
    float SugarValue = 0.0;
    try{
        SugarValue = stof(SugarStdString);
    }catch(std::invalid_argument)
    {
         QMessageBox::critical(nullptr, "Critical error!", "Fill the Sugar Field before Filtering by Sugar", QMessageBox::Ok );
         return;
    }
    filltable(m_SortedTable, this->ctrl->FilterBySugar(SugarValue));
}
void MainWindow::handleFilterType()
{
    QString TypeQString = m_FTypeLineEdit->text();
    std::string TypeStdString = TypeQString.toStdString();

    if(TypeStdString == "")
       { QMessageBox::critical(nullptr, "Critical error!", "Fill the Type field before Filtering by Type", QMessageBox::Ok );
        return;
          }
    filltable(m_SortedTable, this->ctrl->FilterByType(TypeStdString));
}

MainWindow::MainWindow(Controller *ctrl, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->ctrl = ctrl;

    /// create visual elements
    m_CentralWidget = new QWidget;

    m_formLayout = new QFormLayout();
    m_vLayout = new QVBoxLayout();

    m_IdLabel = new QLabel("ID:");
    m_IdLabel->setStyleSheet("color: #C70039 ");
    m_IdLineEdit = new QLineEdit();
    m_IdLineEdit->setPlaceholderText("Enter number (integer)");

    m_nameLabel = new QLabel("Name:");
    m_nameLineEdit = new QLineEdit();
    m_nameLineEdit->setPlaceholderText("Enter name");

    m_StockLabel = new QLabel("Stock:");
    m_StockLineEdit = new QLineEdit();
    m_StockLineEdit->setPlaceholderText("Enter stock number (integer)");

    m_PriceLabel = new QLabel("Price:");
    m_PriceLineEdit = new QLineEdit();
    m_PriceLineEdit->setPlaceholderText("Enter price (decimal)");

    m_SugarLabel = new QLabel("Sugar:");
    m_SugarLineEdit = new QLineEdit();
    m_SugarLineEdit->setPlaceholderText("Enter grams of sugar (decimal)");

    m_TypeLabel = new QLabel("Type:");
    m_TypeLineEdit = new QLineEdit();
    m_TypeLineEdit->setPlaceholderText("Enter a type : sweet, salty or bread");

    m_BtsLayout = new QHBoxLayout();

    m_addBtn = new QPushButton("Add");
    m_addBtn->setStyleSheet("background-color : #FF5733; color: white");
    connect(m_addBtn, &QPushButton::released, this, &MainWindow::handleAdd);
     m_BtsLayout->addWidget(m_addBtn);

    m_updateBtn = new QPushButton("Update");
    m_updateBtn->setStyleSheet("background-color : #FF5733; color: white");
    connect(m_updateBtn, &QPushButton::released, this, &MainWindow::handleUpdate);
    m_BtsLayout->addWidget(m_updateBtn);

    m_removeBtn = new QPushButton("Remove");
    m_removeBtn->setStyleSheet("background-color : #FF5733; color: white");
    connect(m_removeBtn, &QPushButton::released, this, &MainWindow::handleRemove);
    m_BtsLayout->addWidget(m_removeBtn);

    m_BtsUndoRedo = new QHBoxLayout();

    m_undo = new QPushButton("Undo");
    m_undo->setStyleSheet("background-color : #C70039 ; color: white");
    connect(m_undo, &QPushButton::released, this, &MainWindow::handleUndo);
    m_BtsUndoRedo->addWidget(m_undo);

    m_redo = new QPushButton("Redo");
    m_redo->setStyleSheet("background-color : #C70039 ; color: white");
    connect(m_redo, &QPushButton::released, this, &MainWindow::handleRedo);
    m_BtsUndoRedo->addWidget(m_redo);

    m_formLayout->addRow(m_IdLabel, m_IdLineEdit);
    m_formLayout->addRow(m_nameLabel, m_nameLineEdit);
    m_formLayout->addRow(m_StockLabel, m_StockLineEdit);
    m_formLayout->addRow(m_PriceLabel, m_PriceLineEdit);
    m_formLayout->addRow(m_SugarLabel, m_SugarLineEdit);
    m_formLayout->addRow(m_TypeLabel, m_TypeLineEdit);
    m_formLayout->addRow(m_BtsLayout);
    m_formLayout->addRow(m_BtsUndoRedo);

    // crete tabel and add inital items to the table

    m_TableWidget = new QTableWidget();
    m_TableWidget->setStyleSheet("border : none; background-color: #F7EEA6; gridline-color: #FF5733; color: #FF5733");
    m_TableWidget->setColumnCount(6);
    m_TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    filltable(m_TableWidget, this->ctrl->GetContent());

    //Create Form+Table Layout
    m_FormTableLayout = new QHBoxLayout();
    m_FormTableLayout->addLayout(m_formLayout);
    m_FormTableLayout->addWidget(m_TableWidget);


    m_SortTableFilterTableLayout = new QHBoxLayout();
    m_SortFilterBTNS = new QVBoxLayout();

    // things for sorting
    m_BtsSortingLayout = new QVBoxLayout();

    m_BtsPair1 = new QHBoxLayout();
    m_SortID = new QPushButton("Sort by ID");
    connect(m_SortID, &QPushButton::released, this, &MainWindow::handleSortID);
    m_SortID->setStyleSheet("background-color : #581845  ; color: white");
    m_BtsPair1->addWidget(m_SortID);
    m_SortName = new QPushButton("Sort by Name");
    connect(m_SortName, &QPushButton::released, this, &MainWindow::handleSortName);
    m_SortName->setStyleSheet("background-color : #581845 ; color: white");
    m_BtsPair1->addWidget(m_SortName);

    m_BtsPair2 = new QHBoxLayout();
    m_SortStock = new QPushButton("Sort by Stock");
    connect(m_SortStock, &QPushButton::released, this, &MainWindow::handleSortStock);
    m_SortStock->setStyleSheet("background-color : #581845; color: white");
    m_BtsPair2->addWidget(m_SortStock );
    m_SortPrice = new QPushButton("Sort by Price");
    connect(m_SortPrice, &QPushButton::released, this, &MainWindow::handleSortPrice);
    m_SortPrice->setStyleSheet("background-color : #581845 ; color: white");
    m_BtsPair2->addWidget(m_SortPrice);

    m_BtsPair3 = new QHBoxLayout();
    m_SortSugar = new QPushButton("Sort by Sugar");
    connect(m_SortSugar, &QPushButton::released, this, &MainWindow::handleSortSugar);
    m_SortSugar->setStyleSheet("background-color : #581845 ; color: white");
    m_BtsPair3->addWidget(m_SortSugar);
    m_SortType = new QPushButton("Sort by Type");
    connect(m_SortType, &QPushButton::released, this, &MainWindow::handleSortType);
    m_SortType->setStyleSheet("background-color : #581845 ; color: white");
    m_BtsPair3->addWidget(m_SortType);

    m_BtsSortingLayout->addLayout(m_BtsPair1);
    m_BtsSortingLayout->addLayout(m_BtsPair2);
    m_BtsSortingLayout->addLayout(m_BtsPair3);

    //things for filtering form
    m_filter = new QHBoxLayout();
    m_filterbtns = new QVBoxLayout();
    m_filterFormLayout = new QFormLayout();

    m_filterNamebtns = new QHBoxLayout();
    m_FilterName = new QPushButton("Filter by Name");
    m_FilterName->setFixedSize(QSize(100, 30));
    connect(m_FilterName, &QPushButton::released, this, &MainWindow::handleFilterName);
    m_FilterName->setStyleSheet("background-color : #900C3F ; color: white");
    m_filterNamebtns->addWidget(m_FilterName);
    m_FNameLabel = new QLabel("Name:");
    m_FNameLabel->setFixedSize(QSize(50, 25));
    m_FNameLabel->setAlignment(Qt::AlignRight);
    m_FNameineEdit = new QLineEdit();
    m_FNameineEdit->setPlaceholderText("Enter name");
    m_filterNamebtns->addWidget(m_FNameLabel);
    m_filterNamebtns->addWidget(m_FNameineEdit);
    m_filterFormLayout->addRow(m_filterNamebtns);

    m_filterStockbtns = new QHBoxLayout();
    m_FilterStock = new QPushButton("Filter by Stock");
    m_FilterStock->setFixedSize(QSize(100, 30));
    m_FilterStock->setStyleSheet("background-color : #900C3F  ; color: white");
    connect(m_FilterStock, &QPushButton::released, this, &MainWindow::handleFilterStock);
    m_filterStockbtns->addWidget(m_FilterStock);
    m_FStockLabel = new QLabel("Stock:");
    m_FStockLabel->setFixedSize(QSize(50, 25));
    m_FStockLabel->setAlignment(Qt::AlignRight);
    m_FStockLineEdit = new QLineEdit();
    m_FStockLineEdit->setPlaceholderText("Enter stock number (integer)");
    m_filterStockbtns->addWidget(m_FStockLabel);
    m_filterStockbtns->addWidget(m_FStockLineEdit);
    m_filterFormLayout->addRow(m_filterStockbtns);

    m_filterPricebtns = new QHBoxLayout();
    m_FilterPrice = new QPushButton("Filter by Price");
    m_FilterPrice->setFixedSize(QSize(100, 30));
    connect(m_FilterPrice, &QPushButton::released, this, &MainWindow::handleFilterPrice);
    m_FilterPrice->setStyleSheet("background-color :#900C3F  ; color: white");
    m_filterPricebtns->addWidget(m_FilterPrice);
    m_FPriceLabel = new QLabel("Price:");
    m_FPriceLabel->setFixedSize(QSize(50, 25));
    m_FPriceLabel->setAlignment(Qt::AlignRight);
    m_FPriceLineEdit = new QLineEdit();
    m_FPriceLineEdit->setPlaceholderText("Enter price (decimal)");
    m_filterPricebtns->addWidget(m_FPriceLabel);
    m_filterPricebtns->addWidget(m_FPriceLineEdit);
    m_filterFormLayout->addRow(m_filterPricebtns);

     m_filterSugarbtns = new QHBoxLayout();
     m_FilterSugar = new QPushButton("Filter by Sugar");
     connect(m_FilterSugar, &QPushButton::released, this, &MainWindow::handleFilterSugar);
     m_FilterSugar->setStyleSheet("background-color : #900C3F  ; color: white");
     m_FilterSugar->setFixedSize(QSize(100, 30));
     m_filterSugarbtns->addWidget(m_FilterSugar);
     m_FSugarLabel = new QLabel("Sugar:");
     m_FSugarLabel->setFixedSize(QSize(50, 25));
     m_FSugarLabel->setAlignment(Qt::AlignRight);
     m_FSugarLineEdit = new QLineEdit();
     m_FSugarLineEdit->setPlaceholderText("Enter grams of sugar (decimal)");
     m_filterSugarbtns->addWidget(m_FSugarLabel);
     m_filterSugarbtns->addWidget(m_FSugarLineEdit);
     m_filterFormLayout->addRow(m_filterSugarbtns);

     m_filterTypebtns = new QHBoxLayout();
     m_FilterType = new QPushButton("Filter by Type");
     m_FilterType->setFixedSize(QSize(100, 30));
     connect(m_FilterType, &QPushButton::released, this, &MainWindow::handleFilterType);
     m_FilterType->setStyleSheet("background-color : #900C3F  ; color: white");
     m_filterTypebtns->addWidget(m_FilterType);
     m_FTypeLabel = new QLabel("Type:");
     m_FTypeLabel->setFixedSize(QSize(50, 25));
     m_FTypeLabel->setAlignment(Qt::AlignRight);
     m_FTypeLineEdit = new QLineEdit();
     m_FTypeLineEdit->setPlaceholderText("Enter a type : sweet, salty or bread");
     m_filterTypebtns->addWidget(m_FTypeLabel);
     m_filterTypebtns->addWidget(m_FTypeLineEdit);
     m_filterFormLayout->addRow(m_filterTypebtns);

    m_filter->addLayout(m_filterFormLayout);

    m_SortFilterBTNS->addLayout(m_filter);
    m_SortFilterBTNS->addLayout(m_BtsSortingLayout);

    m_SortTableFilterTableLayout->addLayout(m_SortFilterBTNS);

    //table
    m_SortedTable = new QTableWidget();
    m_SortedTable->setStyleSheet("border : none; background-color: #F7EEA6; gridline-color: #FF5733; color: #FF5733 ");
    m_SortedTable->setColumnCount(6);
    m_SortedTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_SortedTable->setSelectionMode(QAbstractItemView::NoSelection);
    filltable(m_SortedTable, this->ctrl->GetContent());

    m_SortFilterTotal = new QHBoxLayout();

    m_SortFilterTotal->addLayout(m_SortTableFilterTableLayout);
    m_SortFilterTotal->addWidget(m_SortedTable);

    m_BigTitleLabel = new QLabel("Bakery Management");
    m_BigTitleLabel->setStyleSheet("font-size: 20pt; font-weight: bold; color: #581845 ");
    m_BigTitleLabel->setAlignment(Qt::AlignCenter);
    m_vLayout->addWidget(m_BigTitleLabel);

    m_UpdateLabel = new QLabel("Update the Items List");
    m_UpdateLabel->setStyleSheet("font-size: 15pt; font-weight: bold; color: #900C3F ");
    m_UpdateLabel->setAlignment(Qt::AlignCenter);
    m_vLayout->addWidget(m_UpdateLabel);
    m_vLayout->addLayout(m_FormTableLayout);

    m_BigFilterLabel = new QLabel("Filtering and Sorting");
    m_BigFilterLabel->setStyleSheet("font-size: 15pt; font-weight: bold; color: #900C3F ");
    m_BigFilterLabel->setAlignment(Qt::AlignCenter);
    m_vLayout->addWidget(m_BigFilterLabel);
    m_vLayout->addLayout(m_SortFilterTotal);

    m_CentralWidget->setLayout(m_vLayout);
    m_CentralWidget->setStyleSheet("QLineEdit {border: none}");
    m_CentralWidget->setStyleSheet("QLabel{color: #C70039}");

    this->setCentralWidget(m_CentralWidget);
}

MainWindow::~MainWindow()
{
    delete m_CentralWidget;
    delete m_vLayout;

    //ADD REMOVE UPDATE
    delete m_FormTableLayout;

    //things necessary for addition, update form
    delete m_formLayout;
    delete m_IdLabel;
    delete m_IdLineEdit;

    delete m_nameLabel;
    delete m_nameLineEdit;

    delete m_StockLabel;
    delete m_StockLineEdit;

    delete m_PriceLabel;
    delete m_PriceLineEdit;

     delete m_SugarLabel;
     delete m_SugarLineEdit;

     delete m_TypeLabel;
     delete m_TypeLineEdit;

    //buttons for add, remove, update
     delete m_BtsLayout;
     delete m_removeBtn;
     delete m_updateBtn;
     delete m_addBtn;

    //table where to see add, remove , update
     delete m_TableWidget;

    //SORT FILTER
     delete m_SortTableFilterTableLayout;

    // things for sorting
     delete m_BtsSortingLayout;
     delete m_SortID;
     delete m_SortName;
     delete m_SortStock;
     delete m_SortPrice;
     delete m_SortSugar;
     delete m_SortType;

    //table
     delete m_SortedTable;

    //things for filtering form
     delete m_filter;
     delete m_filterbtns;
     delete m_filterFormLayout;

     delete m_FilterName;
     delete m_FNameLabel;
     delete m_FNameineEdit;

     delete m_FilterStock;
     delete m_FStockLabel;
     delete m_FStockLineEdit;

     delete m_FilterPrice;
     delete m_FPriceLabel;
     delete m_FPriceLineEdit;

     delete m_FilterSugar;
     delete m_FSugarLabel;
     delete m_FSugarLineEdit;

     delete m_FilterType;
     delete m_FTypeLabel;
     delete m_FTypeLineEdit;

}

