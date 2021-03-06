// albert - a simple application launcher for linux
// Copyright (C) 2014-2015 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <QWidget>
#include <QLineEdit>
#include "proposallist.h"
#include "inputline.h"
#include "ui_mainwidget.h"

class MainWidget final : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

    void show();
    void hide();
    void toggleVisibility();

    bool showCenterd() const;
    void setShowCentered(bool b = true);

    const QString &theme() const;
    bool setTheme(const QString& theme);

    Ui::MainWidget ui;

private:
    void closeEvent(QCloseEvent * event);
    void keyPressEvent(QKeyEvent * event);
    bool nativeEvent(const QByteArray &eventType, void *message, long *) override;

    QString _theme;
    bool _showCentered;

    static const constexpr char* CFG_CENTERED     = "showCentered";
    static const constexpr bool  CFG_CENTERED_DEF = true;
    static const constexpr char* CFG_THEME        = "theme";
    static const constexpr char* CFG_THEME_DEF    = "Standard";

signals:
    void widgetShown();
    void widgetHidden();
};
