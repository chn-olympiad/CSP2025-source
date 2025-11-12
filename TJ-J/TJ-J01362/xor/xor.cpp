#include<bits/stdc++.h>
using namespace std;
long long a[50005];
long long n,k;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0||k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
}
