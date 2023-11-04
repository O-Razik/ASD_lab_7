#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dlist.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_push_back_clicked();

    void on_push_front_clicked();

    void on_pop_back_clicked();

    void on_pop_front_clicked();

    void on_after_max_clicked();

    void on_before_min_clicked();

    void on_index_box_valueChanged(int arg1);

    void on_look_num_valueChanged(double arg1);

    void update_list(int index, QTableWidget *table_list);

    void on_tabWidget_currentChanged(int index);

    void on_push_front_1_clicked();

    void on_push_back_1_clicked();

    void on_pop_front_1_clicked();

    void on_pop_back_1_clicked();

    void on_push_front_2_clicked();

    void on_push_back_2_clicked();

    void on_pop_front_2_clicked();

    void on_pop_back_2_clicked();

    void on_comb_button_clicked();

    void on_insert_clicked();

    void on_extract_clicked();

    void on_index_insert_box_valueChanged(int arg1);

    void on_extract_index_box_valueChanged(int arg1);

    void on_idex_from_clicked();

private:
    Ui::MainWindow *ui;
    DList list[3];
};
#endif // MAINWINDOW_H
