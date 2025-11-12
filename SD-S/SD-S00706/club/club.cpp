#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],d[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int i,j,n,m,t,ca,cb,cc,del,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ca=cb=cc=ans=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) ca++,ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i]) cb++,ans+=b[i];
			else cc++,ans+=c[i];
		}
		if(ca<=n/2&&cb<=n/2&&cc<=n/2) cout<<ans<<'\n';
		else
		{
			if(cb>n/2) {swap(ca,cb);for(i=1;i<=n;i++) swap(a[i],b[i]);}
			if(cc>n/2) {swap(ca,cc);for(i=1;i<=n;i++) swap(a[i],c[i]);}
			del=ca-n/2;
			for(i=1;i<=n;i++)
			{
				if(a[i]>=b[i]&&a[i]>=c[i]) d[i]=a[i]-max(b[i],c[i]);
				else d[i]=2e9;
			}
			sort(d+1,d+n+1);
			for(i=1;i<=del;i++) ans-=d[i];
			cout<<ans<<'\n';
		}
	}
}
