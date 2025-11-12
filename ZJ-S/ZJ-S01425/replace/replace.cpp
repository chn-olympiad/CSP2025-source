#include<bits/stdc++.h>
using namespace std;

int n,q;

struct node
{
	string x,y;
}a[200001];

map<string,string> mp;

int f(string x,string e,int cnt)
{
	if(x == e)
	{
		return cnt;
	}
	else
	{
		return f(mp[x],e,cnt + 1);
	}
	
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	
	for(int i = 1; i <= n;i ++)
	{
		cin >> a[i].x >> a[i].y;
		mp[a[i].x] = a[i].y;
	}
	
	while(q --)
	{
		string s,e;
		cin >> s >> e;
		
		string x;
		
		for(int i = 1; i <= n;i ++)
		{
			if(s[i - 1] != e[i - 1])
			{
				x[x.size()]	= s[i - 1];
			}
		}
		
		int ans = 0;
		
		for(int i = 1; i <= n;i ++)
		{
			if(f(a[i].x,e,0) != 0)
			{
				ans ++;
			}
		}
		
		cout << ans;
		
	}
	
	return 0;
}
