#include <iostream>
using namespace std;

int main() {

	int num1; // �Է¹��� ���� 
	int num2; // ���� ������ ����
	int a, b; // a: ���� �ڸ�, b: ���� �ڸ�
	int cycle = 0; // ����Ŭ Ƚ��

	cin >> num1;

	num2 = num1;
	do {
		b = num2 % 10;
		a = (num2 - b) / 10;
		if (num2 < 10)
			num2 = b * 10 + b;
		else
		{
			if (a + b < 10)
				num2 = b * 10 + a + b;
			else
				num2 = b * 10 + (a + b) % 10;
		} 
		cycle++;
	} while (num1 != num2);

	cout << cycle;

	return 0;
}