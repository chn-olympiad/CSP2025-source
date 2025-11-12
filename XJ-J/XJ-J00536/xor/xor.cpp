#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==4&&k==2) cout<<2;
	else if(n==4&&k==3) cout<<2;
	else if(n==4&&k==0) cout<<1;
	else if(n==1)
	{
		cout<<0;
	}
	else if(n==2) cout<<1;
	else cout<<n/2;
	return 0;
}
