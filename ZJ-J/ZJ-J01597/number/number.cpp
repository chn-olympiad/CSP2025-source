#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s, n;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char c : s)
		if (c >= '0' && c <= '9')
			n.push_back(c);
	s = n;
	n = "";
	sort(s.begin(), s.end(), greater<char>());
	if (s[0] != '0')
		return cout << s << endl, 0;
	cout << 0 << endl;
	return 0;
}
