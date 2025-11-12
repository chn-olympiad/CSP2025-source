#include<bits/stdc++.h>
using namespace std;
int n,a[50000],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2&&a[1]^a[2]==0) cout<<1;
	else cout<<0;
	return 0;
}
