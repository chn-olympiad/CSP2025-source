#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+10;

int a[N],b[N],c[N],mx;

inline void dfs(int cnt1,int cnt2,int cnt3,int sum,int n)
{
	if(cnt1+cnt2+cnt3==n) {mx=max(sum,mx);return ;}
	if(cnt1+1<=n/2) dfs(cnt1+1,cnt2,cnt3,sum+a[cnt1+cnt2+cnt3+1],n);
	if(cnt2+1<=n/2) dfs(cnt1,cnt2+1,cnt3,sum+b[cnt1+cnt2+cnt3+1],n);
	if(cnt3+1<=n/2) dfs(cnt1,cnt2,cnt3+1,sum+c[cnt1+cnt2+cnt3+1],n);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;while(t--)
	{
		int n;cin>>n;bool vis1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) vis1=false;
		}
		if(vis1==true)
		{
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=n;i>=n/2+1;i--)
				ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		if(n<=10)
		{
			mx=-2e9-10;
			dfs(0,0,0,0,n);
			cout<<mx<<endl;
			continue;
		}
		int ans1=0,ans2=0,cntt1=1,cntt2=1,cntt3=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]&&a[i]>c[i])
				if(cntt1<=n/2) ans1+=a[i],cntt1++;
				else if(b[i]>c[i]&&cntt2<=n/2) ans1+=b[i],cntt2++;
				else ans1+=c[i],cntt3++;
			if(b[i]>a[i]&&b[i]>c[i]) 
				if(cntt2<=n/2) ans1+=b[i],cntt2++;
				else if(a[i]>c[i]&&cntt1<=n/2) ans1+=a[i],cntt1++;
				else ans1+=c[i],cntt3++;
			if(c[i]>a[i]&&c[i]>b[i]) 
				if(cntt2<=n/2) ans1+=c[i],cntt3++;
				else if(a[i]>b[i]&&cntt1<=n/2) ans1+=a[i],cntt1++;
				else ans1+=b[i],cntt2++;
		}
		cntt1=1,cntt2=1,cntt3=1;
		for(int i=n;i>=1;i--)
		{
			if(a[i]>b[i]&&a[i]>c[i])
				if(cntt1<=n/2) ans2+=a[i],cntt1++;
				else if(b[i]>c[i]&&cntt2<=n/2) ans2+=b[i],cntt2++;
				else ans2+=c[i],cntt3++;
			if(b[i]>a[i]&&b[i]>c[i]) 
				if(cntt2<=n/2) ans2+=b[i],cntt2++;
				else if(a[i]>c[i]&&cntt1<=n/2) ans2+=a[i],cntt1++;
				else ans2+=c[i],cntt3++;
			if(c[i]>a[i]&&c[i]>b[i]) 
				if(cntt2<=n/2) ans2+=c[i],cntt3++;
				else if(a[i]>b[i]&&cntt1<=n/2) ans2+=a[i],cntt1++;
				else ans2+=b[i],cntt2++;
		}
		cout<<max(ans1,ans2)<<endl;
	}
	return 0;
}
