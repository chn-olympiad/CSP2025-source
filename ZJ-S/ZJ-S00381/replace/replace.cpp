#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ull B = 1140721;
const ull B2 = 114514191981007219;
const int MAXN = 200005;

vector<int> getpi(string s) // 1-based
{
	int n = s.size();
	s = " " + s;
	vector<int> pi(n + 1);
	pi[1] = 0;
	for(int i = 2;i <= n;i++)
	{
		int len = pi[i - 1];
		while(len > 0 && s[len + 1] != s[i])
			len = pi[len];
		if(s[len + 1] == s[i]) len++;
		pi[i] = len;
	}
	return pi;
}

vector<int> KMP(string text,string pat)
{
	int tgt = text.size();
	string combined = text + "#" + pat;
	vector<int> pi = getpi(combined);
	vector<int> pos;
	for(int i = tgt + 2;i <= combined.size();i++)
		if(pi[i] == tgt)
			pos.push_back(i - tgt - 1);
	return pos;
}

struct Hash //1-based
{
	vector<ull> h,power;
	vector<ull> h2,power2;
	Hash(string s)
	{
		int l = s.size();
		h.resize(l + 5,0ULL);
		power.resize(l + 5,1ULL);
		for(int i = 0;i < l;i++)
		{
			int p = i + 1;
			h[p] = B * h[p - 1] + (s[i] - 'a');
			power[p] = B * power[p - 1];
		}
		
		h2.resize(l + 5,0ULL);
		power2.resize(l + 5,1ULL);
		for(int i = 0;i < l;i++)
		{
			int p = i + 1;
			h2[p] = B2 * h2[p - 1] + (s[i] - 'a');
			power2[p] = B2 * power2[p - 1];
		}
		
	}
	
	ull get1(int l,int r)
	{
		return h[r] - h[l - 1] * power[r - l + 1];
	}
	
	ull get2(int l,int r)
	{
		return h2[r] - h2[l - 1] * power2[r - l + 1];
	}
	
};

struct Rep
{
	string a,b;
}dict[MAXN];

int n,q;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
		cin>>dict[i].a>>dict[i].b;
	
	while(q--)
	{
		string bg,ed;
		cin>>bg>>ed;
		
		ll ans = 0;
		
		for(int i = 1;i <= n;i++)
		{
			vector<int> matched = KMP(bg,dict[i].a);
			for(int p = 0;p < matched.size();p++)
			{	
				Hash x(bg),y(ed),z(dict[i].b);
				int pos = matched[p];
//				cerr<<"pos:"<<pos<<"\n";
				if(x.get1(1,pos - 1) == y.get1(1,pos - 1) && x.get2(1,pos - 1) == y.get2(1,pos - 1) && x.get1(pos + dict[i].a.size(),bg.size()) == y.get1(pos + dict[i].a.size(),bg.size()) && x.get2(pos + dict[i].a.size(),bg.size()) == y.get2(pos + dict[i].a.size(),bg.size()))
					if(z.get1(1,dict[i].b.size()) == y.get1(pos,pos + dict[i].b.size() - 1) && z.get2(1,dict[i].b.size()) == y.get2(pos,pos + dict[i].b.size() - 1))
						ans++;
			}	
		}
		
		printf("%lld\n",ans);
		
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
