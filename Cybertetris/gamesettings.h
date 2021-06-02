#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <QDialog>
#include <settings.h>

namespace Ui {
class GameSettings;
}

class GameSettings : public QDialog {
  Q_OBJECT

 public:
  explicit GameSettings(QWidget* parent, Settings& settings);
  ~GameSettings();

 private slots:
  void on_buttonBox_accepted();

 private:
  Settings& settings;
  Ui::GameSettings* ui;
};

#endif // GAMESETTINGS_H
