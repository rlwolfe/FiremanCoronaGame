#include "CollisionObjects.h"

//------include gameObjects------
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
//------include gameObjects------
#include "Player.h"
#include "Fire.h"
#include "Hydrant.h"
#include "Corona.h"
#include "Wall.h"
#include "WoodWall.h"
#include "Question.h"
#include "WaterShoot.h"
#include "FireEnemy.h"
#include "FireShoot.h"
#include "FireStation.h"
#include "AlcogelShoot.h"

namespace // anonymous namespace — controll all the collision function"
{
    void PlayerHydrant(GameObject & player,
         GameObject & hydrant){
         Player& fireman = dynamic_cast<Player&>(player);
         Hydrant& hyd = dynamic_cast<Hydrant&>(hydrant);
         if (hyd.getFill()) {
             fireman.add_water(HYDRANT_FILLUP);
         }
         fireman.getSprite().move(-fireman.getDirection() * fireman.getDeltaTime().asSeconds());//stopobject
     }

    void PlayerCorona(GameObject& player,
        GameObject& corona)
    {
        Player& fireman = dynamic_cast<Player&>(player);
        fireman.setSlow();
        corona.set_delete_me();
    }

    void PlayerHurt(GameObject& player, GameObject& hurtingobject)
    {//playerr collision by: fire, fireshoot, fireenemy
        Player& fireman = dynamic_cast<Player&>(player);
        fireman.decrease_life();
        hurtingobject.set_delete_me();
    }

    void HurtPlayer(GameObject& hurtingobject, GameObject& player)
    {//call PlayerHurt function
        PlayerHurt(player, hurtingobject);
    }

    void PlayerWoodWall(GameObject& player,
        GameObject& woodwall)
     
    { //player collision wood wall and check if holds axe so break the wall otherwise to player block
        Player& fireman = dynamic_cast<Player&>(player);
        fireman.getSprite().move(-fireman.getDirection() * fireman.getDeltaTime().asSeconds());
        if (fireman.getWeapon() == weapon::axe) {
            WoodWall& walll = dynamic_cast<WoodWall&>(woodwall);
            walll.set_delete_me();
        }
    }

    void PlayerFireStation(GameObject& player,
        GameObject& fireStation) 
    { //player collision fire station and check if can finish the game or isnt
        Player& fireman = dynamic_cast<Player&>(player);
        if (Question::getKey()) {
            fireman.setWin(true);
        }
        else
            fireman.getSprite().move(-fireman.getDirection() * fireman.getDeltaTime().asSeconds());
        Fire::resetCount();
    }

    void CoronaPlayer(GameObject& corona,
        GameObject& player)
    {
        PlayerCorona(player, corona);
    }
    
    void WaterShootFire(GameObject& waterShoot,
        GameObject& fire)
    {//fire putof so updated score+=15 and more fire adding to the question count
        WaterShoot& water = dynamic_cast<WaterShoot&>(waterShoot);
        water.set_delete_me();
        Fire& firee = dynamic_cast<Fire&>(fire);
        firee.set_delete_me();
        firee.fireOff();
    }

    void FireEnemyObject(GameObject& fireenemy, GameObject& Object)
    {//fireenemy hits object so detrmine this side has false and make him go other way
        FireEnemy& firenemy = dynamic_cast<FireEnemy&>(fireenemy);
        firenemy.setSideCollision(firenemy.getSide());
        firenemy.getSprite().move(-firenemy.getDirection() * firenemy.getDeltaTime().asSeconds());
    }

    void deleteFirstObject(GameObject& object1, GameObject& object2) {
        object1.set_delete_me();
    }

    void Movingstaticstop(GameObject& moving, GameObject& staticobject) {
        //moving object hits static object and block him for go the static place
        MovingObject& movobject = dynamic_cast<MovingObject&>(moving);
        movobject.getSprite().move(-movobject.getDirection() * movobject.getDeltaTime().asSeconds());
    }

    void Coronastatic(GameObject& corona, GameObject& staticobject) {
        //corona hits static object and change his way up or down
        Corona& cor = dynamic_cast<Corona&>(corona);
        cor.getSprite().move(-cor.getDirection() * cor.getDeltaTime().asSeconds());
        cor.switchSides();
    }

    void CoronahitCorona(GameObject& corona1, GameObject& corona2) {
        Corona& corona = dynamic_cast<Corona&>(corona1);
        corona.getSprite().move(-corona.getDirection() * corona.getDeltaTime().asSeconds());
        corona.switchSides();
        Corona& coro = dynamic_cast<Corona&>(corona2);
        coro.getSprite().move(-coro.getDirection() * coro.getDeltaTime().asSeconds());
        coro.switchSides();
    }

    void FireEnemyhitFireEnemy(GameObject& fireenemy1, GameObject& fireenemy2)
    {
        FireEnemy& firenemy = dynamic_cast<FireEnemy&>(fireenemy1);
        firenemy.setSideCollision(firenemy.getSide());
        firenemy.getSprite().move(-firenemy.getDirection() * firenemy.getDeltaTime().asSeconds());
        FireEnemy& firee = dynamic_cast<FireEnemy&>(fireenemy2);
        firee.setSideCollision(firee.getSide());
        firee.getSprite().move(-firee.getDirection() * firee.getDeltaTime().asSeconds());
    }

    void deleteSecendObject(GameObject& object1, GameObject& object2)
    {
        deleteFirstObject(object2, object1);
    }

