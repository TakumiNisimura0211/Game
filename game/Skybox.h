#include "lib\\SkinModelData.h"

class CSkybox :public SkinModel
{
public:
	CSkybox();
	~CSkybox();
	void Initialize();
	void Update();
private:
	//SkinModel model;
	SkinModelData modelData;
	//Animation animation;
	Light light;

	//ÉÇÉfÉãÇÃç¿ïWÇ∆Ç©
	D3DXVECTOR3 vec;
	D3DXQUATERNION rot;
	D3DXVECTOR3 scale;
};