#ifndef TODOLIST_H
#define TODOLIST_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QLabel>
#include <vector>
#include <string>

class TodoList : public QWidget {
    Q_OBJECT

public:
    TodoList(QWidget *parent = nullptr);

private slots:
    void addTask();
    void removeTask();

private:
    void updateTaskList();

    QLineEdit *taskInput;
    QListWidget *taskList;
    QPushButton *addButton;
    QPushButton *removeButton;
    std::vector<std::string> tasks;
};

#endif // TODOLIST_H