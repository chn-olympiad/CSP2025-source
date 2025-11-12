#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int cnt, a[1000006];

int main()
{
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> s1;
	for (int i = 0;i < s1.size();i++)
	{
		if ((s1[i] >= '1' and s1[i] <= '9') or s1[i] == '0')
		{
			cnt++;
			a[cnt] = int(s1[i] - 48);
		}
	}
	sort(a + 1, a + cnt + 1);
	for (int i = cnt;i >= 1;i--) cout << a[i];
	return 0;
} 
