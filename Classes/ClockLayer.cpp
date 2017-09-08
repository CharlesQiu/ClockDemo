//
//  ClockLayer.cpp
//  HelloWorld
//
//  Created by david on 2017/9/7.
//
//

#include "ClockLayer.hpp"

bool ClockLayer::init() {
    
    Layer *bg = LayerColor::create(Color4B(217, 217, 217, 255));
    this->addChild(bg,0);
    
    Size winSize = Director::getInstance()->getWinSize();

    MenuItemLabel *menuItem = MenuItemLabel::create(Label::createWithSystemFont("返回", "", 15), CC_CALLBACK_1(ClockLayer::menuCallBack, this));
    menuItem -> setColor(Color3B(100, 100, 100));
    menuItem->setPosition(Vec2(winSize.width * 0.9, winSize.height * 0.8));
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    _dot = Sprite::create("dot.png");
    _dot -> setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    _dot -> setScale(1);
    this -> addChild(_dot, 1);
    
    _second = Sprite::create("hand_second.png");
    _second -> setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    _second -> setScale(0.5);
    _second -> setAnchorPoint(Vec2(0, 0.5));
    this -> addChild(_second, 2);
    
    _minute = Sprite::create("hand_minute.png");
    _minute -> setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    _minute -> setScale(0.5);
    _minute -> setAnchorPoint(Vec2(0, 0.5));
    this -> addChild(_minute, 3);
    
    _hour = Sprite::create("hand_hour.png");
    _hour -> setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    _hour -> setScale(0.5);
    _hour -> setAnchorPoint(Vec2(0, 0.5));
    this -> addChild(_hour, 4);
    
    _background = Sprite::create("clock_face.png");
    _background -> setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    _background -> setScale(0.5);
    this -> addChild(_background);
    
    struct timeval nowTimeval;
    gettimeofday(&nowTimeval, NULL);
    struct tm *tm;
    time_t time_sec;
    time_sec = nowTimeval.tv_sec;
    tm = localtime(&time_sec);
    
    CCLOG("hour = %d, minute = %d, second = %d", tm -> tm_hour, tm -> tm_min, tm -> tm_sec);
    
    /// 因为图片水平，所以均需要减90度
    mRotation = tm->tm_min * 6 - 90;
    sRotation = tm->tm_sec * 6 - 90;
    
    if (tm -> tm_hour > 12) {
        hRotation = (tm->tm_hour - 12) * 5 * 6 + (mRotation / 72) * 6 - 90;
    } else {
        hRotation = tm->tm_hour * 5 * 6 + (mRotation / 72) * 6 - 90;
    }
    CCLOG("hRotation = %d", hRotation);
    _hour -> setRotation(hRotation);
    _minute -> setRotation(mRotation);
    _second -> setRotation(sRotation);
    
    schedule(CC_SCHEDULE_SELECTOR(ClockLayer::timeUpdate), 1.0);
    
    return true;
}

void ClockLayer::menuCallBack(Ref *pSender) {
    tsm -> goOpenScene();
}

void ClockLayer::timeUpdate(float dt) {
    
    _second -> setRotation(_second -> getRotation() + 6);
    if (_second -> getRotation() == 270) {
        _minute -> setRotation(_minute -> getRotation() + 6);
        _second -> setRotation(-90);
        if ((int)_minute -> getRotation() % 72 == -90) {
            _hour -> setRotation(_hour -> getRotation() + 6);
            if (_minute -> getRotation() == 270) {
                _minute -> setRotation(-90);
            }
        }
    }

}
