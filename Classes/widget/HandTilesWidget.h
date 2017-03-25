﻿#ifndef __HAND_TILES_WIDGETS_H__
#define __HAND_TILES_WIDGETS_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "../mahjong-algorithm/tile.h"

class HandTilesWidget : public cocos2d::ui::Widget {
public:
    CREATE_FUNC(HandTilesWidget);

    static cocos2d::Node *createStaticNode(const mahjong::hand_tiles_t &handTiles, mahjong::tile_t servingTile);

    const std::vector<mahjong::tile_t> &getStandingTiles() const { return _standingTiles; }
    const std::vector<mahjong::pack_t> &getFixedPacks() const { return _fixedPacks; }

    void setCurrentIdxChangedCallback(const std::function<void ()> &callback) { _currentIdxChangedCallback = callback; }
    void setTileClickCallback(const std::function<void ()> &callback) { _tileClickCallback = callback; }

    size_t getCurrentIdx() const { return _currentIdx; }
    mahjong::tile_t getCurrentTile() const { return _currentIdx < _standingTiles.size() ? _standingTiles[_currentIdx] : 0; }
    int getUsedTileCount(mahjong::tile_t tile) const { return _usedTilesTable[tile]; }
    int getStandingTileCount(mahjong::tile_t tile) const { return _standingTilesTable[tile]; }

    void setData(const mahjong::hand_tiles_t &handTiles, mahjong::tile_t servingTile);
    void getData(mahjong::hand_tiles_t *handTiles, mahjong::tile_t *servingTile) const;

    mahjong::tile_t getServingTile() const;
    bool isFixedPacksContainsKong() const;
    bool isStandingTilesContainsServingTile() const;
    size_t countServingTileInFixedPacks() const;

CC_CONSTRUCTOR_ACCESS:
    virtual bool init() override;

public:
    void reset();
    void sortStandingTiles();
    mahjong::tile_t putTile(mahjong::tile_t tile);

    bool canChow_XX();
    bool canChowX_X();
    bool canChowXX_();
    bool canPung();
    bool canKong();

    bool makeFixedChow_XXPack();
    bool makeFixedChowX_XPack();
    bool makeFixedChowXX_Pack();
    bool makeFixedPungPack();
    bool makeFixedMeldedKongPack();
    bool makeFixedConcealedKongPack();

private:
    cocos2d::ui::Widget *_fixedContainer;
    cocos2d::ui::Widget *_standingContainer;
    std::vector<cocos2d::ui::Button *> _standingTileButtons;
    cocos2d::DrawNode *_highlightBox;

    int _usedTilesTable[mahjong::TILE_TABLE_SIZE];
    int _standingTilesTable[mahjong::TILE_TABLE_SIZE];
    std::vector<mahjong::tile_t> _standingTiles;
    std::vector<mahjong::pack_t> _fixedPacks;
    size_t _currentIdx;

    std::function<void ()> _currentIdxChangedCallback;
    std::function<void ()> _tileClickCallback;

private:
    void addTile(mahjong::tile_t tile);
    void replaceTile(mahjong::tile_t tile);
    void refreshHighlightPos();
    void refreshStandingTiles();
    void refreshStandingTilesPos();

    void onTileButton(cocos2d::Ref *sender);

    int calcMeldedIdx(int maxIdx) const;
    void addFixedChowPack(mahjong::tile_t tile, int meldedIdx);
    void addFixedPungPack(mahjong::tile_t tile, int meldedIdx);
    void addFixedMeldedKongPack(mahjong::tile_t tile, int meldedIdx);
    void addFixedConcealedKongPack(mahjong::tile_t tile);
};

#endif
