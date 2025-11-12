#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],q[500005],l[500005],f[500005];
bool b[500005];
unordered_map<int,int> mp1;
unordered_map<int,bool> mp2;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	mp2[k]=true;
	for(int i=1;i<=n;++i)
	{
	    cin>>a[i];
	    q[i]=q[i-1]^a[i];
	    if(mp2[q[i]]) 
		{
			l[i]=mp1[q[i]];
			b[i]=true;
		}
	    mp1[q[i]^k]=i;
	    mp2[q[i]^k]=true;
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		if(b[i]) f[i]=max(f[i],f[l[i]]+1);
	}
	cout<<f[n];
	return 0;
}
