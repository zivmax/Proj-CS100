#include "Zombies.hpp"

static const int HP = 1300;
static const int AP = 3;

BucketZombie::BucketZombie(int x, int y, pGameWorld belonging_world)
    : ZombieBase(belonging_world, IMGID_BUCKET_HEAD_ZOMBIE, ANIMID_WALK_ANIM, AP, HP, x, y)
{
    m_speed = 1;
    m_has_bucket = true;
}


void BucketZombie::OnCollision(const GameObject &other)
{
    if (GameObject::IsPlant(other) && !m_is_eating)
    {
        m_is_eating = true;
        PlayAnimation(ANIMID_EAT_ANIM);
    }
    else
    {
        m_HP -= other.GetAP();
        if (0 < m_HP && m_HP <= 200 && m_has_bucket)
        {
            // Remove the bucket.
            ChangeImage(IMGID_REGULAR_ZOMBIE);
            m_has_bucket = false;
        }
        else if (m_HP <= 0)
        {
            SelfKill();
        }
    }
}
