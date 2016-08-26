/*!
 * @brief	ゲームクラス。
 */

#pragma once

#include"Player.h"
#include"Enemy.h"
#include"Skybox.h"

/*!
 * @brief	ゲームクラス。
 */
class Game{
public:
	/*!
	 * @brief	コンストラクタ。
	 */
	Game();
	/*!
	 * @brief	デストラクタ。
	 */
	~Game();
	/*!
	 * @brief	ゲームが起動してから一度だけ呼ばれる関数。
	 */
	void Start();
	/*!
	 * @brief	更新。
	 */
	void Update();
	/*!
	 * @brief	描画。
	 */
	void Render();
private:
	Camera camera;
	CPlayer m_pPlayer;
	CEnemy m_pEnemy;
	CSkybox m_pSkybox;
	D3DXVECTOR3 center;
};

extern Game* game;