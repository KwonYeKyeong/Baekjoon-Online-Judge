#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int test; // �׽�Ʈ ���̽� ����
	int h, w;
	int client; 
	int left, right;

	cin >> test;
	for (int i = 0; i < test; i++) {
		cin.clear();
		cin >> h >> w >> client;
		left = client % h;
		if (left == 0)
		{
			left = h;
			right = client / h;
		}
		else
			right = client / h + 1;
		cout << left << setw(2) << setfill('0') << right << endl;
	}
	return 0;
}

/*
	cout << (N - 1) % H + 1; // 10��° �մ��� 10���� �����޴� ���
*/
