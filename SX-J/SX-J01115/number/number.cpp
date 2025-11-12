
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10e6+1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, str_[10], s1[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
//	{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	cin >> s;
	int i;
	char str;

	for (i = 0; i < s.size(); i++) {
		str = s[i];

		if (str == '0')
			str_[0] += s1[0];
		else if (str == '1')
			str_[1] += s1[1];
		else if (str == '2')
			str_[2] += s1[2];
		else if (str == '3')
			str_[3] += s1[3];
		else if (str == '4')
			str_[4] += s1[4];
		else if (str == '5')
			str_[5] += s1[5];
		else if (str == '6')
			str_[6] += s1[6];
		else if (str == '7')
			str_[7] += s1[7];
		else if (str == '8')
			str_[8] += s1[8];
		else if (str == '9')
			str_[9] += s1[9];

	}


	s = "";

	for (i = 9; i >= 0; i--) {

		s = s + str_[i];

	}
	cout << s << endl;
	return 0;
}






