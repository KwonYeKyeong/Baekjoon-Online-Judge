#include <iostream>
using namespace std;

void quick_sort(int data[], int s, int e) { // s = start, e = end
	if (s >= e) {
		// ������ ������ 1���� ��
		return;
	}

	int pivot = s;
	int i = s + 1;
	int j = e;
	int temp;

	while (i <= j) {
		while (i <= e && data[pivot] >= data[i]) {
			// �ǹ����� ū �� ã��
			i++;
		} 
		while (j > s && data[pivot] <= data[j]) {
			// �ǹ����� ���� �� ã��
			j--; 
		}
		
		if (i > j) {
			// ������
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			// i��°��  j��°�� ����
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	// ���� ���
	quick_sort(data, s, j - 1);
	quick_sort(data, j + 1, e);
}

int main() {
	int data[10000];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> data[i];

	quick_sort(data, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << data[i] << '\n';

	return 0;
}