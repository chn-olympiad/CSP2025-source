#include<bits/stdc++.h>
using namespace std;
long long int a[105][105],sc[1005],v[105][105];
int main()
{
	long long int n,m,i,j,k,t;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>sc[i];
	if(n==1&&m==1)
	{
	cout<<1<<" "<<1;	
	return 0;	
	}
	t=sc[1];
	sort(sc+1,sc+1+n*m);	
	for(i=0;i<m;i+=2)
	for(j=1;j<=n;j++)	
	v[j][i+1]=i*n+j;
	for(i=1;i<m;i+=2)
	{
	k=1;	
	for(j=n;j>=1;j--)
	{
	v[j][i+1]=i*n+k;	
	k++;	
	}	
	}	
	for(i=n*m;i>=1;i--)
	if(sc[i]==t)
	break;
	for(j=1;j<=n;j++)
	for(k=1;k<=m;k++)
	if(v[j][k]==n*m-i+1)
	{
	cout<<k<<" "<<j;	
	return 0;	
	}
	return 0;
}
