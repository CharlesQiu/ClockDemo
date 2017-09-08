//
//  SceneManger.hpp
//  HelloWorld
//
//  Created by david on 2017/9/7.
//
//

#ifndef SceneManger_hpp
#define SceneManger_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class SceneManger {
    
    
public:
    
    Scene *sceLoad;
    Scene *sceOpen;
    Scene *sceClock;
    
    void createLoadScene();
    void goOpenScene();
    void goClockScene();
};

#endif /* SceneManger_hpp */
