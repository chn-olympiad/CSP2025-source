#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll a[N][3],vis[N][3];
ll f[N],top;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof vis);
		int n,ca=0,cb=0,cc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)cin>>a[i][j];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				vis[i][0]=1;
				ans+=a[i][0];
				ca++;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				vis[i][1]=1;
				ans+=a[i][1];
				cb++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][1]){
				vis[i][2]=1;
				ans+=a[i][2];
				cc++;
			}
		}
		top=0;
		int maxn=max({ca,cb,cc});
		if(maxn<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(maxn==ca&&vis[i][0])f[++top]=a[i][0]-max(a[i][1],a[i][2]);
			if(maxn==cb&&vis[i][1])f[++top]=a[i][1]-max(a[i][0],a[i][2]);
			if(maxn==cc&&vis[i][2])f[++top]=a[i][2]-max(a[i][1],a[i][0]);
		}
		sort(f+1,f+top+1);
		int p=1;
		while(maxn>n/2){
			ans-=f[p];
			maxn--;
			p++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}