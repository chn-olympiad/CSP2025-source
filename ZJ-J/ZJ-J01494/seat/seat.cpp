#include<bits/stdc++.h>
using namespace std;
int n,m,j=1,a[1001],ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>a[i];
		if(i==1) ans=a[i];
	}
		
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		int k=i;
		if(k>n)
		{
			j=(k-1)/n+1;
			if(((k-1)/n)%2) k=n-k%n+1;
			else
			{
				if(k%n==0) k=n;
				else k=k%n;
			}
		}
		if(ans==a[n*m-i+1]) cout<<j<<" "<<k;
	}
	return 0;
}