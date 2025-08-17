#include <QDebug>
#include <QObject>
#include <QQmlEngine>
#include <QQmlProperty>
#include <QQmlComponent>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication o_app{argc, argv};

    QQmlEngine o_engine;
    QQmlComponent o_component{&o_engine, "qrc:/qml/main.qml"};
    QObject *po_rootObject = o_component.create(nullptr);

    // Print the object name of the root element
    qDebug() << po_rootObject->objectName() << "\n";
    qDebug() << "Object has " << po_rootObject->children().size() << " children !";

    // Read child1
    const auto *po_child1 = po_rootObject->findChild<QObject *>("Child1");

    if (po_child1) {
        qDebug() << "Child1 age is: " << QQmlProperty::read(po_child1, "age").toInt();
        qDebug() << "Child1 age is: " << po_child1->property("age").toInt();
        qDebug() << "Name is: " << po_child1->property("names").toString();
    }

    const auto *po_rect = po_rootObject->findChild<QObject *>("childRect");

    if (po_rect) {
        qDebug() << "Rectangle color is: " << po_rect->property("color").toString();
        qDebug() << "Rectangle object name: " << QQmlProperty::read(po_rect, "objectName").toString();
    }

    QList<QObject *> o_children = po_rootObject->findChildren<QObject *>("Child2");

    if (!o_children.isEmpty()) {
        qDebug() << "Got some children, printing their cars:";
        foreach (QObject *po_object, o_children) {
            qDebug() << "\tThe car brand is: " << po_object->property("car").toString();
        }
    }

    QList<QObject *> o_recursive = po_rootObject->findChildren<QObject *>("deepChild", Qt::FindChildrenRecursively);
    if (o_recursive.count() > 0) {
        qDebug() << "Found the followings child:";
        foreach (QObject *po_object, o_recursive) {
            qDebug() << "\tThe child level is: " << po_object->property("level").toString();
        }
    }
    return o_app.exec();
}
