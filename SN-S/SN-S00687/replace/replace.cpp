#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
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

const int inf = 1e18,N = 2e5 + 10,base = 127;

int n,q;
string s1[N],s2[N],t1[N],t2[N];
ull p[1000010];
vector<ull> hshs1,hshs2;
map<int,vector<pair<int,int>>> mp;

inline bool checkk(string t)
{
	int cnt = 0,sum = 0;
	for(int i = 0;i<t.size();i++)
	{
		cnt += (t[i]=='a'),sum += (t[i]=='b');
	}
	return (cnt+sum==t.size())&&(sum==1);
}

inline int erfen(vector<pair<int,int>> &x,pair<int,int> vul)
{
	int ans = 0;
	for(auto it : x)
	{
		ans += (it.first<=vul.first&&it.second<=vul.second);
	}
	return ans;
}

inline ull get(vector<ull> hs,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	return hs[r] - (l==0?0:hs[l-1]) * p[r-l+1];
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
		bool check = 1;
		for(int i = 1;i<=n;i++)
		{
			cin>>s1[i]>>s2[i];
			check &= checkk(s1[i]);
			check &= checkk(s2[i]);
		}
		for(int i = 1;i<=q;i++)
		{
			cin>>t1[i]>>t2[i];
			check &= checkk(t1[i]);
			check &= checkk(t2[i]);
		}
		if(check)
		{
			for(int i = 1;i<=n;i++)
			{
				int dis = 0,cnt = 0;
				for(int j = 0;j<s1[i].size();j++)
				{
					if(s1[i][j]=='b')
					{
						dis += j;
						cnt *= -1;
					}
					if(s2[i][j]=='b')
					{
						dis -= j;
					}
					if(cnt>=0&&s1[i][j]=='a')
					{
						cnt++;
					}
				}
				cnt = -cnt;
				mp[dis].push_back({cnt,s1[i].size()-cnt-1});
			}
			int dis = 0,cnt = 0;
			for(auto it : mp)
			{
				sort(it.second.begin(),it.second.end());
			}
			for(int i = 1;i<=q;i++)
			{
				int dis = 0,cnt = 0;
				for(int j = 0;j<t1[i].size();j++)
				{
					if(t1[i][j]=='b')
					{
						dis += j;
						cnt *= -1;
					}
					if(t2[i][j]=='b')
					{
						dis -= j;
					}
					if(cnt>=0&&t1[i][j]=='a')
					{
						cnt++;
					}
				}
				cnt = -cnt;
				cout<<erfen(mp[dis],{cnt,t1[i].size()-cnt-1})<<endl;
			}
		}
		else
		{
			p[0] = 1;
			for(int i = 1;i<=1000000;i++)
			{
				p[i] = p[i-1] * base;
			}
			hshs1.resize(n+10),hshs2.resize(n+10);
			for(int i = 1;i<=n;i++)
			{
				int h1 = 0,h2 = 0;
				for(int j = 0;j<s1[i].size();j++)
				{
					h1 = h1 * base + s1[i][j];
					h2 = h2 * base + s2[i][j];
				}
				hshs1[i] = h1,hshs2[i] = h2;
			}
			for(int i = 1;i<=q;i++)
			{
				vector<ull> hsht1,hsht2;
				hsht1.resize(t1[i].size()),hsht2.resize(t2[i].size());
				int h1 = 0,h2 = 0;
				for(int j = 0;j<t1[i].size();j++)
				{
					h1 = h1 * base + t1[i][j];
					h2 = h2 * base + t2[i][j];
					hsht1[j] = h1,hsht2[j] = h2;
				}
				int ans = 0;
				for(int j = 1;j<=n;j++)
				{
					for(int k = s1[j].size()-1;k<t1[i].size();k++)
					{
						if(get(hsht1,k-s1[j].size()+1,k)==hshs1[j])
						{
							int newh = get(hsht1,0,k-s1[j].size()) * p[t1[i].size()-(k-s1[j].size()+1)] + hshs2[j] * p[t1[i].size()-k-1] + get(hsht1,k+1,t1[i].size()-1);
							if(newh==hsht2[t1[i].size()-1])
							{
								ans++;
							}
						}
					}
				}
				cout<<ans<<endl;
			}
		}
	return 0;
}

