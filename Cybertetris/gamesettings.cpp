#include "gamesettings.h"
#include "ui_gamesettings.h"

GameSettings::GameSettings(QWidget* parent, Settings& settings) :
  QDialog(parent), settings(settings),
  ui(new Ui::GameSettings) {
  ui->setupUi(this);

  ui->glassHeight->setValue(settings.glassHeight());
  ui->glassWidth->setValue(settings.glassWidth());
  ui->cellSize->setValue(settings.cellSize());
  ui->cellBorder->setValue(settings.cellBorder());
}

GameSettings::~GameSettings() {
  delete ui;
}

void GameSettings::on_buttonBox_accepted() {
  settings.setGlassHeight(ui->glassHeight->value());
  settings.setGlassWidth(ui->glassWidth->value());
  settings.setCellSize(ui->cellSize->value());
  settings.setCellBorder(ui->cellBorder->value());

  settings.sync(); //保存设置
}
