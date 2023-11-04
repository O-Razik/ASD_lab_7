#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_list_2->setVisible(false);
    ui->table_dlist_2->setVisible(false);
    ui->label_list_res->setVisible(false);
    ui->table_dlist_3->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_back_clicked()
{
    list[0].push_back(new node(ui->add_box->value()));
    update_list(0, ui->table_dlist);
}


void MainWindow::on_push_front_clicked()
{
    list[0].push_front(new node(ui->add_box->value()));
    update_list(0, ui->table_dlist);
}


void MainWindow::on_pop_back_clicked()
{
    node* pop = list[0].pop_back();
    if (pop == nullptr) return;
    ui->pop_num->setText(QString::number(pop->a));
    update_list(0, ui->table_dlist);
    delete pop;
}


void MainWindow::on_pop_front_clicked()
{
    node* pop = list[0].pop_front();
    if (pop == nullptr) return;
    ui->pop_num->setText(QString::number(pop->a));
    update_list(0, ui->table_dlist);
    delete pop;
}


void MainWindow::on_after_max_clicked()
{
    int index = list[0].get_index(list[0].max_elem());
    if (index != -1) {
        node* nextNode = list[0].get_node_back(index + 1);
        if (nextNode != nullptr) {
            ui->get_ab_m->setText(QString::number(nextNode->a));
        }
    }
    else {
        ui->get_ab_m->setText("");
    }
}

void MainWindow::on_before_min_clicked()
{
    int index = list[0].get_index(list[0].min_elem());
    if (index != -1) {
        node* prevNode = list[0].get_node_back(index - 1);
        if (prevNode != nullptr) {
            ui->get_ab_m->setText(QString::number(prevNode->a));
        }
    }
    else {
        ui->get_ab_m->setText("");
    }
}

void MainWindow::on_index_box_valueChanged(int arg1)
{
    if(list[0].size() == 0){
        ui->index_box->setValue(0);
        ui->index->setText("");
        return;
    }
    if (arg1 >= 0 && arg1 < list[0].size()) {
        if(ui->idex_from->text() == "Back") ui->num_by_index->setText(QString::number(list[0].get_node_back(arg1)->a));
        else ui->num_by_index->setText(QString::number(list[0].get_node_front(arg1)->a));
    }
    else {
        ui->index_box->setValue(arg1-1);
    }
}

void MainWindow::on_look_num_valueChanged(double arg1)
{
    node* n = new node(arg1);
    ui->index->setText(QString::number(list[0].get_index(n)));
    delete n;
}

void MainWindow::update_list(int index, QTableWidget* table_list) {
    int size = list[index].size();
    if(size == 0) {
        table_list->clear();
        ui->size->setText("0");
        ui->max->setText("___");
        ui->min->setText("___");
        return;
    }

    table_list->setRowCount(1);
    table_list->setColumnCount(size);
    for (int i = 0; i < size; ++i) {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(list[index][i]->a));
        table_list->setItem(0, i, item);
    }

    if (index == 0) {
        ui->size->setText(QString::number(list[index].size()));
        ui->max->setText(QString::number(list[index].max_elem()->a));
        ui->min->setText(QString::number(list[index].min_elem()->a));
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0) {
        ui->label_list_2->setVisible(false);
        ui->table_dlist_2->setVisible(false);
        ui->label_list_res->setVisible(false);
        ui->table_dlist_3->setVisible(false);
    }
    else if(index == 1) {
        ui->label_list_2->setVisible(true);
        ui->table_dlist_2->setVisible(true);
        ui->label_list_res->setVisible(true);
        ui->table_dlist_3->setVisible(true);
    }
}


void MainWindow::on_push_front_1_clicked()
{
    list[0].push_front(new node(ui->add_box_1->value()));
    update_list(0, ui->table_dlist);
}


void MainWindow::on_push_back_1_clicked()
{
    list[0].push_back(new node(ui->add_box_1->value()));
    update_list(0, ui->table_dlist);
}


void MainWindow::on_pop_front_1_clicked()
{
    node* pop = list[0].pop_front();
    if (pop == nullptr) return;
    ui->pop_num_1->setText(QString::number(pop->a));
    update_list(0, ui->table_dlist);
    delete pop;
}


void MainWindow::on_pop_back_1_clicked()
{
    node* pop = list[0].pop_back();
    if (pop == nullptr) return;
    ui->pop_num_1->setText(QString::number(pop->a));
    update_list(0, ui->table_dlist);
    delete pop;
}


void MainWindow::on_push_front_2_clicked()
{
    list[1].push_front(new node(ui->add_box_2->value()));
    update_list(1, ui->table_dlist_2);
}


void MainWindow::on_push_back_2_clicked()
{
    list[1].push_back(new node(ui->add_box_2->value()));
    update_list(1, ui->table_dlist_2);
}


void MainWindow::on_pop_front_2_clicked()
{
    node* pop = list[1].pop_front();
    if (pop == nullptr) return;
    ui->pop_num_2->setText(QString::number(pop->a));
    update_list(1, ui->table_dlist_2);
    delete pop;
}


void MainWindow::on_pop_back_2_clicked()
{
    node* pop = list[1].pop_back();
    if (pop == nullptr) return;
    ui->pop_num_2->setText(QString::number(pop->a));
    update_list(1, ui->table_dlist_2);
    delete pop;
}


void MainWindow::on_comb_button_clicked()
{
    list[2] = list[0].combine(list[1]);
    update_list(2, ui->table_dlist_3);
}


void MainWindow::on_insert_clicked()
{
    list[0].insert(ui->index_insert_box->value(),new node(ui->add_box->value()));
    update_list(0, ui->table_dlist);
}


void MainWindow::on_extract_clicked()
{
    node* pop = list[0].extract(ui->extract_index_box->value());
    if (pop == nullptr) return;
    ui->pop_num->setText(QString::number(pop->a));
    update_list(0, ui->table_dlist);
    delete pop;
}


void MainWindow::on_index_insert_box_valueChanged(int arg1)
{
    if(list[0].size() == 0){
        ui->index_insert_box->setValue(0);
        return;
    }
    else if (arg1 > list[0].size())  {
        ui->index_insert_box->setValue(list[0].size()-1);
    }
    return;
}


void MainWindow::on_extract_index_box_valueChanged(int arg1)
{
    if(list[0].size() == 0){
        ui->extract_index_box->setValue(0);
        return;
    }
    else if (arg1 > list[0].size())  {
        ui->extract_index_box->setValue(list[0].size()-1);
    }
    return;
}


void MainWindow::on_idex_from_clicked()
{
    if(ui->idex_from->text().contains("Back")) ui->idex_from->setText("Front");
    else ui->idex_from->setText("Back");
}

