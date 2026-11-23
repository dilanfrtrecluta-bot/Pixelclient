// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "BrightTheme.h"

// An optional light theme. Existing and custom themes remain unchanged.
class PixelLightTheme : public BrightTheme {
   public:
    QString id() override;
    QString name() override;
    QString tooltip() override;
    QPalette colorScheme() override;
    bool hasStyleSheet() override;
    QString appStyleSheet() override;
};
