// SPDX-License-Identifier: GPL-3.0-only
#include "PixelLightTheme.h"

#include <QObject>

QString PixelLightTheme::id()
{
    return "pixel-light";
}

QString PixelLightTheme::name()
{
    return QObject::tr("Pixel Light");
}

QString PixelLightTheme::tooltip()
{
    return QObject::tr("A clean, light theme with soft blue accents.");
}

QPalette PixelLightTheme::colorScheme()
{
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#f5f7fb"));
    palette.setColor(QPalette::WindowText, QColor("#202a3b"));
    palette.setColor(QPalette::Base, QColor("#ffffff"));
    palette.setColor(QPalette::AlternateBase, QColor("#f5f7fb"));
    palette.setColor(QPalette::ToolTipBase, QColor("#202a3b"));
    palette.setColor(QPalette::ToolTipText, QColor("#ffffff"));
    palette.setColor(QPalette::Text, QColor("#202a3b"));
    palette.setColor(QPalette::Button, QColor("#ffffff"));
    palette.setColor(QPalette::ButtonText, QColor("#202a3b"));
    palette.setColor(QPalette::BrightText, QColor("#b42318"));
    palette.setColor(QPalette::Link, QColor("#315bc4"));
    palette.setColor(QPalette::Highlight, QColor("#315bc4"));
    palette.setColor(QPalette::HighlightedText, QColor("#ffffff"));
    palette.setColor(QPalette::PlaceholderText, QColor("#687386"));
    palette.setColor(QPalette::Disabled, QPalette::Text, QColor("#8490a3"));
    palette.setColor(QPalette::Disabled, QPalette::WindowText, QColor("#8490a3"));
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor("#8490a3"));
    return palette;
}

bool PixelLightTheme::hasStyleSheet()
{
    return true;
}

QString PixelLightTheme::appStyleSheet()
{
    // Keep the rules deliberately small: native controls, icons and existing
    // custom delegates remain responsible for their own rendering.
    return QStringLiteral(R"(
        QWidget#instanceHeader { background: #ffffff; border-bottom: 1px solid #e0e6ef; }
        QLabel#instanceSubtitle { color: #5b677b; }
        QToolButton#addInstanceHeaderButton { padding: 8px 14px; border: 1px solid #cbd4e2; background: #f5f7fb; }
        QToolButton#addInstanceHeaderButton:hover { background: #e6ecf8; }
        QToolBar { spacing: 5px; padding: 6px; border: 0; }
        QToolButton { padding: 5px; border: 1px solid transparent; border-radius: 6px; }
        QToolButton:hover { background: #e6ecf8; }
        QToolButton:pressed, QToolButton:checked { background: #d8e3fa; }
        QToolButton:focus { border: 1px solid #315bc4; }
        QPushButton { padding: 6px 14px; border: 1px solid #cbd4e2; border-radius: 6px; background: #ffffff; }
        QPushButton:hover:!disabled { background: #edf2fc; border-color: #9aadd2; }
        QPushButton:pressed:!disabled { background: #d8e3fa; }
        QPushButton:focus { border: 2px solid #315bc4; }
        QPushButton:disabled { background: #eef1f5; color: #8490a3; }
        QLineEdit { padding: 6px 8px; border: 1px solid #cbd4e2; border-radius: 6px; background: #ffffff; }
        QLineEdit:focus { border: 2px solid #315bc4; }
        QTabBar::tab { padding: 8px 14px; margin-right: 3px; }
        QTabBar::tab:selected { border-bottom: 2px solid #315bc4; }
    )");
}
