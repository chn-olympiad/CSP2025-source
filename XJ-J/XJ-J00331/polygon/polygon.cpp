#include<bits/stdc++.h>
using namespace std;
long long int n,maxn=-1,a[5005],i,j,ans,u; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{cin>>a[i];maxn=max(maxn,a[i]);}
	if(n<=3)
	{
	if(n<3)
	cout<<0;
	else if(n==3&&a[1]+a[2]+a[3]>maxn*2)
	cout<<1;
	else
	cout<<0;
	return 0;
	}
	return 0;
}
