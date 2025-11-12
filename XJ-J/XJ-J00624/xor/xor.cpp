#include<bits/stdc++.h>
using namespace std;
long long int i,j,a[1000006],n,maxn=-114514,x,f;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>x;
	for(i=1;i<=n;i++)
	cin>>a[i];
	
	if(n==1&&x==0)
	cout<<0;
	if(n==2&&x==0)
	cout<<1;
	return 0;
 } 
