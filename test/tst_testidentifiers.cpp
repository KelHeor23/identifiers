#include <QtTest>
#include <vector>
#include "../src/Identifiers.h"

// add necessary includes here

class testIdentifiers : public QObject
{
    Q_OBJECT
public:
    testIdentifiers();
    ~testIdentifiers();

private slots:
    void testNextIdentifiers_data();
    void testNextIdentifiers();
};

testIdentifiers::testIdentifiers(){}

testIdentifiers::~testIdentifiers(){}

void testIdentifiers::testNextIdentifiers_data()
{
    QTest::addColumn<QString>("a");
    QTest::addColumn<QString>("result");

    QTest::newRow("A1 A2") << "A1" << "A2";
    QTest::newRow("A9 B1") << "A9" << "B1";
    QTest::newRow("A1-A9 A1-B1") << "A1-A9" << "A1-B1";
    QTest::newRow("A1-Z9 A2-A1") << "A1-Z9" << "A2-A1";
    QTest::newRow("Z9 A1-A1") << "Z9" << "A1-A1";
    QTest::newRow("Z9-Z9-Z9-Z9 A1-A1-A1-A1-A1") << "Z9-Z9-Z9-Z9" << "A1-A1-A1-A1-A1";
}

void testIdentifiers::testNextIdentifiers()
{
    QFETCH(QString, a);
    QFETCH(QString, result);
    QCOMPARE(QString::fromStdString(Identifiers::nextIdent(a.toStdString())), result);
}

QTEST_APPLESS_MAIN(testIdentifiers)

#include "tst_testidentifiers.moc"
