#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
string s;
int num[N];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int i = s.size(), cnt = 0;
	while(i --)
	{
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
			num[++ cnt] = s[i] - 48;
	}
	if(cnt >= 2)
	{
		sort(num + 1, num + cnt + 1);
		for(int i = cnt; i >= 1; i --)printf("%d", num[i]);
	}
	else printf("%d", num[1]);

	return 0;
}
