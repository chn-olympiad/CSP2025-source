#include<bits/stdc++.h>
using namespace std;
int a[110],aa[110];
int f[15][15];
int ff[15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int a1=a[1];
	sort(a+1,a+1+n*m);
//	for(int i=1;i<=n*m;i++)
//	{
//		for(int j=n*m;j>=1;j--)
//		aa[i]=a[j];
//	}
//	f[1][1]=aa[1];
//	for(int i=1;i<=)
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1)
	{
		for(int i=1;i<=m*n;i++)
		{
			if(a1==a[i])
			{
				cout<<i<<" "<<1;
				return 0;	
			}	
		}	
	}
	if(m==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(a1==a[i]) 
			{
				cout<<1<<" "<<i;
				return 0;
			}
		}	
	} 
	return 0;
}
