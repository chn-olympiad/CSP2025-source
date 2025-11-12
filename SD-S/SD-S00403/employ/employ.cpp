#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string r;
	long long a,b,c[1000]={0},d,e,f=0,g;
	cin>>a>>b;
	cin>>r;
	for(d=0;d<a;d++) cin>>e;
	for(d=b;d<=a;d++)
	{
		c[d]=1;
		for(e=d-1;e>=0;e--) c[d]=(c[d]*(a-e))%998244353;
	}
	for(d=b;d<=a;d++) f=(f+c[d])%998244353;
	cout<<f;
	return 0;
}
