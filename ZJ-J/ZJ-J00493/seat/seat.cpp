#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	int k,s=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a;
			if(i==1&&j==1) k=a;
			if(a>k) s++;
		}
	}  
	int b=(s+n-1)/n;
	int c=s%n;
	if(c==0) c=n;
	if(b%2==1) cout<<b<<" "<<c;
	else cout<<b<<" "<<n+1-c;
	return 0;
}
