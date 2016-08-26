/*
	Player
*/

#include"stdafx.h"
#include"Player.h"

/*!
* @brief	コンストラクタ。
*/
CPlayer::CPlayer()
{

	//ライトを初期化。
	light.SetDiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetDiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetDiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetAmbientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));

	modelData.LoadModelData("Assets/model/Unity.X", &animation);

	Init(&modelData);
	SetLight(&light);
	animation.PlayAnimation(0,true);

	//初期位置
	vec = D3DXVECTOR3(0.4f, 0.0f, 3.0f);
	//クォンタニオン
	D3DXQuaternionRotationAxis(&rot, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXToRadian(200.0f));
	//スケール
	scale = D3DXVECTOR3(0.5f, 0.5f, 0.5f);

	UpdateWorldMatrix(vec, rot, scale);
}
/*!
* @brief	デストラクタ。
*/
CPlayer::~CPlayer()
{
}
void CPlayer::Initialize()
{

}
void CPlayer::Update()
{
	if (animation.GetEnd())
		animation.PlayAnimation(0, true);
	animation.Update(1.0f / 60.0f);
	UpdateWorldMatrix(vec, rot, scale);
}