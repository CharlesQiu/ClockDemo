//
//  LoadLayer.cpp
//  HelloWorld
//
//  Created by david on 2017/9/7.
//
//

#include "LoadLayer.hpp"

bool LoadLayer::init() {
    
    Size winSize = Director::getInstance()->getWinSize();

    Label *label = Label::createWithTTF("Loading...", "fonts/Marker Felt.ttf", 32);
    label->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    this->addChild(label);
    
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2.0);
    
    return true;
}

void LoadLayer::onScheduleOnce(float dt) {
    tsm->goOpenScene();
}
