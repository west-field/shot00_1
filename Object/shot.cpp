#include "DxLib.h"
#include "shot.h"
#include "game.h"
#include "enemy.h"


//コンストラクタ初期化子
Shot::Shot() :
	m_handle(-1),
	m_isExist(false),
	m_pos(100.0f,100.0f),
	m_vec(8.0f,0.0f),
	m_graphSize()
{
}

Shot::~Shot()
{

}

void Shot::setHandle(int handle)
{
	m_handle = handle; 
	GetGraphSizeF(m_handle, &m_graphSize.x, &m_graphSize.y);
}

void Shot::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;
}

void Shot::update()
{
	if (!m_isExist)	return;

	m_pos += m_vec;

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
	if (m_pos.y < 0 - m_graphSize.y)
	{
		m_isExist = false;
	}
}
// 表示
void Shot::draw()
{
	if (!m_isExist)	return;

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}

bool Shot::isCol(Enemy& enemy)
{
	//存在しない敵、存在しないたまには何も当たらない
	if (!m_isExist)	return false;
	if (!enemy.isExist())	return false;
	/*
	float shotWidth = 0;
	float shotHeight = 0;
	GetGraphSizeF(m_handle, &shotWidth, &shotHeight);
	*/
	float shotLeft		= m_pos.x;
	float shotTop		= m_pos.y;
	float shotRight		= m_pos.x + m_graphSize.x;
	float shotBottom	= m_pos.y + m_graphSize.y;
/*
	float enemyLeft		= enemy.getPos().x;
	float enemyTop		= enemy.getPos().y;
	float enemyRight	= enemy.getPos().x + enemy.getColWidth();
	float enemyBottom	= enemy.getPos().y + enemy.getColHeight();
*/
	float enemyLeft = enemy.getPos().x;
	float enemyTop = enemy.getPos().y;
	float enemyRight = enemy.getPos().x + enemy.getColSize().x;
	float enemyBottom = enemy.getPos().y + enemy.getColSize().y;

	if (enemyLeft > shotRight)	return false;
	if (enemyTop > shotBottom)	return false;
	if (enemyRight < shotLeft)	return false;
	if (enemyBottom < shotTop)	return false;

	return true;
}