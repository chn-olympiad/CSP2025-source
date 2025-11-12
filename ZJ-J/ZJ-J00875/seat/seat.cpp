#include<bits/stdc++.h>
#define int long long
int a[105];
using namespace std;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	int k=m*n,l;
	sort(a+1,a+k+1);
	for(int i=1;i<=t;i++)
	{
		if(a[i]==t)
			l=k-i+1;
	}
	int m1;
	if(l%n==0)
		m1=(l/n);
	else
		m1=(l/n+1);
	int j=l-(m1-1)*n;
	int n1;
	if(m1%2==1)
		n1=j;
	else
		n1=n-j+1;
	cout<<m1<<" "<<n1;
	return 0;
}
