#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,s1,s2,s3,ans,cnt;
int a[N][5],b[N],vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cnt=s1=s2=s3=ans=0;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
					s1++;
					vis[i]=1;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					s2++;
					vis[i]=2;
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
					s3++;
					vis[i]=3;
			}
		}
		if(s1>n/2){
			for(int i=1;i<=n;i++)
				if(vis[i]==1) b[++cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			sort(1+b,1+b+cnt);
			for(int i=1;i<=s1-n/2;i++) ans-=b[i];
			cout<<ans<<"\n";
		}
		else if(s2>n/2){
			for(int i=1;i<=n;i++)
				if(vis[i]==2) b[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			sort(1+b,1+b+cnt);
			for(int i=1;i<=s2-n/2;i++) ans-=b[i];
			cout<<ans<<"\n";
		}
		else if(s3>n/2){
			for(int i=1;i<=n;i++)
				if(vis[i]==3) b[++cnt]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			sort(1+b,1+b+cnt);
			for(int i=1;i<=s3-n/2;i++) ans-=b[i];
			cout<<ans<<"\n";
		}
		else cout<<ans<<"\n";
	}
	return 0;
}