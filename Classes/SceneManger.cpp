//
//  SceneManger.cpp
//  HelloWorld
//
//  Created by david on 2017/9/7.
//
//

#include "SceneManger.hpp"
#include "LoadLayer.hpp"
#include "OpenLayer.hpp"
#include "ClockLayer.hpp"

void SceneManger::createLoadScene() {
    
    sceLoad = Scene::create();
    LoadLayer *layer = LoadLayer::create();
    layer->tsm = this;
    sceLoad->addChild(layer);
}

void SceneManger::goOpenScene() {
    sceOpen = Scene::create();
    OpenLayer *layer = OpenLayer::create();
    layer->tsm = this;
    sceOpen->addChild(layer);
    
    Director::getInstance()->replaceScene(sceOpen);
}

void SceneManger::goClockScene() {
    sceClock = Scene::create();
    ClockLayer *layer = ClockLayer::create();
    layer->tsm = this;
    sceClock->addChild(layer);
    
    Director::getInstance()->replaceScene(sceClock);
}
