#pragma once

#ifdef _WIN32
#ifdef __SOYNET__
#define SOYNET_DLL __declspec(dllexport)
#else
#define SOYNET_DLL __declspec(dllimport)
#endif
#else
#define SOYNET_DLL 
#endif

struct BOX { int x1, y1, x2, y2; };

#ifdef __cplusplus
extern "C" {
#endif

	SOYNET_DLL void getOutputWav2LipFaceDetect(const void* handle, BOX* output, int batch_size, int count, int height, int width, int py1, int py2, int px1, int px2);
	// handle : SoyNet ��ü�� ������(�ڵ�)
	// output : BOX{int x1,y1,x2,y2}�� �迭�� ����ϴ� �������
	// count : batch_size=128�� �߿��� ��ȿ�� ����
	//         ex. �� 207���� ��� batch_size=128�̸� 
	//             batch_idx=0�� ��� count=128���� ��ȿ
	//             batch_idx=1�� ��� count=79���� ��ȿ 
	// height,width : detection�� ���� ��ġ�� ���� �̹��� (height,width) �������� ȯ���ϱ� ���� ��
	SOYNET_DLL void smoothFaceBBox(BOX* bboxes, int count, int T);
	// bboxes : BOX{int x1,y1,x2,y2}�� �迭�� ��/����ϴ� �������
	// count : BOX�� ����
	// T : smoothing ó�� window ũ��

#ifdef __cplusplus
}
#endif
