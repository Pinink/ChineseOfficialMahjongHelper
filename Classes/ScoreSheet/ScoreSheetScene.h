﻿#ifndef __SCORE_SHEET_SCENE_H__
#define __SCORE_SHEET_SCENE_H__

#include "../BaseLayer.h"

class ScoreSheetScene : public BaseLayer {
public:
    static cocos2d::Scene *createScene();

    virtual bool init() override;

    CREATE_FUNC(ScoreSheetScene);

private:
    cocos2d::ui::EditBox *_editBox[4];
    cocos2d::Label *_nameLabel[4];
    int _totalScores[4];
    cocos2d::ui::Button *_lockButton;
    cocos2d::Label *_totalLabel[4];
    cocos2d::Label *_scoreLabels[16][4];
    cocos2d::ui::Button *_recordButton[16];
    cocos2d::ui::Button *_detailButton[16];
    cocos2d::Label *_pointNameLabel[16];
    cocos2d::Label *_timeLabel;

    void fillRow(size_t handIdx);
    void refreshStartTime();
    void refreshEndTime();
    void recover();
    void reset();
    void onLockButton(cocos2d::Ref *sender);
    void onRecordButton(cocos2d::Ref *sender, size_t handIdx);
    void onDetailButton(cocos2d::Ref *sender, size_t handIdx);
    void onTimeScheduler(float dt);
    void onPursuitButton(cocos2d::Ref *sender);
};

#endif // __SCORE_SHEET_SCENE_H__
