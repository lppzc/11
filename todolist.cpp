#include "todolist.h"
#include <QtWidgets/QMessageBox>

TodoList::TodoList(QWidget *parent) : QWidget(parent) {
    // 创建控件
    taskInput = new QLineEdit(this);
    taskList = new QListWidget(this);
    addButton = new QPushButton("添加任务", this);
    removeButton = new QPushButton("删除选中任务", this);

    // 布局设置
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *inputLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    inputLayout->addWidget(new QLabel("任务:", this));
    inputLayout->addWidget(taskInput);

    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(removeButton);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(taskList);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    setWindowTitle("待办事项");
    resize(400, 300);

    // 连接信号与槽
    connect(addButton, &QPushButton::clicked, this, &TodoList::addTask);
    connect(removeButton, &QPushButton::clicked, this, &TodoList::removeTask);
}

void TodoList::addTask() {
    QString task = taskInput->text().trimmed();
    if (!task.isEmpty()) {
        tasks.push_back(task.toStdString());
        updateTaskList();
        taskInput->clear();
    } else {
        QMessageBox::warning(this, "警告", "任务内容不能为空！");
    }
}

void TodoList::removeTask() {
    QListWidgetItem *item = taskList->currentItem();
    if (item) {
        int row = taskList->row(item);
        tasks.erase(tasks.begin() + row);
        delete item;
    } else {
        QMessageBox::warning(this, "警告", "请选择要删除的任务！");
    }
}

void TodoList::updateTaskList() {
    taskList->clear();
    for (const auto &task : tasks) {
        taskList->addItem(QString::fromStdString(task));
    }
}