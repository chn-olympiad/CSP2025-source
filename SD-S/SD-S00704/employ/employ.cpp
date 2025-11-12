#include<bits/stdc++.h>
using namespace std;
int n,m,nx[502];
int sum=0,rs,ff,kp=0;
string  zfc[502];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>zfc[i];
	}
	for(int j=1;j<=n;j++)
	{
		cin>>nx[j];
		
	}
	sort(nx,nx+n);
	for(int g=1;g<=n;g++)
	{
		if(nx[g]<=sum) sum++;
	}
	for(int w=1;w<=n;w++)
	{
		
	}
	if(n-m-sum>=0) ff=n*(n-1);
	else ff=(n-m)*(n-m-1);
	cout<<ff%998244353;
}
