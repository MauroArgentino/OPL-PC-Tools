/***********************************************************************************************
 *                                                                                             *
 * This file is part of the OPL PC Tools project, the graphical PC tools for Open PS2 Loader.  *
 *                                                                                             *
 * OPL PC Tools is free software: you can redistribute it and/or modify it under the terms of  *
 * the GNU General Public License as published by the Free Software Foundation,                *
 * either version 3 of the License, or (at your option) any later version.                     *
 *                                                                                             *
 * OPL PC Tools is distributed in the hope that it will be useful,  but WITHOUT ANY WARRANTY;  *
 * without even the implied warranty of  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *
 * See the GNU General Public License for more details.                                        *
 *                                                                                             *
 * You should have received a copy of the GNU General Public License along with MailUnit.      *
 * If not, see <http://www.gnu.org/licenses/>.                                                 *
 *                                                                                             *
 ***********************************************************************************************/

#ifndef __OPLPCTOOLS_GAMECOLLECTIONWIDGET__
#define __OPLPCTOOLS_GAMECOLLECTIONWIDGET__

#include <QDir>
#include <QPixmap>
#include <QWidget>
#include <QSortFilterProxyModel>
#include <OplPcTools/Core/GameArtManager.h>
#include <OplPcTools/UI/UIContext.h>
#include "ui_GameCollectionWidget.h"

namespace OplPcTools {
namespace UI {

class GameCollectionWidget : public QWidget, private Ui::GameCollectionWidget
{
    class GameTreeModel;

    Q_OBJECT

public:
    explicit GameCollectionWidget(UIContext & _context, QWidget * _parent = nullptr);
    ~GameCollectionWidget() override;
    bool tryLoadRecentDirectory();
    void load(const QDir & _directory);

private:
    void applySettings();
    void saveSettings();
    void activateCollectionControls(bool _activate);
    void activateItemControls(bool _activate);

private slots:
    void load();
    void reload();
    void collectionLoaded();
    void changeIconsSize();
    void gameSelected();
    void showGameDetails();

private:
    UIContext & mr_context;
    OplPcTools::Core::GameArtManager * mp_game_art_manager;
    GameTreeModel * mp_model;
    QSortFilterProxyModel * mp_proxy_model;
    QPixmap m_default_cover;
};

} // namespace UI
} // namespace OplPcTools

#endif // __OPLPCTOOLS_GAMECOLLECTIONWIDGET__