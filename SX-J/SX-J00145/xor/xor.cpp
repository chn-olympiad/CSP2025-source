#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<n<<k;
	for(int i=0;i<n;i++)
	{
		cin>>m;
	}
	if(k==1)
	{
		cout<<n;
		return 0;
	}
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	cout<<0;
	return 0;
}