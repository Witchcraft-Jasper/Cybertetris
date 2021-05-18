#include "settings.h"

const QString Settings::GlassHeight = "glass/height";
const QString Settings::GlassWidth = "glass/width";//储存界面的宽度和高度
const QString Settings::CellSize = "glass/cellSize";
const QString Settings::CellBorder = "glass/cellBorder";//储存每一方格的宽度

Settings::Settings() : QSettings("tetris.ini", QSettings::IniFormat) {
}
