#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while('0'>ch||ch>'9')
	{
		if(ch=='-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int inf = 1e18,N = 1e5 + 10,mod = 998244353;

int n,m,c[N],ans;
string s;
bool falg[N];
vector<int> op;

inline void dfs(int it)
{
	if(it==n+1)
	{
		int cnt = 0,sum = 0;
		for(int i = 0;i<n;i++)
		{
			if(s[i]=='0'||cnt>=c[op[i]])
			{
				cnt++;
			}
			else
			{
				sum++;
			}
		}
		ans += sum >= m;
		return ;
	}
	for(int i = 1;i<=n;i++)
	{
		if(!falg[i])
		{
			op.push_back(i);
			falg[i] = 1;
			dfs(it+1);
			falg[i] = 0;
			op.pop_back();
		}
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	bool check = 1;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			check = 0;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(check)
	{
		int ans = 1;
		for(int i = 1;i<=n;i++)
		{
			ans = ans * i % mod;
		}
		cout<<ans<<endl;
	}
	else
	{
		dfs(1);
		cout<<ans%mod<<endl;
	}
	return 0;
}

