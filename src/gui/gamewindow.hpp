#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    
private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_HPP
