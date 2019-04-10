#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1024, 768, 32);
	DxLib_Init();

	// ビュー行列と射影行列の取得
	MATRIX view = GetCameraViewMatrix();
	MATRIX proj = GetCameraProjectionMatrix();

	// ビューポート行列（スクリーン行列）の作成
	float w = 1024.0f / 2.0f;
	float h = 768.0f / 2.0f;

	MATRIX viewport = {
		w , 0 , 0 , 0 ,
		0 ,-h , 0 , 0 ,
		0 , 0 , 1 , 0 ,
		w , h , 0 , 1
	};

	VECTOR screenPos, tmp = VGet(320.0f, 200.0f, 0.0f);
	// ビュー変換とプロジェクション変換
	tmp = VTransform(tmp, view);
	tmp = VTransform(tmp, proj);
	// zで割って-1~1の範囲に収める
	tmp.x /= tmp.z; tmp.y /= tmp.z; tmp.z /= tmp.z;
	// スクリーン変換
	screenPos = VTransform(tmp, viewport);


	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	// ３Ｄ空間上に球を描画する
	DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

	DrawCircle(static_cast<int>(screenPos.x), static_cast<int>(screenPos.y), 10, 255, true);

	// キー入力待ちをする
	WaitKey();

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}