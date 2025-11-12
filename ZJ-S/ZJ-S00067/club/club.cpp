#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,flag=9,ans,a[100005],b[100005],c[100005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++)
			if(b[i]!=0||c[i]!=0)
				flag=0;
		if(flag!=0)
		{
			sort(a+1,a+1+n);
			for(int i=n;i>=1;i--)
				ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}
//rp++;