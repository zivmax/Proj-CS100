#include "GameObject.hpp"

GameObject::GameObject(pGameWorld ptr_gameworld, ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID) : ObjectBase(imageID, x, y, layer, width, height, animID), m_belonging_world(ptr_gameworld)
{
    m_row_on_lawn = (y - FIRST_ROW_CENTER) / LAWN_GRID_HEIGHT + 1;
}


void GameObject::SelfKill()
{
    m_is_dead = true;
}


bool GameObject::IsDead() const
{
    return m_is_dead;
}

int GameObject::GetAP() const
{
    return m_AP;
}


void GameObject::OnCollision(const GameObject &obj) {}


// These funcs use const GameObject &obj as parameter.
bool GameObject::IsPlant(const GameObject &obj)
{
    return obj.m_type == ObjectType::PLANT;
}

bool GameObject::IsAttackingObject(const GameObject &obj)
{
    return obj.m_type == ObjectType::ATTACKING_OBJECT;
}

bool GameObject::IsZombie(const GameObject &obj)
{
    return obj.m_type == ObjectType::ZOMBIE;
}


void GameObject::InitCollisionStatus(GameObject &obj)
{
    obj.m_is_colliding = false;
}


bool GameObject::AreCollidable(const GameObject &obj1, const GameObject &obj2)
{
    if (obj1.m_row_on_lawn != obj2.m_row_on_lawn)
    {
        return false;
    }
    else if (obj1.m_is_dead || obj2.m_is_dead)
    {
        return false;
    }
    else if (obj1.m_type == ObjectType::ATTACKING_OBJECT)
    {
        if (obj2.m_type == ObjectType::ZOMBIE)
            return true;
    }
    else if (obj1.m_type == ObjectType::PLANT)
    {
        if (obj2.m_type == ObjectType::ZOMBIE)
            return true;
    }
    else if (obj1.m_type == ObjectType::ZOMBIE)
    {
        if (obj2.m_type == ObjectType::ATTACKING_OBJECT || obj2.m_type == ObjectType::PLANT)
            return true;
    }
    else
    {
        return false;
    }

    return false;
}


bool GameObject::AreColliding(GameObject &obj1, GameObject &obj2)
{
    int diff_x = std::abs(obj1.GetX() - obj2.GetX());

    if (diff_x <= (obj1.GetWidth() / 2 + obj2.GetWidth() / 2))
    {
        return true;
    }
    else
    {
        return false;
    }

    return false;
}


bool GameObject::UpdateCollisionStatus(GameObject &obj1, GameObject &obj2)
{
    // We only check the ollision of two objects
    // if they are on the same row and their type need to be checked.
    if (GameObject::AreCollidable(obj1, obj2))
    {
        if (GameObject::AreColliding(obj1, obj2))
        {
            obj1.m_is_colliding = true;
            obj2.m_is_colliding = true;

            obj1.OnCollision(obj2);
            obj2.OnCollision(obj1);

            return true;
        }
    }

    obj1.m_is_colliding = false;
    obj2.m_is_colliding = false;
    return false;
}


// These funcs use const pointer of GameObject &obj as parameter.
bool GameObject::IsPlant(const pGameObject &obj)
{
    return obj->m_type == ObjectType::PLANT;
}

bool GameObject::IsAttackingObject(const pGameObject &obj)
{
    return obj->m_type == ObjectType::ATTACKING_OBJECT;
}

bool GameObject::IsZombie(const pGameObject &obj)
{
    return obj->m_type == ObjectType::ZOMBIE;
}


void GameObject::InitCollisionStatus(pGameObject &obj)
{
    obj->m_is_colliding = false;
}


bool GameObject::AreCollidable(const pGameObject &obj1, const pGameObject &obj2)
{
    if (obj1->m_row_on_lawn != obj2->m_row_on_lawn)
    {
        return false;
    }
    else if (obj1->m_is_dead || obj2->m_is_dead)
    {
        return false;
    }
    else if (obj1->m_type == ObjectType::ATTACKING_OBJECT)
    {
        if (obj2->m_type == ObjectType::ZOMBIE)
            return true;
    }
    else if (obj1->m_type == ObjectType::PLANT)
    {
        if (obj2->m_type == ObjectType::ZOMBIE)
            return true;
    }
    else if (obj1->m_type == ObjectType::ZOMBIE)
    {
        if (obj2->m_type == ObjectType::ATTACKING_OBJECT || obj2->m_type == ObjectType::PLANT)
            return true;
    }
    else
    {
        return false;
    }

    return false;
}

bool GameObject::AreColliding(pGameObject &obj1, pGameObject &obj2)
{
    int diff_x = std::abs(obj1->GetX() - obj2->GetX());

    if (diff_x <= (obj1->GetWidth() / 2 + obj2->GetWidth() / 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool GameObject::UpdateCollisionStatus(pGameObject &obj1, pGameObject &obj2)
{
    // We only check the ollision of two objects
    // if they are on the same row and their type need to be checked.
    if (GameObject::AreCollidable(obj1, obj2))
    {
        if (GameObject::AreColliding(obj1, obj2))
        {
            obj1->m_is_colliding = true;
            obj2->m_is_colliding = true;

            obj1->OnCollision(*obj2);
            obj2->OnCollision(*obj1);

            return true;
        }
    }

    obj1->m_is_colliding = (obj1->m_is_colliding) ? true : false;
    obj2->m_is_colliding = (obj2->m_is_colliding) ? true : false;
    return false;
}
