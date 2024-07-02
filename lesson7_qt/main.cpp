
#include <QtSql>
#include <QTableView>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open()) {
        qDebug() << "Что-то не так с соединением!";
        return -1;
    }

    QTableView view;
    QSqlTableModel model;

    model.setTable("my_table");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    view.setModel(&model);
    view.show();

    return app.exec();
}

