#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_dial_valueChanged(int value);

    void on_actionDefine_theme_path_triggered();

    void on_actionReload_theme_triggered();

    void on_ProgessBarControl_valueChanged(int value);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString gsThemePath;

    bool loadThemeFile();
};

#endif // MAINWINDOW_H
