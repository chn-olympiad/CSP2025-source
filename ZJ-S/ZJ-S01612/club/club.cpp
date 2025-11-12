#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+5;
int n,a[N][3],d[N],ans,cnt[3],b[N],tot;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ans+=max({a[i][0],a[i][1],a[i][2]});
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) d[i]=0;
			else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]) d[i]=1;
			else d[i]=2;
			cnt[d[i]]++;
		}
		if(cnt[0]>n/2){
			for(int i=1;i<=n;i++){
				if(d[i]==0) b[++tot]=max(a[i][1]-a[i][0],a[i][2]-a[i][0]);
			}
			sort(b+1,b+1+tot);
			while(tot>n/2){
				ans+=b[tot];
				tot--;
			}
		}else if(cnt[1]>n/2){
			for(int i=1;i<=n;i++){
				if(d[i]==1) b[++tot]=max(a[i][0]-a[i][1],a[i][2]-a[i][1]);
			}
			sort(b+1,b+1+tot);
			while(tot>n/2){
				ans+=b[tot];
				tot--;
			}
		}else if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				if(d[i]==2) b[++tot]=max(a[i][0]-a[i][2],a[i][1]-a[i][2]);
			}
			sort(b+1,b+1+tot);
			while(tot>n/2){
				ans+=b[tot];
				tot--;
			}
		}
		cout<<ans<<"\n";
		ans=tot=cnt[0]=cnt[1]=cnt[2]=0;
	}
	return 0;
}