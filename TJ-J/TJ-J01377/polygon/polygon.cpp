#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int maxn=max(a,b);
		maxn=max(maxn,c);
		int sum=a+b+c;
		if(sum>2*maxn) cout<<1;
		else cout<<0;
	}
	
	
	
	return 0;
 } 
