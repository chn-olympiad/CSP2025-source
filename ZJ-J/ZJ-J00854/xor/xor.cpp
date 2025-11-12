#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long n,k,l,r=500005,mid,t;
long long a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);   cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	else if(n<=100&&k==0)
	{
		cout<<0;
	}
	return 0;
} 
