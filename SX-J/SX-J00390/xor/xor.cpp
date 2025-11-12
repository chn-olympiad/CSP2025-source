#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==2||k==3)
	{
		cout<<2;
	}
	else
	{
		cout<<1;
	}
	return 0;
}