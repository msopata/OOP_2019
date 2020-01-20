#include <QtTest>

// add necessary includes here
#include "demo.h"
#include "QSignalSpy"

class demo_test : public QObject
{
    Q_OBJECT

private slots:
    void test_case1();

};

void demo_test::test_case1()
{
    Demo demo{};
    QSignalSpy spy(&demo, SIGNAL(added()));

}

QTEST_APPLESS_MAIN(demo_test)

#include "tst_demo_test.moc"
