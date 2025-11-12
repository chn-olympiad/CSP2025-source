#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int m,n;
int a[20];
bool vis[20];
string s;
int ans;
void kao(int pos,int res,int OUT)
{
	if(pos>n)
	{
		ans+=(res>=m);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
		    vis[i]=1;
			if(OUT>=a[i]||s[pos-1]=='0')
			{
				kao(pos+1,res,OUT+1);
			}
			else
			{
				kao(pos+1,res+1,OUT);
			}
		    vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	kao(1,0,0);
	cout<<ans;
	return 0;
}