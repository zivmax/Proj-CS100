#include "Seeds.hpp"


SeedBase::SeedBase(pGameWorld belonging_world, ImageID imageID, ObjectOnHands seed_type, int cooling_ticks, int cost_sun, int x)
    : GameObject(belonging_world, imageID, x, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION)
{
    m_type = ObjectType::HANDIBLE;
    m_cooling_ticks = cooling_ticks;
    m_seed_type = seed_type;
    m_cost_sun = cost_sun;
    m_row_on_lawn = 0;
}


void SeedBase::OnClick()
{
    int current_sun = m_belonging_world->GetSun();
    switch (m_belonging_world->GetObjectOnHands())
    {
        // Only when in empty hands, gamer can pick up a seed.
        case ObjectOnHands::NONE:
            if (current_sun >= m_cost_sun)
            {
                m_belonging_world->SetObjectOnHands(m_seed_type);
                m_belonging_world->SetSun(current_sun - m_cost_sun);

                /*
                 * The SeedCoolDownMask will cover the icon of the seed,
                 * and make the seed icon unclickable.
                 */
                m_belonging_world->AddObject(std::make_shared<SeedCoolDownMask>(GetX(), GetY(), m_cooling_ticks, m_belonging_world));
            }
            break;

        default:
            break;
    }
}


void SeedBase::Update() {}
