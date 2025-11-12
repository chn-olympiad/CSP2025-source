#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10,M = 5e6 + 10;
vector<int> aa[M];
string a[N],b[N];
string c,d;
int n,q;
vector<int> ne[N],pos;
vector<int> ne1[N];
unordered_map<int,bool> mp;
void get_ne(int p)
{
	ne[p].assign(a[p].size() + 10,0);
	for(int i = 2,j = 0; i < a[p].size(); i ++)
	{
		while(j && a[p][j + 1] != a[p][i]) j = ne[p][j];
		if(a[p][j + 1] == a[p][i]) j ++;
		ne[p][i] = j;
	}
	ne1[p].assign(b[p].size() + 10,0);
	for(int i = 2,j = 0; i < b[p].size(); i ++)
	{
		while(j && b[p][j + 1] != b[p][i]) j = ne1[p][j];
		if(b[p][j + 1] == b[p][i]) j ++;
		ne1[p][i] = j;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; i ++)
	{
		cin>>a[i]>>b[i],a[i] = ' ' + a[i],b[i] = ' ' + b[i],get_ne(i);
		aa[a[i].size()].push_back(i);
	}
	while(q --)
	{
		cin>>c>>d;
		c = ' ' + c,d = ' ' + d;
		if(c.size() != d.size())
		{
			cout<<"0\n";
			continue;
		}
		int p1 = 0,p2 = 0;
		for(int i = 1; i < c.size(); i ++)
			if(c[i] != d[i])
			{
				p1 = i;
				break;
			}
		for(int i = c.size() - 1; i >= 1; i --)
			if(c[i] != d[i])
			{
				p2 = i;
				break;
			}
		int len = p2 - p1 + 1;
		int cnt = 0;
		for(int l = len; l <= c.size(); l ++)
			for(auto xx : aa[l])
			{
				pos.clear();
				int j = xx;
				for(int k = 1,p = 0; k < c.size(); k ++)
				{
					while(p && a[j][p + 1] != c[k]) p = ne[j][p];
					if(a[j][p + 1] == c[k]) p ++;
					if(p == a[j].size() - 1)
					{
						pos.push_back(k - a[j].size() + 2);
						p = ne[j][p];
					}
				}
				mp.clear();
				for(int k = 1,p = 0; k < d.size(); k ++)
				{
					while(p && b[j][p + 1] != d[k]) p = ne1[j][p];
					if(b[j][p + 1] == d[k]) p ++;
					if(p == b[j].size() - 1)
					{
						mp[k - b[j].size() + 2] = 1;
						p = ne1[j][p];
					}
				}
				for(auto x : pos)
					if(mp.count(x))
						if(c.substr(0,x) + b[j].substr(1,a[j].size() - 1) + c.substr(x + a[j].size() - 1,c.size() - x - a[j].size() + 1) == d) cnt ++;
			}
		cout<<cnt<<'\n';
	}
	return 0;
}

