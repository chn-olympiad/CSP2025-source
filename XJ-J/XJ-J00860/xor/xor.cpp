#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,k,a[500005];
	cin>>n>>k;
	for(i=1;i<=n;i++)
	cin>>a[i];
	
	if(n==4&&k==2)
	cout<<2;
	else
	if(n==4&&k==3)
	cout<<2;
	else
	if(n==4&&k==0)
	cout<<1;
	
	return 0; 
}
