#include <iostream>
using namespace std;

// ü������ 2����(B, W)�� ������ Ǫ�� ���� �ٽɹ��
#define B 0
#define W 1

int board[11][11], l[20], r[20];
int s, black, white;

void back_tracking(int x, int y, int cnt, int color) {
	if (y >= s) {
		x++;
		if (y % 2) y = 0;
		else y = 1;
	}

	if (x >= s) {
		if (color == W)
			white = white < cnt ? cnt : white;
		else
			black = black < cnt ? cnt : black;
		return;
	}

	/*
	���� ��ġ�� ����� ���� �� �ִ� ���� �Ǵ��ϱ� ���� 3���� ����
	1. chess�ǿ� ����� ���� �� �ִ°�.
	2. ���� �밢�� ���⿡ ����� ������ �ִ°�.
	3. ������ �밢�� ���⿡ ����� ������ �ִ°�.
	*/
	if (board[x][y] && !l[y - x + s - 1] && !r[x + y]) {
		l[y - x + s - 1] = r[x + y] = 1;
		back_tracking(x, y + 2, cnt + 1, color);
		l[y - x + s - 1] = r[x + y] = 0;
	}
	back_tracking(x, y + 2, cnt, color);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++)
			cin >> board[i][j];
	}

	back_tracking(0, 0, 0, B);
	back_tracking(0, 1, 0, W);

	cout << black + white;

	return 0;
}