// heap2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

int heaps[100005];
int now = 0;

void swap(int a, int b) {
	int temp = heaps[a];
	heaps[a] = heaps[b];
	heaps[b] = temp;
}

void sorting(int p) {
	if (p == 1) return;
	// 부모노드보다 자식이 크다면 바꾸기
	if (heaps[p / 2] < heaps[p]) {
		swap(p / 2, p);
		sorting(p / 2);
	}
}

void downsorting(int p) {
	if (p * 2 + 1 <= now) { // 자식이 둘다 있다면
		// 자식이 둘중 하나라도 부모보다 크다면
		if (heaps[p * 2 + 1] > heaps[p] || heaps[p * 2] > heaps[p]) {
			if (heaps[p * 2 + 1] > heaps[p * 2]) { // 오른자식이 더 크다면
				swap(p, p * 2 + 1);
				downsorting(p * 2 + 1);
			}
			else { 
				swap(p, p * 2);
				downsorting(p * 2);
			}
		}
		// 둘다 작다면
		else return;
	}
	else if (p * 2 <= now) { // 왼자식만 있다면
		if (heaps[p * 2] > heaps[p]) {
			swap(p * 2, p);
			downsorting(p * 2);
		}
		else return;
	}
	else {
		return;
	}
}

void add(int v) {
	now++;
	heaps[now] = v;
	sorting(now);
}

void pop() {
	if (now >= 1) { printf("%d ", heaps[1]); }
	else { printf("-1 "); return; }
	swap(1, now);
	heaps[now] = NULL;
	now--;
	downsorting(1);
}

int cmdnum, cmd, value;
void input() {
	now = 0;
	scanf("%d", &cmdnum);
	for (int i = 0; i < cmdnum; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) { scanf("%d", &value); add(value); }
		else { pop(); }
	}
}

int main()
{
	int T; scanf("%d",&T);
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
