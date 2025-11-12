//SN-J01104 陈安旭 西安滨河学校
 #include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
long long a[MAXN] , cnt;
string s;

bool cmp(long long c , long long d)
{
	return c > d;
}

signed main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	for (long long i = 0;i < s.size();i++)
	{
		if (s[i] >= 97 && s[i] <= 123)
		{
			continue;
		}
		cnt++;
		a[cnt] = s[i] - '0';
	}
	sort(a + 1 , a + cnt + 1 , cmp);
	for (long long i = 1;i <= cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}
