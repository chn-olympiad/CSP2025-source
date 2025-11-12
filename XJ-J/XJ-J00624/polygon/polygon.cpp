#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,a[10000007],x,m,s=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	s=max(a[1],max(a[2],a[3]));
	if(a[1]+a[2]+a[3]>s*2)
	cout<<1;
	else
	cout<<0;
	
	return 0;
 } 
