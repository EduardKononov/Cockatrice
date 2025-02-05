#ifndef VISUAL_DECK_STORAGE_WIDGET_H
#define VISUAL_DECK_STORAGE_WIDGET_H

#include "../../../../deck/deck_list_model.h"
#include "../../../ui/widgets/general/layout_containers/flow_widget.h"
#include "../cards/card_size_widget.h"
#include "deck_preview/deck_preview_color_identity_filter_widget.h"
#include "deck_preview/deck_preview_widget.h"
#include "visual_deck_storage_search_widget.h"
#include "visual_deck_storage_sort_widget.h"
#include "visual_deck_storage_tag_filter_widget.h"

#include <QFileSystemModel>

class VisualDeckStorageSearchWidget;
class VisualDeckStorageSortWidget;
class VisualDeckStorageTagFilterWidget;
class DeckPreviewColorIdentityFilterWidget;
class VisualDeckStorageWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit VisualDeckStorageWidget(QWidget *parent);
    void retranslateUi();

public slots:
    void deckPreviewClickedEvent(QMouseEvent *event, DeckPreviewWidget *instance);
    void deckPreviewDoubleClickedEvent(QMouseEvent *event, DeckPreviewWidget *instance);
    void refreshBannerCards(); // Refresh the display of cards based on the current sorting option
    QStringList gatherAllTagsFromFlowWidget() const;
    QStringList gatherAllTags(const QList<DeckPreviewWidget *> &allDecks);
    void updateSortOrder();

signals:
    void bannerCardsRefreshed();
    void deckPreviewClicked(QMouseEvent *event, DeckPreviewWidget *instance);
    void deckPreviewDoubleClicked(QMouseEvent *event, DeckPreviewWidget *instance);
    void deckLoadRequested(QString &filePath);

private:
    QVBoxLayout *layout;
    QHBoxLayout *searchAndSortLayout;
    FlowWidget *flowWidget;
    DeckListModel *deckListModel;
    QLabel *databaseLoadIndicator;

    VisualDeckStorageSortWidget *sortWidget;
    VisualDeckStorageSearchWidget *searchWidget;
    VisualDeckStorageTagFilterWidget *tagFilterWidget;
    DeckPreviewColorIdentityFilterWidget *deckPreviewColorIdentityFilterWidget;
    CardSizeWidget *cardSizeWidget;
};

#endif // VISUAL_DECK_STORAGE_WIDGET_H
