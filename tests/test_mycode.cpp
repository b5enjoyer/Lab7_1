#include <QtTest/QtTest>
#include "../src/form.h"

class TestMyCode : public QObject {
    Q_OBJECT

private slots:
    void testSubstringPresent();
    void testSubstringNotPresent();
    void testEmptyStrings();
    void testSubstringAtBeginning();
};

void TestMyCode::testSubstringPresent() {
    Form form;
    QString str = "Hello, World!";
    QString sub_str = "World";

    form.ui->str->setText(str);
    form.ui->sub_str->setText(sub_str);

    form.start();

    // Дополнительный вывод для отслеживания прохождения теста
    qDebug() << "Test Substring Present Result:" << form.ui->result->text();

    QCOMPARE(form.ui->result->text(), QString("Подстрока найдена!"));
}

void TestMyCode::testSubstringNotPresent() {
    Form form;
    QString str = "Hello, World!";
    QString sub_str = "Universe";

    form.ui->str->setText(str);
    form.ui->sub_str->setText(sub_str);

    form.start();

    // Дополнительный вывод для отслеживания прохождения теста
    qDebug() << "Test Substring Not Present Result:" << form.ui->result->text();

    QCOMPARE(form.ui->result->text(), QString("Подстрока не найдена!"));
}

void TestMyCode::testEmptyStrings() {
    Form form;
    QString str = "";
    QString sub_str = "";

    form.ui->str->setText(str);
    form.ui->sub_str->setText(sub_str);

    form.start();

    // Дополнительный вывод для отслеживания прохождения теста
    qDebug() << "Test Empty Strings Result:" << form.ui->result->text();

    QCOMPARE(form.ui->result->text(), QString("Подстрока найдена!")); // Ожидаем, что при пустых строках подстрока будет найдена
}
void TestMyCode::testSubstringAtBeginning() {
    Form form;
    QString str = "Hello, World!";
    QString sub_str = "Hello";

    form.ui->str->setText(str);
    form.ui->sub_str->setText(sub_str);

    form.start();

    // Дополнительный вывод для отслеживания прохождения теста
    qDebug() << "Test Substring At Beginning Result:" << form.ui->result->text();

    QCOMPARE(form.ui->result->text(), QString("Подстрока найдена!")); // Ожидаем, что подстрока будет найдена в начале строки
}

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
