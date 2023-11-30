#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"),hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Model\\bullet.fbx");
    assert(hModel_ >= 0);
    transform_.position_ = { 1, 0, 0 };

}

void Bullet::Update()
{
    transform_.position_.z += 0.1;
    if (transform_.position_.z >= 80.0f)
    {
        KillMe();
    }
}

void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Bullet::Release()
{
}
