#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=10+5;
struct line {
	int s,e,len;
	bool operator<(const line com)const {
		return len<com.len;
	}
}a[M+N*K];
int cnt,ans,top;
int fa[N+K];
int len[N+K];
int vis[N+K];
int open[N+K];
int mx[N];
int n,m,k;
int find(int p) { //²¢²é¼¯
	if(fa[p]==p) {
		return p;
	}
	return fa[p]=find(fa[p]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(len,0x3f,sizeof(len));
	cin>>n>>m>>k;
	for(int i=1; i<=n+k; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=m; i++) {
		int s,e,l;
		cin>>s>>e>>l;
		a[++top]={s,e,l};
		mx[s]=max(mx[s],l);
		mx[e]=max(mx[e],l);
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>open[i];
		bool flag=0;
		for(int j=1;j<=n;j++){
			int len;
			cin>>len;
			if(mx[j]>len+open[i]){
				a[++top]={i,j,len+open[i]};
				if(flag==0){
					cnt++;
					flag=1;
				}
			}
		}
	}
	int use=0;
	sort(a+1,a+top+1);
	for(int i=1;use<n+cnt;i++){
		if(find(a[i].s)==find(a[i].e)){
			continue;
		}
		fa[find(a[i].s)]=find(a[i].e);
		vis[a[i].s]++;
		vis[a[i].e]++;
		len[a[i].s]=min(len[a[i].s],a[i].len);
		len[a[i].e]=min(a[i].len,len[a[i].e]);
		use++;
		ans+=a[i].len;
		if(use==n+k-1)break;
	}
	for(int i=n+1;i<=n+k;i++){
		if(vis[i]==1){
			ans-=len[i];
		}else{
			ans-=(vis[i]-1)*open[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}

