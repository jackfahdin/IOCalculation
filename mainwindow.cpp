#include "mainwindow.h"

#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建输入框
        QLineEdit* inputBox1 = new QLineEdit();
        QLineEdit* inputBox2 = new QLineEdit();
        QLineEdit* inputBox3 = new QLineEdit();

        // 将输入框存储在数组中以方便处理
        QLineEdit* inputBoxes[] = {inputBox1, inputBox2, inputBox3};

        // 将第一个输入框设置为活动输入框
        inputBox1->setFocus();

        // 为每个输入框添加textChanged信号
        for (auto inputBox : inputBoxes)
        {
            QObject::connect(inputBox, &QLineEdit::textChanged, [=]()
            {
                // 检查当前输入框的文本长度是否达到所需长度
                if (inputBox->text().length() == 1)
                {
                    // 找到当前输入框的索引
                    int currentIndex = -1;
                    for (int i = 0; i < sizeof(inputBoxes) / sizeof(QLineEdit*); i++)
                    {
                        if (inputBox == inputBoxes[i])
                        {
                            currentIndex = i;
                            break;
                        }
                    }

                    // 激活下一个输入框
                    if (currentIndex != sizeof(inputBoxes) / sizeof(QLineEdit*) - 1)
                    {
                        inputBoxes[currentIndex + 1]->setFocus();
                    }
                }
            });
        }
}

MainWindow::~MainWindow()
{
}

