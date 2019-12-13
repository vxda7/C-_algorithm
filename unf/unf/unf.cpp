﻿// unf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#define NM 1000005

int n, m, cmd, a, b;
int set[NM];

void init() {
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}
}

void sum(int x, int y){
	for (int i = 0; i < n; i++) {
		if (set[i] == set[y]) {
			set[i] = set[x];
		}
	}
}

void check(int x, int y) {
	if (set[x] == set[y]) {
		printf("1");
	}
	else {
		printf("0");
	}
}

void input() {
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &cmd, &a, &b);
		if (cmd == 0) {
			sum(a, b);
		}
		else if(cmd == 1) {
			check(a, b);
		}
	}
}

int main()
{
	int T; scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		printf("#%d ", t + 1);
		input();
		printf("\n");
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
