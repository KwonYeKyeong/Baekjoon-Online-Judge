#include <iostream>
using namespace std;

int main()
{
	int num;

	cin >> num;

	for (int line = 0; line < num; line++)
	{
		for (int space = 0; space < line; space++)
			cout << ' ';
		for (int star = 0; star < 2 * (num - line) - 1; star++)
			cout << '*';
		cout << endl;
	}
	for (int line = 0; line < num - 1; line++)
	{
		for (int space = 0; space < num - line - 2; space++)
			cout << ' ';
		for (int star = 0; star < 2 * line + 3; star++)
			cout << '*';
		cout << endl;
	}
	return 0;
}