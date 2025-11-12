#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	int a[300];
	cin>>n>>m;
	int b=m+1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		sort(a,a+i+1);
	}
	cout<<a[b];
    return 0;	
} 
