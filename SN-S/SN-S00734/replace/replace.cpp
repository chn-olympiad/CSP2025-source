#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
	int h1,h2;
	bool operator<(node another)const
	{
		if (h1 == another.h1) return h2 < another.h2;
		return h1 < another.h1;
	}
};

const int jz1 = 59,mod1 = 1000000007,jz2 = 31,mod2 = 998244353;
int n,q,p1[5000005],p2[5000005];
node T1[5000005],T2[5000005];
set<pair<node,node> > st;
string s1,s2,t1,t2;

node hs(string s)
{
	node ret;
	ret.h1 = ret.h2 = 0;
	for (int i = 0;i < (int)s.size();i++)
	{
		ret.h1 = (ret.h1+(s[i]-'a')*p1[i])%mod1;
		ret.h2 = (ret.h2+(s[i]-'a')*p2[i])%mod2;
	}
	return ret;
}

void HS1(string s)
{
	node ret;
	ret.h1 = ret.h2 = 0;
	for (int i = 0;i < (int)s.size();i++)
	{
		ret.h1 = (ret.h1+(s[i]-'a')*p1[i])%mod1;
		ret.h2 = (ret.h2+(s[i]-'a')*p2[i])%mod2;
		T1[i] = ret;
	}
}

void HS2(string s)
{
	node ret;
	ret.h1 = ret.h2 = 0;
	for (int i = 0;i < (int)s.size();i++)
	{
		ret.h1 = (ret.h1+(s[i]-'a')*p1[i])%mod1;
		ret.h2 = (ret.h2+(s[i]-'a')*p2[i])%mod2;
		T2[i] = ret;
	}
}

int fast_power(int x,int y,int md)
{
	int ret = 1;
	while (y)
	{
		if (y&1) ret = ret*x%md;
		x = x*x%md;
		y >>= 1;
	}
	return ret;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	p1[0] = p2[0] = 1;
	for (int i = 1;i <= 5000000;i++) p1[i] = p1[i-1]*jz1%mod1,p2[i] = p2[i-1]*jz2%mod2;
	cin >> n >> q;
	while (n--)
	{
		cin >> s1 >> s2;
		st.insert({hs(s1),hs(s2)});
	}
	while (q--)
	{
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << '\n';
			continue;
		}
		int l = -1,r = -1,len = t1.size(); 
		for (int i = 0;i < len;i++)
		{
			if (t1[i] != t2[i])
			{
				if (l == -1) l = i;
				else r = i;
			}
		}
		if (l == -1)
		{
			cout << 0 << '\n';
			continue;
		}
		HS1(t1);HS2(t2);
		int ans = 0;
		for (int i = 0;i <= l;i++)
		{
			for (int j = r;j < (int)(t1.size());j++)
			{
				node n1,n2;
				n1.h1 = (T1[j].h1-(i == 0?0:T1[i-1].h1)+mod1)%mod1*fast_power(p1[i],mod1-2,mod1)%mod1;
				n1.h2 = (T1[j].h2-(i == 0?0:T1[i-1].h2)+mod2)%mod2*fast_power(p2[i],mod2-2,mod2)%mod2;
				n2.h1 = (T2[j].h1-(i == 0?0:T2[i-1].h1)+mod1)%mod1*fast_power(p1[i],mod1-2,mod1)%mod1;
				n2.h2 = (T2[j].h2-(i == 0?0:T2[i-1].h2)+mod2)%mod2*fast_power(p2[i],mod2-2,mod2)%mod2;
				if (st.count({n1,n2})) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
