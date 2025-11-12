#include<bits/stdc++.h>
using namespace std;
long long int a[10005],i,j,n,m,s,t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,greater<long long int>());
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		++t;
		if(a[t]==s)
		{
			cout<<i<<" "<<j;
			return 0;
		}
	}
	return 0;
}
