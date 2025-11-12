#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define int long long
const int N=1e5+5;
int n,vis[N];
PII a[N][4],b[N],c[N],d[N];
bool cmp1(PII x,PII y){
	return x.first>y.first;
	if(x.first==y.first) return x.second<y.second;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		cin>>n;
		if(n<=2){
			pair<int,int> a1[4],b1[4];
			for(int i=1;i<=3;++i){cin>>a1[i].first;a1[i].second=i;}
			for(int i=1;i<=3;++i){cin>>b1[i].first;b1[i].second=i;}
			sort(a1+1,a1+4,cmp1);sort(b1+1,b1+4,cmp1);
			if(a1[1].second!=b1[1].second) cout<<a1[1].first+b1[1].first<<'\n';
			else cout<<max(a1[2].first+b1[1].first,a1[1].first+b1[2].first)<<'\n';
			continue;
		}
		else {
			int m=n/2,ans=0;
			memset(vis,0,sizeof vis);
			for(int i=1;i<=n;++i){
				cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;
				a[i][1].second=i;
				a[i][2].second=i;
				a[i][3].second=i;
				sort(a[i]+1,a[i]+4,cmp1);
				b[i]=a[i][1];
				c[i]=a[i][2];
				d[i]=a[i][3];
			}
			sort(b+1,b+1+n,cmp1);
			sort(c+1,c+1+n,cmp1);
			sort(d+1,d+1+n,cmp1);
			for(int i=1;i<=m;++i){
				ans+=b[i].first;
				vis[b[i].second]=1;
			}
			for(int i=1;i<=n;++i)
				if(vis[c[i].second]==0) ans+=c[i].first;
			for(int i=1;i<=n;++i)
				if(vis[d[i].second]==0) ans+=d[i].first;
			cout<<ans<<'\n';
		}
	}
	return 0;
}