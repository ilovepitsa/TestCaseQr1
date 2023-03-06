#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("Author");
    db.setUserName("postgres");
    db.setPassword("123");
    if(!db.open())
    {
        qDebug()<<"error open";
        return -1;
    }
    QSqlQuery query;
    QString str_t = "select * from books";
    if(!query.exec(str_t))
        qDebug()<<"error select";
    else
    {
        while(query.next())
        {
            qDebug()<<query.value(0).toString()<<"   "<<query.value(1).toString();
        }
    }
    return a.exec();
}
