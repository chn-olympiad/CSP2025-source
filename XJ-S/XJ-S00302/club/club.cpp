#include<bits/stdc++.h>
using namespace std;
long long int t,n,i,a1,a2,a3,j,maxn=0,a[100],b[100],c[100],x=0,y=0,z=0,s=0,zt=0,qs,k;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		maxn=0;
		x=0;
		y=0;
		z=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a1>>a2>>a3;
			a[++x]=a1;
			b[++y]=a2;
			c[++z]=a3;
		}
		sort(a+1,a+1+n,greater<long long int>());
		sort(b+1,b+1+n,greater<long long int>());
		sort(c+1,c+1+n,greater<long long int>());
		maxn+=a[1]+b[1]+c[1];
		cout<<maxn<<endl;
		
	}

	return 0;
} 
