#include<bits/stdc++.h>
using namespace std;
int c[501],n,m,p;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int ans=1;
	scanf("%d%d",&n,&m); 
	scanf("%s",&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	p=n;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			p--;
		}
	}
	if(p<m)
	{
		printf("%d",0);
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	ans%=998244353;
	printf("%d",ans);
	return 0;
 } 
 //I love CCF 
