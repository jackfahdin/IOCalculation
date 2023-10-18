#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 创建一个垂直布局管理器，并添加4个水平布局管理器
    QVBoxLayout *vLayout = new QVBoxLayout();

    QHBoxLayout *hLayoutIo2NumTitle = new QHBoxLayout();
    QHBoxLayout *hLayoutIo2Num = new QHBoxLayout();
   // QHBoxLayout *hLayoutNum2IoTitle = new QHBoxLayout();
    //QHBoxLayout *hLayoutNum2Io = new QHBoxLayout();

    QLabel *labelIo2NumTitle = new QLabel("GPIO转换成数字");
    labelIo2NumTitle->setAlignment(Qt::AlignCenter);
    hLayoutIo2NumTitle->addWidget(labelIo2NumTitle);

    // GPIO0_A1
    QLineEdit *hLayoutIo2NumGroup = new QLineEdit(); // GPIO0
    QLineEdit *hLayoutIo2NumId1 = new QLineEdit(); // A
    QLineEdit *hLayoutIo2NumId2 = new QLineEdit(); // 1
    QLabel *labelIo2NumSum = new QLabel("等于"); //转换之后的结果

    hLayoutIo2Num->addWidget(hLayoutIo2NumGroup);
    hLayoutIo2Num->addWidget(hLayoutIo2NumId1);
    hLayoutIo2Num->addWidget(hLayoutIo2NumId2);

    labelIo2NumSum->setAlignment(Qt::AlignCenter);
    hLayoutIo2Num->addWidget(labelIo2NumSum);

//    QLabel *label2 = new QLabel("数字转换成GPIO");
//    label2->setAlignment(Qt::AlignCenter);
//    hLayout3->addWidget(label2);

//    QLineEdit *lineEdit7 = new QLineEdit();
//    QLineEdit *lineEdit8 = new QLineEdit();
//    QLineEdit *lineEdit9 = new QLineEdit();
//    QLineEdit *lineEditA = new QLineEdit();
//    hLayout4->addWidget(lineEdit7);
//    QLabel *label4 = new QLabel("等于");
//    label4->setAlignment(Qt::AlignCenter);
//    hLayout4->addWidget(label4);
//    hLayout4->addWidget(lineEdit8);
//    hLayout4->addWidget(lineEdit9);
//    hLayout4->addWidget(lineEditA);

    // 将两个水平布局管理器添加到垂直布局管理器中
    vLayout->addLayout(hLayoutIo2NumTitle);
    vLayout->addLayout(hLayoutIo2Num);
//    vLayout->addLayout(hLayout3);
//    vLayout->addLayout(hLayout4);

    // 显示窗口并启动事件循环
    QWidget widget;
    widget.setLayout(vLayout);
    widget.show();

    // 连接 QLineEdit 控件的 returnPressed 信号到槽函数
        QObject::connect(hLayoutIo2NumId2, &QLineEdit::returnPressed, [&]() {
            if (!hLayoutIo2NumGroup->text().isEmpty() &&
                    !hLayoutIo2NumId1->text().isEmpty() &&
                    !hLayoutIo2NumId2->text().isEmpty()) {
                // 获取两个 QLineEdit 控件中的文本，并将其转换为整数
                int num1 = hLayoutIo2NumGroup->text().toInt();
                int num2 = hLayoutIo2NumId1->text().toInt();
                int num3 = hLayoutIo2NumId2->text().toInt();

                // 计算两个整数的和
                int sum = num1 + num2 + num3;

                // 将计算结果设置为 QLabel 控件的文本
                labelIo2NumSum->setText(QString::number(sum));
            }
        });
    return a.exec();
}
