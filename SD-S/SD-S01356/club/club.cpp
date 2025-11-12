#include<bits/stdc++.h>
using namespace std;
long long a[10001][10001],b[10],m[10001];
main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long tot=0,j,k,l,m,n,maxn=-1,minn=-1;
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		m=n/2;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=3;k++)
			{
				cin>>a[j][k];
				if(a[j][k]>maxn)
					maxn=a[j][k];
			}
			tot+=maxn;
			maxn=-1;
		}
		cout<<tot;
		cout<<endl;
		tot=0;		
	}
	
 }

