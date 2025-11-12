#include<bits/stdc++.h>
using namespace std;
const int N=2e2;
int n,m,f[N*N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>f[i];
	}
	int tot=f[1];
	sort(f+1,f+1+n*m);
	int len=lower_bound(f+1,f+1+n*m,tot)-f;
	len=n*m-len+1;
	tot=ceil(1.0*len/n);
	if(tot%2==0)
	{
		if(len%n==0)
		{
			cout<<tot<<" "<<1;
		}
		else cout<<tot<<" "<<n-len%n+1;
	}
	else
	{
		if(len%n==0)
		{
			cout<<tot<<" "<<n;
		}
		else cout<<tot<<" "<<len%n;
	}
	return 0;
} 
