/*!
 * @brief	ゲーム
 */
#include "stdafx.h"
#include "game.h"


/*!
 * @brief	コンストラクタ。
 */
Game::Game()
{
	//注視点
	center = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}
/*!
 * @brief	デストラクタ。
 */
Game::~Game()
{
}
/*!
 * @brief	ゲームが起動してから一度だけ呼ばれる関数。
 */
void Game::Start()
{
	//カメラ初期化。
	camera.Init();
	camera.SetEyePt(D3DXVECTOR3(0.0f, 0.5f, 5.0f));
	camera.SetLookatPt(center);
	camera.Update();

	m_pPlayer.Initialize();
	m_pEnemy.Initialize();
	m_pSkybox.Initialize();
}
/*!
 * @brief	更新。
 */
void Game::Update()
{
	m_pPlayer.Update();
	m_pEnemy.Update();
	m_pSkybox.Update();
	camera.Update();
}
/*!
 * @brief	描画。
 */
void Game::Render()
{
	m_pPlayer.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
	m_pEnemy.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
	m_pSkybox.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
}
