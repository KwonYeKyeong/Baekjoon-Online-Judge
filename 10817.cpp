#include <iostream>
#include <vector>
using namespace std;

int main() {
	/*
	int a, b, c;
	cin >> a >> b >> c;

	if (a >= b) {
		if (b >= c)
			cout << b;
		else if (a >= c)
			cout << c;
	} // a�� ���� ū ���϶�
	else if (b >= c)
	{
		if (c >= a)
			cout << c;
		else if(b >= a)
			cout << a;
	} // b�� ���� ū ���϶�
	else if (c >= a)
	{
		if (a >= b)
			cout << a;
		else if (c >= b)
			cout << b;
	} // c�� ���� ū ���϶�
	*/

	int N, X;

	cin >> N >> X;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	for (auto a : vec) {
		if (a < X)
			cout << a << ' ';
	}

	return 0;
}