#include<bits/stdc++.h>
using namespace std;
long long n,k,x,ans,End,last[1<<21],s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<(1<<20);++i)
	  last[i]=-1;
	for(long long i=1;i<=n;++i)
	{
		cin>>x;
		s^=x;
		if(last[s^k]>=End)
		  ++ans,End=i;
		last[s]=i;
	}
	cout<<ans;
	return 0;
}
