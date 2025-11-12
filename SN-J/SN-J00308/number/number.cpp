//康铱宸-SN-J00308-西安滨河学校 
#include <bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
string s;
int a[1000006];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int k=1;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[k] = s[i] - '0';
			k++;
			
		}
	}
	sort(a+1,a+k+1);
	for (int i = k;i >= 2;i--)
	{
		cout << a[i];
	}
	return 0;
}
