#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e6+5;
ll a[N],b[N],n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}ll l=1,r=1;
	while(l<=n&&r<=n)
	{
		bool f=1;
		for(ll i=l-1;i<r;i++)
			if((b[r]^b[i])==k)
			{
				ans++;l=++r;
				f=0;break;
			} 
		if(f) r++;
	}cout<<ans;
	return 0;
}