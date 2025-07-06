#include "DxLib.h"

namespace
{
	int constexpr kScreenWidth = 1280;
	int constexpr kScreenHeight = 720;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	SetGraphMode(kScreenWidth, kScreenHeight,0);

	SetWindowSizeChangeEnableFlag(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		//��ʂ��N���A
		ClearDrawScreen();

		//ESC�L�[�������ꂽ��E�B���h�E�����
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//�����ɃQ�[���̏����Ȃǂ�����
		//DrawPixel(kScreenWidth / 2, kScreenHeight / 2, GetColor(255,255,255));

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

	}

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}