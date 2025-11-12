#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m,c[501],a[501],w,di,ma=0,i;
bool l[501];
string s;
int tes()
{
	w=0;
	di=0;
	int i;
	for(i=1;i<=n;i++)
	{
		if(di>=c[a[i]])
		{
			di++;
		}
		else
		{
			if(s[i-1]=='0')
			{
				di++;
			}
			else
			{
				w++;
			}
		}
	}
	return w;
}
void dfs(int i)
{
	if(i>n)
	{
		if(tes()>=m)
		{
			ma++;
		}
		return;
	}
	int j;
	for(j=1;j<=n;j++)
	{
		if(l[j]==0)
		{
			a[i]=j;
			l[j]=1;
			dfs(i+1);
			l[j]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<ma<<"\n";
	return 0;
}
/*
3 2
101
1 1 2

*/
