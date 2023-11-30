#include "PlayScene.h"
#include "Player.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Camera::SetPosition({ 0, 10, -10 });
	Camera::SetTarget({ 0,0,-5 });
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
