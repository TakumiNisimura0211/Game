/*
Player
*/

#include"stdafx.h"
#include"Enemy.h"

/*!
* @brief	�R���X�g���N�^�B
*/
CEnemy::CEnemy()
{

	//���C�g���������B
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

	//�����ʒu
	vec = D3DXVECTOR3(-1.5f, 0.0f, -3.0f);
	//�N�H���^�j�I��
	D3DXQuaternionRotationAxis(&rot, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXToRadian(45.0f));
	D3DXQUATERNION q;
	D3DXQuaternionRotationAxis(&q, &D3DXVECTOR3(1.0f, 0.0f, 0.0f), D3DXToRadian(45.0f));
	/*rot = rot * q;*/
	//�X�P�[��
	scale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	UpdateWorldMatrix(vec, rot, scale);
}
/*!
* @brief	�f�X�g���N�^�B
*/
CEnemy::~CEnemy()
{
}
void CEnemy::Initialize()
{

}
void CEnemy::Update()
{
	animation.Update(1.0f / 60.0f);
	UpdateWorldMatrix(vec, rot, scale);
}