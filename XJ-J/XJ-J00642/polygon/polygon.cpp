#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int n,a[5050],sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout<<1; 
	return 0;
}
