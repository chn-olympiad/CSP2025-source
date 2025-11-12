#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x<<3)+(x<<1)+(ch^48);
		ch = getchar();
	}
	return x*f;
}

ll cnt[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,ans = 0;
	n = read();
	m = read();
	string s;
	cin >> s;
	cnt[0] = 1;
	for(int i = 1; i <= n; i ++)
		cnt[i] = (cnt[i-1]*(long long)(i))%998244353;
	for(int i = 1; i <= n; i ++)
	{
		int a;
		cin >> a;
		if(a == 0) ans ++;
	}
	if(n-ans >= m) cout << cnt[n];
	else cout << 0;
	
	return 0;
}
