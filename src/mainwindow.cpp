#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Qsci/qsciscintilla.h"
#include "Qsci/qscilexerlua.h"
#include "Qsci/qsciapis.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建QsciScintilla实例
    QsciScintilla *editor = new QsciScintilla(this);
    this->setCentralWidget(editor);
    //创建一个词法分析器
    QsciLexerLua *textLexer = new QsciLexerLua;
    //给QsciScintilla设置词法分析器
    editor->setLexer(textLexer);
    editor->setMarginType(0,QsciScintilla::NumberMargin);//设置编号为0的页边显示行号。
    editor->setMarginLineNumbers(0,true);//对该页边启用行号
    editor->setMarginWidth(0,50);//设置页边宽度
    QsciAPIs *apis = new QsciAPIs(textLexer);
    apis->add(QString("local"));
    apis->prepare();


}

MainWindow::~MainWindow()
{
    delete ui;
}
