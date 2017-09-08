//
//  ClockLayer.hpp
//  HelloWorld
//
//  Created by david on 2017/9/7.
//
//

#ifndef ClockLayer_hpp
#define ClockLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManger.hpp"
USING_NS_CC;

class ClockLayer: public Layer {
    
    
public:
    
    CREATE_FUNC(ClockLayer);
    virtual bool init();
    
    void menuCallBack(Ref *pSender);
    void timeUpdate(float dt);
    
public:
    SceneManger *tsm;

    Sprite *_dot;
    Sprite *_hour;
    Sprite *_minute;
    Sprite *_second;
    Sprite *_background;
    
    int hRotation;
    int mRotation;
    int sRotation;
};

#endif /* ClockLayer_hpp */
