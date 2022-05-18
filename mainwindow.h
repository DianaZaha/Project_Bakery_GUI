#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controller.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QMessageBox>
#include <QKeyEvent>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Controller *ctrl = nullptr, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void handleAdd();
    void handleUpdate();
    void handleRemove();

    void handleSortID();
    void handleSortName();
    void handleSortStock();
    void handleSortPrice();
    void handleSortSugar();
    void handleSortType();

    void handleFilterName();
    void handleFilterStock();
    void handleFilterPrice();
    void handleFilterSugar();
    void handleFilterType();

    void handleUndo();
    void handleRedo();

private:
    void filltable(QTableWidget*, vector<Pastry>);

    Ui::MainWindow *ui;
    Controller* ctrl;

    //big things
    QWidget* m_CentralWidget;
    QVBoxLayout * m_vLayout;

    //ADD REMOVE UPDATE
    QHBoxLayout * m_FormTableLayout;

    //things necessary for addition, update form
    QFormLayout* m_formLayout;
    QLabel * m_IdLabel;
    QLineEdit* m_IdLineEdit;

    QLabel * m_nameLabel;
    QLineEdit* m_nameLineEdit;

    QLabel * m_StockLabel;
    QLineEdit* m_StockLineEdit;

    QLabel * m_PriceLabel;
    QLineEdit* m_PriceLineEdit;

    QLabel * m_SugarLabel;
    QLineEdit* m_SugarLineEdit;

    QLabel * m_TypeLabel;
    QLineEdit* m_TypeLineEdit;

    //buttons for add, remove, update
    QHBoxLayout * m_BtsLayout;
    QPushButton * m_removeBtn;
    QPushButton * m_updateBtn;
    QPushButton * m_addBtn;

    QHBoxLayout * m_BtsUndoRedo;
    QPushButton * m_undo;
    QPushButton * m_redo;

    //table where to see add, remove , update
    QTableWidget * m_TableWidget;

    // things for sorting
    QVBoxLayout * m_BtsSortingLayout;
    QHBoxLayout * m_BtsPair1;
    QPushButton * m_SortID;
    QPushButton * m_SortName;
    QHBoxLayout * m_BtsPair2;
    QPushButton * m_SortStock;
    QPushButton * m_SortPrice;
    QHBoxLayout * m_BtsPair3;
    QPushButton * m_SortSugar;
    QPushButton * m_SortType;

    QHBoxLayout * m_SortTableFilterTableLayout;
    //table
    QTableWidget * m_SortedTable;

    QHBoxLayout * m_SortFilterTotal;

    //SORT FILTER BTNS
    QVBoxLayout * m_SortFilterBTNS;

    //FILTER BTNS
    QFormLayout* m_filterBTNS;

    //things for filtering form
    QHBoxLayout * m_filter;
    QVBoxLayout * m_filterbtns;
    QFormLayout* m_filterFormLayout;

    QPushButton * m_FilterName;
    QLabel * m_FNameLabel;
    QLineEdit* m_FNameineEdit;
    QHBoxLayout * m_filterNamebtns;

    QPushButton * m_FilterStock;
    QLabel * m_FStockLabel;
    QLineEdit* m_FStockLineEdit;
    QHBoxLayout * m_filterStockbtns;

    QPushButton * m_FilterPrice;
    QLabel * m_FPriceLabel;
    QLineEdit* m_FPriceLineEdit;
    QHBoxLayout * m_filterPricebtns;

    QPushButton * m_FilterSugar;
    QLabel * m_FSugarLabel;
    QLineEdit* m_FSugarLineEdit;
    QHBoxLayout * m_filterSugarbtns;

    QPushButton * m_FilterType;
    QLabel * m_FTypeLabel;
    QLineEdit* m_FTypeLineEdit;
    QHBoxLayout * m_filterTypebtns;

    QLabel * m_BigTitleLabel;
    QLabel * m_UpdateLabel;
    QLabel * m_BigFilterLabel;
};
#endif // MAINWINDOW_H
