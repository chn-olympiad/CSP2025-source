#include<bits/stdc++.h>
using namespace std;
int n,m,a[600],cnt,num = 1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 0)
		{
			cnt++;
		}
	}
	for(int i = cnt;i >= cnt - m;i--)
	{
		mun = mun * i % 998244353;
	}
	cout << num;
	return 0;
}

