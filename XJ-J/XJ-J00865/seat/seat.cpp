#include<bits/stdc++.h> 
using namespace std;
long long int i,k,maxn,a[1000005],n,m,r,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m*n;i++)
	cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,greater<long long int>());
	for(i=1;i<=m;i++)
	{
		if(i%2==1)
		for(k=1;k<=n;k++)
		{
			s++;
			if(a[s]==r)
			{
				cout<<i<<" "<<k;
				return 0;
			}
		}
		if(i%2==0)
		for(k=n;k>=1;k--)
		{
			s++;
			if(a[s]==r)
			{
				cout<<i<<" "<<k;
				return 0;
			}
		}	
	}
	return 0;
}
