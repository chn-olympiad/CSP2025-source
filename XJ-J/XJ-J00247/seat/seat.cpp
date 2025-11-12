#include<bits/stdc++.h>
using namespace std;
long long i,k,n,m,l=1,j,a,b[550],c[20][20],d[550];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>b[i];
	a=b[1];
	sort(b+1,b+1+n*m);
	for(i=n*m;i>=1;i--)
	d[++j]=b[i];
	j=0;
	while(l<=n)
	{	
		if(l%2==0)
			for(k=m;k>=1;k--)
				c[l][k]=d[++j];
		if(l%2==1)
			for(k=1;k<=m;k++)
				c[l][k]=d[++j];
		l++;
	}
	l=n;
	for(k=1;k<=m;k++)
	for(i=1;i<=n;i++)
	if(c[i][k]==a)
	cout<<i<<" "<<k;
	return 0;
} 
