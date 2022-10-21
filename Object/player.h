#pragma once

#include "Vec2.h"
class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player();

	//SceneMain�ɒl��ݒ�
	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int handle) { m_handle = handle; }

	// �v���C���[�̏�����
	void init();

	// ����
	void update();
	// �`��
	void draw();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

private:
	//�V�[�����C���̃|�C���^
	SceneMain* m_pMain;

	int m_handle;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
};