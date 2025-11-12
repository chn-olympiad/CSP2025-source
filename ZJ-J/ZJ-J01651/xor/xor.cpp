#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],s[500005],la,ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int r=1;r<=n;r++)
	{
		for(int l=la+1;l<=r;l++)
		{
			if((s[r]^s[l-1]) == k)
			{
				la=r;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return  0;
}
