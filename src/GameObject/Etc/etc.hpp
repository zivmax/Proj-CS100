#ifndef ETC_HPP__
#define ETC_HPP__


#include "GameObject.hpp"


class EmptyObject : public GameObject
{
    public:
        EmptyObject(pGameWorld belonging_world);

        virtual void Update() override;
        virtual void OnClick() override;
};

class BackGround : public GameObject
{
    public:
        BackGround(pGameWorld belonging_world);

        virtual void Update() override;
        virtual void OnClick() override;
};


class Sun : public GameObject
{
    public:
        Sun(int x, int y, pGameWorld belonging_world);

        virtual void OnClick() override;

    protected:
        int m_drop_ticks = -1;
        int m_elapsed_ticks = -1;
};

class FlowerSun : public Sun
{
    public:
        FlowerSun(int x, int y, pGameWorld belonging_world);

        virtual void Update() override;
};

class WorldSun : public Sun
{
    public:
        WorldSun(int x, int y, pGameWorld belonging_world);

        virtual void Update() override;
};


class PlantingSpot : public GameObject
{
    public:
        PlantingSpot(int x, int y, pGameWorld belonging_world);

        virtual void Update() override;
        virtual void OnClick() override;
};


class Shovel : public GameObject
{
    public:
        Shovel(pGameWorld belonging_world);

        virtual void Update() override;
        virtual void OnClick() override;
};


class AttackingObj : public GameObject
{
    public:
        AttackingObj(pGameWorld belonging_world, ImageID imageID, AnimID animID, int AP, int x, int y, int width, int height);

        virtual void OnClick() override;
        virtual void OnCollision(const GameObject &other) override;
};


class Pea : public AttackingObj
{
    public:
        Pea(int x, int y, pGameWorld belonging_world);

        virtual void Update() override;
};


class Explosion : public AttackingObj
{
    public:
        Explosion(int x, int y, pGameWorld belonging_world);

        virtual void Update() override;
};


class BombShrapnel : public AttackingObj
{
    public:
        BombShrapnel(int x, int y, pGameWorld belonging_world);

        virtual void Update() override;
};

#endif // !BACK_GROUND_HPP__