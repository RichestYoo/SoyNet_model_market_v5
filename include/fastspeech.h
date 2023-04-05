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

#pragma pack(push, 1)

#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif

	SOYNET_DLL int regulate_len_for_fastspeech(const void* handle, int output_idx, int* reg_len);
	// handle : SoyNet ��ü�� ������(�ڵ�)
	// input : output_idx �𵨿��� ������� ������ ����, config ������ [output] refname=... ����
	// return : reg_len�� ����
	// output : reg_len (����� ������ Ȯ���Ǿ� �־�� ��, ex MEL_MAX_LEN=10000

#ifdef __cplusplus
}
#endif
