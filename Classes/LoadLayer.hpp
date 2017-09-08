//
//  LoadLayer.hpp
//  HelloWorld
//
//  Created by david on 2017/9/7.
//
//

#ifndef LoadLayer_hpp
#define LoadLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManger.hpp"
USING_NS_CC;

class LoadLayer: public Layer {
    
    
public:
    
    CREATE_FUNC(LoadLayer);
    virtual bool init();
    void onScheduleOnce(float dt);
public:
    SceneManger *tsm;
};
#endif /* LoadLayer_hpp */
