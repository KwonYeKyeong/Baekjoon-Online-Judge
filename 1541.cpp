#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, temp = "";
	int result = 0;
	bool minus = false;

	cin >> s;

	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '+' || s[i] == '-' || i == s.length()) {
			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = "";

			if (s[i] == '-')
				minus = true;
		}
		else
			temp += s[i];
	}

	cout << result;

	return 0;
}