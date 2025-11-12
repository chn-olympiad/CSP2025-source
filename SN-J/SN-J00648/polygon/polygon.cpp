#include<bits/stdc++.h>
using namespace std;
int n, s[5005];
long long a[5005],ans;
bool check(int x, int y)
{
	int maxx=-1;
	long long duobianxing_len=a[y]-a[x-1];
	for(int i=x;i<=y; i++)
	{
		maxx=max(maxx, s[i]);
	}if(duobianxing_len>(maxx*2))return 1;
	return 0;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i =1; i<=n; i++)
	{
		cin >>s[i];
		a[i]=s[i]+a[i-1];
	}
	for(int i=3; i<=n; i++)//数量 
	{
		for(int j=1; j<=n-i+1; j++)//开头 
		{
			int x=j+i-1;//结尾
			if(check(j, x))
			{
				ans++;
				ans%=998244353;
			}
		}
	}cout<<ans;
	return 0;
}
/*
1 2 3 4 5

123
124
125
134
135
145

234
235
245

345
*/
