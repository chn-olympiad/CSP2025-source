#include<bits/stdc++.h>//seat
using namespace std;
long long int n,m,f[15][15],a[105],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int i,j,k;
	cin>>n>>m;
	k=m*n;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n*m);
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
		  for(j=1;j<=m;j++)
		  {
		  	f[j][i]=b[k--];
		  	if(f[j][i]==a[1])
		  	{
		  		cout<<i<<' '<<j<<endl;
		  		return 0;
			}
		  }
		else
		  if(i%2==0)
		    for(j=m;j>=1;j--)
		    {
		    	f[j][i]=b[k--];
		  	    if(f[j][i]==a[1])
		  		{
		  		  cout<<i<<' '<<j<<endl;
		  		  return 0;
				}
		    }
	}
}
