#include "Player.h"
#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

Player::~Player()
{
	//後片付け
}

void Player::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Model\\player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,-5 };
}

void Player::Update()
{
	//左右移動
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x -= 0.1f;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x += 0.1f;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet *p = Instantiate<Bullet>(this->GetParent());
		p->SetPosition(this->transform_.position_);//プレイヤーの位置
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
