#ifndef BACK_GROUND_HPP__
#define BACK_GROUND_HPP__


#include "GameObject.hpp"


class BackGround : public GameObject
{
    public:
        BackGround() : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}

        void Update() override;
        void OnClick() override;
};

#endif // !BACK_GROUND_HPP__