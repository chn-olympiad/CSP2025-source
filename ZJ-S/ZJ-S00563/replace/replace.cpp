#include <bits/stdc++.h>
//#define int long long
using namespace std;
const long long mod = 1e9+7;
const long long m = 47;
const int limit = 5e6;

struct AC
{
	int son[31];
	int fail;
	int length = 0;
	unordered_map <long long,int> mp;
	bool flag = false;
};
long long pmw[5000001];
long long nmi[5000001];
long long s[5000001];
bool st[5000001];
bool ht[5000001];
AC ac[5000001];
int cur = 0;

long long pw(long long x,long long y)
{
	long long c = 1;
	while(y)
	{
		if(y&1)
		{
			c = (c*x)%mod;
		}
		x = (x*x)%mod;
		y >>= 1;
	}
	return c;
}

long long Hsh(string s)
{
	long long ans = 0;
	for(int i = 1;i <= s.length();i++)
	{
		ans *= m;
		ans += s[i-1]-'a';
		ans %= mod;
	}
	return ans;
}

//#undef int
int main()
{
//#define int long long

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    pmw[0] = 1;
    for(int i = 1;i <= limit;i++)
    {
    	pmw[i] = pmw[i-1]*m%mod;
	}
	long long nm = pw(m,mod-2);
	nmi[0] = 1;
	for(int i = 1;i <= limit;i++)
	{
		nmi[i] = nmi[i-1]*nm%mod;
	}
    int n,Q;
    scanf("%d %d",&n,&Q);
    for(int i = 1;i <= n;i++)
    {
    	string s1,s2;
    	cin >> s1 >> s2;
    	int nw = 0;
    	for(int j = 1;j <= s1.length();j++)
    	{
    		if(ac[nw].son[s1[j-1]-'a'] == 0)
    		{
    			ac[nw].son[s1[j-1]-'a'] = ++cur;
    			ac[cur].length = ac[nw].length+1;
			}
			nw = ac[nw].son[s1[j-1]-'a'];
		}
		ac[nw].mp[Hsh(s2)]++;
		ac[nw].flag = true;
	}
	queue <int> q;
	while(!q.empty())
	{
		q.pop();
	}
	for(int i = 0;i < 26;i++)
	{
		if(ac[0].son[i] != 0)
		{
			ac[ac[0].son[i]].fail = 0;
			q.push(ac[0].son[i]);
		}
	}
	while(!q.empty())
	{
		int id = q.front();
		q.pop();
		for(int i = 0;i < 26;i++)
		{
			if(ac[id].son[i] != 0)
			{
				ac[ac[id].son[i]].fail = ac[ac[id].fail].son[i];
				ac[ac[id].son[i]].flag |= ac[ac[ac[id].fail].son[i]].flag;
				q.push(ac[id].son[i]);
			}
			else
			{
				ac[id].son[i] = ac[ac[id].fail].son[i];
			}
		}
	}
//	return 0;
	while(Q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		
//		if(Q == 27476)
//		{
//			cout << t1 << endl << t2 << endl;
//		}
//		printf("666\n");
		
		if(t1.length() != t2.length())
		{
			printf("0\n");
			continue;
		}
		long long hsh1,hsh2;
		hsh1 = hsh2 = 0;
		s[0] = 0;
		st[0] = true;
		ht[t1.length()+1] = true;
		for(int i = 1;i <= t1.length();i++)
		{
			hsh1 *= m;
			hsh1 += t1[i-1]-'a';
			hsh1 %= mod;
			hsh2 *= m;
			hsh2 += t2[i-1]-'a';
			hsh2 %= mod;
			st[i] = hsh1 == hsh2;
			s[i] = hsh2;
		}
		hsh1 = hsh2 = 0;
		for(int i = t1.length();i >= 1;i--)
		{
			hsh1 *= m;
			hsh1 += t1[i-1]-'a';
			hsh1 %= mod;
			hsh2 *= m;
			hsh2 += t2[i-1]-'a';
			hsh2 %= mod;
			ht[i] = hsh1 == hsh2;
		}
		
//		printf("%lld %lld\n",Hsh("de"),(s[4]-s[2]*pmw[2]%mod));
		
		int ans = 0;
		int nw = 0;
		for(int i = 1;i <= t1.length();i++)
		{
			nw = ac[nw].son[t1[i-1]-'a'];
			if(ht[i+1] == true)
			{
				for(int j = nw;ac[j].flag;j = ac[j].fail)
				{
					if(st[i-ac[j].length] == true)
					{
						long long tmp = s[i]-s[i-ac[j].length]*pmw[ac[j].length]%mod;
						ans += ac[j].mp[(tmp%mod+mod)%mod];
					}
					else
					{
						break;
					}
				}
			}
			if(st[i-ac[nw].length] == false)
			{
				break;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
