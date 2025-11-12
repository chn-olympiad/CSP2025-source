#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[15][15],b[100005],i,j,x,k,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=m*n;
	for(i=1;i<=p;i++)
	cin>>b[i];
	x=b[1];
	sort(b+1,b+1+n*m,greater<long long int>());
	i=1;
	k=1;
	for(j=1;j<=m;j++)
	{
	if(j%2==0)
	{
	i=n;
	while(i>=1)
	{
		
		a[i][j]=b[k++];
		if(a[i][j]==x)
		cout<<j<<" "<<i;i--;
	}
    }
	else
	{
	i=1;
	while(i<=n)
	{
		
		a[i][j]=b[k++];
		if(a[i][j]==x)
		cout<<j<<" "<<i;i++;
	}
    }
    }
    return 0;
} 
