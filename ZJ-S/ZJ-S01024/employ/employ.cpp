#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int n;
int m;
string s;
int cnt;
int c[505];
int tmp[505];
bool check()
{
	int sum = 0;
	for(int i = 1; i<=n; i++)
	{
		if(sum>=c[tmp[i]])
		{
			sum++;
			continue;
		}
		if(s[i-1] == '0')
		{
			sum++;
		}
	}
	return ((n-sum) >= m);
}
bool flg;
int main()
{
	fre();
	cin>>n>>m;
	cin>>s;
	for(int i = 1; i<=n; i++)
	{
		cin>>c[i];
		if(s[i]!='1')
		{
			flg = true;
		}
	}
	if(!flg)
	{
		long long res = 1;
		for(int i = 1; i<=n; i++)
		{
			res*=i;
			res = res%998244353;
		}
		cout<<res;
		return 0;
	}
	for(int i = 1; i<=n; i++)
	{
		tmp[i] = i;
	}
	do
	{
		cnt+=check();
		cnt%=998244353;
	}
	while(next_permutation(tmp+1,tmp+n+1));
	cout<<cnt;
	return 0;
}