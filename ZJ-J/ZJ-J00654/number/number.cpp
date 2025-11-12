#include<bits/stdc++.h>
using namespace std;
string s;
int ans[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int c = s.size();
	for (int i = 0;i < c;i ++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			ans[s[i] - '0'] ++;
		}
	}
//	for (int i = 0;i <= 9;i ++)
//	{
//		cout << i << " " << ans[i] << endl;
//	}
	for (int i = 9;i >= 0;i --)
	{
		int k = ans[i];
		for (int j = 1;j <= k;j ++)
		{
			cout << i;
		}
	}
}
