#include <QtTest>
#include "../Gaiiulin_LAB_4/gaiiulin_lab_4.h"

// add necessary includes here

class test_sample : public QObject
{
    Q_OBJECT

public:
    test_sample();
    ~test_sample();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_sample::test_sample()
{
    QCOMPARE(CSimp::prove(1, 2), std::vector<int>({2}));
}

test_sample::~test_sample()
{

}

void test_sample::initTestCase()
{

}

void test_sample::cleanupTestCase()
{

}

void test_sample::test_case1()
{

}

QTEST_APPLESS_MAIN(test_sample)

#include "tst_test_sample.moc"
