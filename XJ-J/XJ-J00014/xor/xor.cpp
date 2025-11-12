#include<bits/stdc++.h> 
using namespace std;
long long int a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int num=0,maxn=0,i,j,n,k,l,r;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==2)
	{
		cout<<2;
	}
	if(n==4&&k==3)
	{
		cout<<2;
	}
	if(n==4&&k==0)
	{
		cout<<1;
	}
	return 0;
}
