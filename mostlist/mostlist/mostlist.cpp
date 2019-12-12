// mostlist.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);
		int A[200000];
	
		for (int n = 0; n < N; n++) {
			scanf("%d", &A[n]);
		}

		int temp = 0;
		int max = 0;
		for (int n = 0; n < N; n++) {
			temp += A[n];
			A[n] = temp;
			if (max < temp) {
				max = temp;
			}
		}
		int min = 1000;
		int result = A[0];
		for (int n = 0; n < N; n++) {
			if (result < A[n] - min) {
				result = A[n] - min;
			}
			if (A[n] < 0) {
				if (min > A[n]) {
					min = A[n];
				}
			}
		}

		printf("#%d %d\n", t+1, result);
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
