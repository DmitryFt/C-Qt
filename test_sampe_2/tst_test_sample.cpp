#include <QtTest>
#include "../Gaiiulin_LAB_4/gaiiulin_lab_4.h"
#include <chrono>
#include <thread>

// add necessary includes here

class test_sample : public QObject
{
    Q_OBJECT

public:
    test_sample();
    ~test_sample();

private slots:
    void not_unit();
    void border_first_arg();
    void border_second_arg();
    void test_benchmark();
    void a_positive();
    void b_posistive();
    void b_more_a();
    void a_is_null();
    void b_is_null();
    void a_ravno_b();
};

test_sample::test_sample()
{

}

test_sample::~test_sample()
{

}

void test_sample::not_unit()
{
    QCOMPARE(CSimp::prove(1, 2), std::vector<int>({2}));
}

void test_sample::border_first_arg()
{
    QCOMPARE(CSimp::prove(2, 12), std::vector<int>({2,3,5,7,11}));
}

void test_sample::border_second_arg()
{
    QCOMPARE(CSimp::prove(1, 11), std::vector<int>({2,3,5,7,11}));
}

void test_sample::test_benchmark()
{
    QBENCHMARK{
        CSimp::prove(10000, 99999);
    }
}

void test_sample::a_positive()
{
    try {
        CSimp::prove(-28,8);
        QFAIL("no exception raised");
    } catch (std::out_of_range const & e) {
        QCOMPARE(e.what(), QString("a must be positive or not null"));
    } catch (...) {
        QFAIL("exception no this type");
    }
}

void test_sample::b_posistive()
{
    try {
        CSimp::prove(20,-38);
        QFAIL("no exception raised");
    } catch (std::out_of_range const & e) {
        QCOMPARE(e.what(), QString("b must be positive or not null"));
    } catch (...) {
        QFAIL("exception no this type");
    }
}

void test_sample::b_more_a()
{
    try {
        CSimp::prove(20,5);
        QFAIL("no exception raised");
    } catch (std::out_of_range const & e) {
        QCOMPARE(e.what(), QString("b must be more a"));
    } catch (...) {
        QFAIL("exception no this type");
    }
}

void test_sample::a_is_null()
{
    try {
        CSimp::prove(0,5);
        QFAIL("no exception raised");
    } catch (std::out_of_range const & e) {
        QCOMPARE(e.what(), QString("a must be positive or not null"));
    } catch (std::invalid_argument const & e) {
        QFAIL("exception no this type");
    }
}

void test_sample::b_is_null()
{
    try {
        CSimp::prove(2,0);
        QFAIL("no exception raised");
    } catch (std::out_of_range const & e) {
        QCOMPARE(e.what(), QString("b must be positive or not null"));
    } catch (std::invalid_argument const & e) {
        QFAIL("exception no this type");
    }
}

void test_sample::a_ravno_b()
{
    try {
        CSimp::prove(20,20);
        QFAIL("no exception raised");
    } catch (std::out_of_range const & e) {
        QCOMPARE(e.what(), QString("b must be more a"));
    } catch (std::invalid_argument const & e) {
        QFAIL("exception no this type");
    }
}



QTEST_APPLESS_MAIN(test_sample)

#include "tst_test_sample.moc"
