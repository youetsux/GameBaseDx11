#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

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
    transform_.position_ = { 0, 0, 0 };
    //SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
    SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 0.5f);
    AddCollider(collision);
}

void Bullet::Update()
{
    transform_.position_.z += 0.1;
    if (transform_.position_.z >= 40.0f)
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