    void deleteObjects(GameObject& object1, GameObject& object2)
    {//delete both object hits each other
        object1.set_delete_me();
        object2.set_delete_me();
    }

    using HitFunctionPtr = void (*)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(Fire))] = &PlayerHurt;
        phm[Key(typeid(Player), typeid(Hydrant))] = &PlayerHydrant;
        phm[Key(typeid(Player), typeid(Corona))] = &PlayerCorona;
        phm[Key(typeid(Player), typeid(WoodWall))] = &PlayerWoodWall;
        phm[Key(typeid(Player), typeid(Wall))] = &Movingstaticstop;
        phm[Key(typeid(Player), typeid(FireStation))] = &PlayerFireStation;
        phm[Key(typeid(Player), typeid(FireEnemy))] = &PlayerHurt;
        phm[Key(typeid(Player), typeid(FireShoot))] = &PlayerHurt;

        phm[Key(typeid(WaterShoot), typeid(Fire))] = &WaterShootFire;
        phm[Key(typeid(WaterShoot), typeid(Hydrant))] = &deleteFirstObject;
        phm[Key(typeid(WaterShoot), typeid(Wall))] = &deleteFirstObject;
        phm[Key(typeid(WaterShoot), typeid(WoodWall))] = &deleteFirstObject;
        phm[Key(typeid(WaterShoot), typeid(FireEnemy))] = &deleteObjects;
        phm[Key(typeid(WaterShoot), typeid(FireShoot))] = &deleteObjects;
        phm[Key(typeid(WaterShoot), typeid(Corona))] = &deleteFirstObject;
        phm[Key(typeid(WaterShoot), typeid(FireStation))] = &deleteFirstObject;

        phm[Key(typeid(Corona), typeid(Player))] = &CoronaPlayer;
        phm[Key(typeid(Corona), typeid(AlcogelShoot))] = &deleteObjects;
        phm[Key(typeid(Corona), typeid(WaterShoot))] = &deleteSecendObject;
        phm[Key(typeid(Corona), typeid(Wall))] = &Coronastatic;
        phm[Key(typeid(Corona), typeid(Hydrant))] = &Coronastatic;
        phm[Key(typeid(Corona), typeid(WoodWall))] = &Coronastatic;
        phm[Key(typeid(Corona), typeid(Fire))] = &Coronastatic;
        phm[Key(typeid(Corona), typeid(Hydrant))] = &Coronastatic;
        phm[Key(typeid(Corona), typeid(FireStation))] = &Coronastatic;
        phm[Key(typeid(Corona), typeid(FireEnemy))] = &Coronastatic;
        phm[Key(typeid(Corona), typeid(FireShoot))] = &deleteSecendObject;
        phm[Key(typeid(Corona), typeid(Corona))] = &CoronahitCorona;
        
        phm[Key(typeid(FireEnemy), typeid(WaterShoot))] = &deleteObjects;
        phm[Key(typeid(FireEnemy), typeid(Wall))] = &FireEnemyObject;
        phm[Key(typeid(FireEnemy), typeid(WoodWall))] = &FireEnemyObject;
        phm[Key(typeid(FireEnemy), typeid(Hydrant))] = &FireEnemyObject;
        phm[Key(typeid(FireEnemy), typeid(FireStation))] = &FireEnemyObject;
        phm[Key(typeid(FireEnemy), typeid(Fire))] = &FireEnemyObject;
        phm[Key(typeid(FireEnemy), typeid(Corona))] = &FireEnemyObject;
        phm[Key(typeid(FireEnemy), typeid(Player))] = &HurtPlayer;
        phm[Key(typeid(FireEnemy), typeid(AlcogelShoot))] = &deleteSecendObject;
        phm[Key(typeid(FireEnemy), typeid(FireEnemy))] = &FireEnemyhitFireEnemy;
        
        phm[Key(typeid(FireShoot), typeid(WaterShoot))] = &deleteObjects;
        phm[Key(typeid(FireShoot), typeid(Wall))] = &deleteFirstObject;
        phm[Key(typeid(FireShoot), typeid(WoodWall))] = &deleteFirstObject;
        phm[Key(typeid(FireShoot), typeid(Hydrant))] = &deleteFirstObject;
        phm[Key(typeid(FireShoot), typeid(FireStation))] = &deleteFirstObject;
        phm[Key(typeid(FireShoot), typeid(Fire))] = &deleteFirstObject;
        phm[Key(typeid(FireShoot), typeid(Corona))] = &deleteFirstObject;
        phm[Key(typeid(FireShoot), typeid(Player))] = &HurtPlayer;
        phm[Key(typeid(FireShoot), typeid(AlcogelShoot))] = &deleteSecendObject;

        phm[Key(typeid(AlcogelShoot), typeid(Wall))] = &deleteFirstObject;
        phm[Key(typeid(AlcogelShoot), typeid(WoodWall))] = &deleteFirstObject;
        phm[Key(typeid(AlcogelShoot), typeid(Fire))] = &deleteFirstObject;
        phm[Key(typeid(AlcogelShoot), typeid(FireStation))] = &deleteFirstObject;
        phm[Key(typeid(AlcogelShoot), typeid(Hydrant))] = &deleteFirstObject;
        phm[Key(typeid(AlcogelShoot), typeid(FireEnemy))] = &deleteFirstObject;
        phm[Key(typeid(AlcogelShoot), typeid(FireShoot))] = &deleteFirstObject;
        phm[Key(typeid(AlcogelShoot), typeid(Corona))] = &deleteObjects;
        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (phf)
        phf(object1, object2);
}