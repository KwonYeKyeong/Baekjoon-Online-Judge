#include <iostream>
using namespace std;

int main()
{
	/*
	int bag; // ���� ����
	int sugar; // �Է¹��� ���� ����

	cin >> sugar;
	if (sugar % 5 == 0)
		bag = sugar / 5;
	else if ((sugar % 5 == 1 || sugar % 5 == 4) && sugar != 3 && sugar != 4)
	{
		bag = sugar / 5 - 1;
		bag += (sugar % 5 + 5) / 3;
	}
	else if ((sugar % 5 == 2) && sugar / 5 > 2)
	{
		bag = sugar / 5 - 2;
		bag += (sugar % 5 + 10) / 3;
	}
	else if (sugar % 5 == 3)
		bag = sugar / 5 + 1;
	else if (sugar % 3 == 0)
		bag = sugar / 3;
	else bag = -1;

	cout << bag;
	*/

	int sugar; // ����ؾ� �� ����
	int bag = 0; // ���� ��

	cin >> sugar;

	while (sugar >= 3) {
		if (sugar % 5 == 0) {
			bag += sugar / 5;
			break;
		}
		sugar -= 3;
		bag++;
	}
	if (sugar < 3 && sugar != 0)
		bag = -1;
	cout << bag;

	return 0;
}