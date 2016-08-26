/*!
 * @brief	�Q�[��
 */
#include "stdafx.h"
#include "game.h"


/*!
 * @brief	�R���X�g���N�^�B
 */
Game::Game()
{
	//�����_
	center = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}
/*!
 * @brief	�f�X�g���N�^�B
 */
Game::~Game()
{
}
/*!
 * @brief	�Q�[�����N�����Ă����x�����Ă΂��֐��B
 */
void Game::Start()
{
	//�J�����������B
	camera.Init();
	camera.SetEyePt(D3DXVECTOR3(0.0f, 0.5f, 5.0f));
	camera.SetLookatPt(center);
	camera.Update();

	m_pPlayer.Initialize();
	m_pEnemy.Initialize();
	m_pSkybox.Initialize();
}
/*!
 * @brief	�X�V�B
 */
void Game::Update()
{
	m_pPlayer.Update();
	m_pEnemy.Update();
	m_pSkybox.Update();
	camera.Update();
}
/*!
 * @brief	�`��B
 */
void Game::Render()
{
	m_pPlayer.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
	m_pEnemy.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
	m_pSkybox.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
}
