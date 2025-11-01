#include <QtWidgets/QApplication>
#include "todolist.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TodoList todoList;
    todoList.show();

    return app.exec();
}