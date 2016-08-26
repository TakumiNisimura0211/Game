/*!
 * @brief	�Q�[���N���X�B
 */

#pragma once

#include"Player.h"
#include"Enemy.h"
#include"Skybox.h"

/*!
 * @brief	�Q�[���N���X�B
 */
class Game{
public:
	/*!
	 * @brief	�R���X�g���N�^�B
	 */
	Game();
	/*!
	 * @brief	�f�X�g���N�^�B
	 */
	~Game();
	/*!
	 * @brief	�Q�[�����N�����Ă����x�����Ă΂��֐��B
	 */
	void Start();
	/*!
	 * @brief	�X�V�B
	 */
	void Update();
	/*!
	 * @brief	�`��B
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