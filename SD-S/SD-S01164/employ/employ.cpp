#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
typedef long long ll;
const ll MO = 998244353;
const int N = 550;
int ne[N];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> ne[i];
	}
	sort(ne+1,ne+n+1);
	s = " "+s;
	bool f = 1;
	for(int i = 1;i <= n;i++)
	{
		if(s[i] != '1') f = 0;
	}
	if(f)
	{
		bool f = 1;
		for(int i = 1;i <= n;i++)
		{
			if(ne[i] < i)
			{
				f = 0;
			}
		}
		ll fac = 1;
		for(int i = 2;i <= n;i++)
		{
			fac *= i;
			fac %= MO;
		}
		if(f)
		{
			cout << fac << endl;return 0;
		}
	}
	cout << 0 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
