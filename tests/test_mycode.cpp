#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testIvan();
    void testMultipleWords();
    void testSpecialCharactersAndCase();
};

void TestMyCode::testIvan() {
    std::stringstream sstr;
    stringstream isst;
    isst << "Ivan";

    hello(isst, sstr);

    string str;
    getline(sstr, str);

    QCOMPARE(str == "hello Ivan", true);
}

void TestMyCode::testMultipleWords() {
    std::stringstream sstr;
    std::stringstream isst;
    isst << "John Doe";

    hello(isst, sstr);

    std::string str;
    getline(sstr, str);

    QCOMPARE(QString::fromStdString(str), QString("hello John"));
}

void TestMyCode::testSpecialCharactersAndCase() {
    std::stringstream sstr;
    std::stringstream isst;
    isst << "Alice123 *&^%";

    hello(isst, sstr);

    std::string str;
    getline(sstr, str);

    QCOMPARE(QString::fromStdString(str), QString("hello Alice123"));
}




QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
