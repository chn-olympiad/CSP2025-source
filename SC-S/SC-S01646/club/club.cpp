#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
void dfs1(int &n,int l,int aa,int bb,int &cnt,int cntt,vector<int> &a,vector<int> &b)
{
	if (l > n)
	{
		cnt = max(cnt,cntt);
		return ;
	}
	if (aa < n/2)
	{
		dfs1(n,l+1,aa+1,bb,cnt,cntt+a[l],a,b);
	}
	if (bb < n/2)
	{
		dfs1(n,l+1,aa,bb+1,cnt,cntt+b[l],a,b);
	}
	return ;
}
void dfs2(int &n,int l,int aa,int bb,int cc,int &cnt,int cntt,vector<int> &a,vector<int> &b,vector<int> &c)
{
	if (l > n)
	{
		cnt = max(cnt,cntt);
		return ;
	}
	if (aa < n/2)
	{
		dfs2(n,l+1,aa+1,bb,cc,cnt,cntt+a[l],a,b,c);
	}
	if (bb < n/2)
	{
		dfs2(n,l+1,aa,bb+1,cc,cnt,cntt+b[l],a,b,c);
	}
	if (cc < n/2)
	{
		dfs2(n,l+1,aa,bb,cc+1,cnt,cntt+c[l],a,b,c);
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		int n,cnt = 0;
		bool bf = true,cf = true;
		cin >> n;
		vector<int> a(n+1);
		vector<int> b(n+1);
		vector<int> c(n+1);
		for (int j = 1;j <= n;j++)
		{
			cin >> a[j] >> b[j] >> c[j];
			if (b[j] != 0)
			{
				bf = false;
			}
			if (c[j] != 0)
			{
				cf = false;
			}
		}
		if (bf && cf)
		{
			sort(a.begin()+1,a.end()+1,cmp);
			for (int j = 1;j <= n/2;j++)
			{
				cnt += a[j];
			}
		}
		else if (cf)
		{
			dfs1(n,1,0,0,cnt,0,a,b);
		}
		else
		{
			dfs2(n,1,0,0,0,cnt,0,a,b,c);
		}
		cout << cnt;
	}
	return 0;
}