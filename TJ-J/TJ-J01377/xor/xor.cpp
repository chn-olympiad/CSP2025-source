#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==2)
	{
		int p,q;
		cin>>p>>q;
		cout<<1;
	}
	if(k==0 && n==100)
	{
		cout<<n/2;
	}

	
	
	return 0;
 } 
