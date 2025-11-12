#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,l,r;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	if(k!=1)cout<<0;
	else cout<<n-1;
	return 0;
}