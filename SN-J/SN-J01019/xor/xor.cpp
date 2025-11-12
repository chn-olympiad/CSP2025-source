#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e5+10;

int a[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,cnt0=0;cin>>n>>k;
	bool vis1=true,vis2=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) cnt0++;
		if(a[i]!=1) vis1=false;
		if(a[i]>=2) vis2=false;
	}
	if(vis1==true) {cout<<n/2;return 0;}
	if(vis2==true)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1&&a[i+1]==1) cnt0++;
			cout<<cnt0;
		}
		else cout<<n-cnt0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==k) cnt++;
	cout<<cnt;
	return 0;
}
