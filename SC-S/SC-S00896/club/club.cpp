#include<bits/stdc++.h>
using namespace std;
int t,n,s[5],a[100010][5];
long long h;
void fs(int d,long long hh)
{
	if(d==n+1)
	{
		if(hh>h)
		{
			h=hh;
		}
		return;
	}
	for(int i=0;i<=3;i++)
	{
		if((s[i]<(n/2))||(i==0))
		{
			s[i]++;
			fs(d+1,hh+a[d][i]);
			s[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		h=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
		}
		fs(1,0);
		printf("%lld\n",h);
	}
	return 0;
}