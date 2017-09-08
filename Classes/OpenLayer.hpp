//
//  OpenLayer.hpp
//  HelloWorld
//
//  Created by david on 2017/9/7.
//
//

#ifndef OpenLayer_hpp
#define OpenLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManger.hpp"
USING_NS_CC;

class OpenLayer: public Layer {
    
    
public:
    
    CREATE_FUNC(OpenLayer);
    virtual bool init();
    void menuCallBack(Ref *pSender);
public:
    SceneManger *tsm;

};

#endif /* OpenLayer_hpp */
