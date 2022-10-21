#pragma once

#include "Vec2.h"
class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player();

	//SceneMainに値を設定
	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// グラフィックデータ設定
	void setHandle(int handle);

	// プレイヤーの初期化
	void init();

	// 処理
	void update();
	// 描画
	void draw();

	//存在するか
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }
	Vec2 getColSize() const { return m_graphSize; }//右下座標

private:
	//シーンメインのポインタ
	SceneMain* m_pMain;

	int m_handle;
	//ショットの発生間隔
	int m_shotInterval;
	//存在フラグ
	bool m_isExist;
	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
	Vec2 m_graphSize;
};