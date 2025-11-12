#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[105],k,r;
bool cmp(long long int A,long long int B)
{
	return A>B;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	    for(long long int j=1;j<=m;j++)
		{
			cin>>a[++k];
			if(i==1 && j==1)
			    r=a[k];
		}
	sort(a+1,a+1+k,cmp);
	long long int i=1,j=1,l=0;
	while(j<=m)
	{
		l++;
		if(a[l]==r)
		{
		    cout<<j<<" "<<i<<"\n";
			return 0;
		}
		if(j%2==1)
		    i++;
		else
		    i--;
		if(i==n+1)
		{
			i=n;
			j++;
		}
		else
		    if(i==0)
		    {
		    	i=1;
		    	j++;
			}
	}
	return 0;
}