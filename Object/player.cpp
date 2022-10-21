#include "DxLib.h"
#include "game.h"
#include "player.h"
#include "SceneMain.h"

namespace
{
	// X方向、Y方向の最大速度
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;

	//ショットの発生間隔（フレーム数）
	constexpr int kShotInterval = 8;
}

//コンストラクタの初期化子
Player::Player() :
	m_pMain(nullptr),
	m_handle(-1),
	m_shotInterval(0),
	m_isExist(false),
	m_pos(),
	m_vec(),
	m_graphSize()
{
}

Player::~Player()
{
	
}

void Player::setHandle(int handle) 
{
	m_handle = handle;
	GetGraphSizeF(m_handle, &m_graphSize.x, &m_graphSize.y);
}

void Player::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_isExist = true;

	m_shotInterval = kShotInterval;
}

void Player::update()
{
	if (!m_isExist)	return;
	m_shotInterval--;
	if (m_shotInterval < 0)	m_shotInterval = 0;

	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_vec.y -= kAcc;
		if (m_vec.y < -kSpeedMax)	m_vec.y = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_vec.y += kAcc;
		if (m_vec.y > kSpeedMax)	m_vec.y = kSpeedMax;
	}
	else
	{
		m_vec.y *= 0.9f;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	else
	{
		m_vec.x *= 0.9f;
	}

	if (padState & PAD_INPUT_1)
	{
		if ((m_pMain) && (m_shotInterval <= 0))
		{
			m_pMain->createShot(m_pos,true);
			m_shotInterval = kShotInterval;
		}
	}

	m_pos += m_vec;
}

void Player::draw()
{
	if (!m_isExist)	return;
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}