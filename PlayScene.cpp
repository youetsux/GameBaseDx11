#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	for (int i = 0; i < 50; i++) {
		Instantiate<Enemy>(this);
	}
	Camera::SetPosition({ 0, 8, -10 });
	Camera::SetTarget({ 0,3, 0 });
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
