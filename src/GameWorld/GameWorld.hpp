#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"
#include "GameObject.hpp"
#include "plants.hpp"
#include "zombies.hpp"
#include "etc.hpp"
#include "utils.hpp"


class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
    public:
        // Use shared_from_this() instead of "this".
        GameWorld();
        virtual ~GameWorld();

        void Init() override;

        LevelStatus Update() override;

        void CleanUp() override;

    private:
        std::list<std::shared_ptr<GameObject>> m_objects;
};

#endif // !GAMEWORLD_HPP__
