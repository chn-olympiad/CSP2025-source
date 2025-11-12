#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,ans;
int a[N],b[N],c[N];
void dfs(int k,int sum,int opta,int optb,int optc)
{
	if(k==n){ans=max(ans,sum);return;}
	if(opta+1<=n/2)
	dfs(k+1,sum+a[k+1],opta+1,optb,optc);
	if(optb+1<=n/2)
	dfs(k+1,sum+b[k+1],opta,optb+1,optc);
	if(optc+1<=n/2)
	dfs(k+1,sum+c[k+1],opta,optb,optc+1);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i]>>b[i]>>c[i];
		if(n<=10) dfs(0,0,0,0,0),cout<<ans<<"\n";//20pts
		else if(b[1]==0&&b[2]==0&&c[1]==0&&c[2]==0)
		{
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=n/2;++i) ans+=a[i];
			cout<<ans<<"\n";
		}//5pts
		else
		{
			int opt[4]={0,0,0,0};
			for(int i=n;i>=1;--i)
			{
				if(opt[1]<n/2&&opt[2]<n/2&&opt[3]<n/2)
				{
					if(a[i]>=b[i]&&a[i]>=c[i]) ans+=a[i],opt[1]++;
					else if(b[i]>=c[i]&&b[i]>=a[i]) ans+=b[i],opt[2]++;
					else if(c[i]>=a[i]&&c[i]>=b[i]) ans+=c[i],opt[3]++;
				}
				else if(opt[1]<n/2&&opt[2]<n/2)
				{
					if(a[i]>=b[i]) ans+=a[i],opt[1]++;
					else if(b[i]>=a[i]) ans+=b[i],opt[2]++;
				}
				else if(opt[2]<n/2&&opt[3]<n/2)
				{
					if(c[i]>=b[i]) ans+=c[i],opt[3]++;
					else if(b[i]>=c[i]) ans+=b[i],opt[2]++;
				}
				else if(opt[1]<n/2) ans+=a[i],opt[1]++;
				else if(opt[2]<n/2) ans+=b[i],opt[2]++;
				else if(opt[3]<n/2) ans+=c[i],opt[3]++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
