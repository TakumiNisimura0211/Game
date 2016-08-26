/*
Playerクラス
*/

#pragma once

class CEnemy : public SkinModel
{
public:
	CEnemy();
	~CEnemy();
	void Initialize();
	void Update();
private:
	SkinModel model;
	SkinModelData modelData;
	Animation animation;
	Light light;

	//モデルの座標とか
	D3DXVECTOR3 vec;
	D3DXQUATERNION rot;
	D3DXVECTOR3 scale;
};