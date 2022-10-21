#pragma once

#include "Vec2.h"
class SceneMain;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	//SceneMain�ɒl��ݒ�
	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int handle);

	// �v���C���[�̏�����
	void init();

	// ����
	void update();
	// �`��
	void draw();

	//���݂��邩
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	// ���̎擾
	Vec2 getPos() const { return m_pos; }//������W
	Vec2 getColSize() const { return m_graphSize; }//�E�����W
	//�����蔻��̕��A�������擾
//	float getColWidth();
//	float getColHeight();
private:
	SceneMain* m_pMain;

	int m_handle;
	//�V���b�g�̔����Ԋu
	int m_shotInterval;
	//���݃t���O
	bool m_isExist;
	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
	//�O���t�B�b�N�T�C�Y
	Vec2 m_graphSize;
};