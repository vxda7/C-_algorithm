﻿// anagram.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool check(int wantcnt[26], int cnt[26]) {
	int how = 0;
	for (int i = 0; i < 26; i++) {
		if (wantcnt[i] == cnt[i]) {
			how++;
		}
	}
	if (how == 26) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		char word[100001];
		char large[100001];
		scanf("%s", word);
		scanf("%s", large);
		// a = 97
		int howlong = 0;
		while (word[howlong] != '\0') {
			howlong++;
		}
		int howlargelong = 0;
		while (large[howlargelong] != '\0') {
			howlargelong++;
		}
		

		// 원하는 글자들의 갯수 카운트
		int wantcnt[26] = { 0, };
		for (int i = 0; i < howlong; i++) {
			wantcnt[word[i] - 97]++;
		}

		// 오른쪽 처음 갯수 카운트
		int cnt[26] = { 0, };
		for (int i = 0; i < howlong; i++) {
			cnt[large[i] - 97]++;
		}
		// 비교
		bool right = false;
		int result = 0;
		if (check(wantcnt, cnt)) {
			result++;
			right = true;
		}

		for (int i = 0; i < howlargelong - howlong; i++) {
			cnt[large[i] - 97]--;
			cnt[large[i + howlong] - 97]++;
			if (large[i] == large[i + howlong] && right) {
				result++;
			}
			else if (large[i] == large[i + howlong]) {
			}
			else {
				if (check(wantcnt, cnt)) {
					result++;
					right = true;
				}
				else {
					right = false;
				}
			}
		}
		printf("#%d %d\n", test + 1, result);
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
