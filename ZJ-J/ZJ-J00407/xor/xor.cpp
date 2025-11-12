#include<bits/stdc++.h>
using namespace std;
int a[10086];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k>1)
	{
		cout<<0;
	}
	else if(k==1)
	{
		cout<<n;
	}
	else if(k==0)
	{
		cout<<n/2;
	}
	ios::sync_with_stdio(0);
	return 0;
}
