#ifndef DIALOGPROJECTBUILDER_H
#define DIALOGPROJECTBUILDER_H

#include <QDialog>
#include "source/Compiler/projectbuilder.h"
#include <QScrollBar>

namespace Ui {
class DialogProjectBuilder;
}

class DialogProjectBuilder : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProjectBuilder(QWidget *parent = nullptr);
    void Initialize(QSharedPointer<CIniFile> ini, QSharedPointer<CIniFile> iniP, QString curDir, QStringList lst);
    ~DialogProjectBuilder();
    ProjectBuilder* m_pb = nullptr;

private slots:
    void on_pushButton_clicked();
    void UpdateText();
private:
    Ui::DialogProjectBuilder *ui;
};

#endif // DIALOGPROJECTBUILDER_H
