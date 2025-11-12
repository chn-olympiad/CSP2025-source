#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a[100005][4],n,m,ct[5],ans,b[100005],cnt,v[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;m=n/2;
		ct[1]=ct[2]=ct[3]=ans=cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				ct[1]++,ans+=a[i][1],v[i]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				ct[2]++,ans+=a[i][2],v[i]=2;
			else ct[3]++,ans+=a[i][3],v[i]=3;
		}
		if(ct[1]<=m&&ct[2]<=m&&ct[3]<=m){
			cout<<ans<<'\n';
			continue;
		}int j=0;
//		cerr<<ct[1]<<' '<<ct[2]<<' '<<ct[3]<<' '<<ans<<'\n';
		for(int i=1;i<=3;i++)if(ct[i]>n/2)j=i;
		for(int i=1;i<=n;i++){
			if(v[i]==j)
				b[++cnt]=a[i][j]-max(a[i][j%3+1],a[i][(j%3+1)%3+1]);
		}
		sort(b+1,b+cnt+1);
		for(int i=1;i<=ct[j]-m;i++)ans-=b[i];
		cout<<ans<<'\n';
	}
}