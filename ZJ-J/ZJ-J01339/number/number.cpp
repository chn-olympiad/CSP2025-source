#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	sort(s.begin(),s.end(),greater <char>());
	for (int i = 0;i < s.size();i++) if (s[i] >= 48 && s[i] <= 57)	cout << s[i];
	return 0;
} 
