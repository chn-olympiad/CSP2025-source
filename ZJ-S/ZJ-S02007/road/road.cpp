#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5;
int n,m,k,f[N],c[N],d[15][N],tt[15],cnt;
ll ans,tme;
struct node{
	int u,v,w;
}a[M],b[M+M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void dfs(int l,int sum,int cnt){
	tme++;
	if(tme>=150000000/(ll)(m*log2(m))){
		cout<<ans;
		exit(0);
	}
	if(sum>=ans) return;
	if(l>k){
		int lll=m;
		ll aans=0,ccnt=0;
		for(int i=1;i<=m;i++) b[i]=a[i];
		for(int i=1;i<=cnt;i++){
			aans+=c[tt[i]]+d[tt[i]][tt[i]];
			for(int j=1;j<=n;j++)
				if(tt[i]!=j)
					b[++lll].u=tt[i],b[lll].v=j,b[lll].w=d[tt[i]][j];
		}
		sort(b+1,b+lll+1,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
//		for(int i=1;i<=cnt;i++) cout<<tt[i]<<" \n"[i==cnt];
		for(int i=1;i<=lll;i++){
//			cout<<b[i].u<<' '<<b[i].v<<' '<<b[i].w<<'\n';
			int ru=find(b[i].u),rv=find(b[i].v);
			if(ru!=rv){
				f[ru]=rv;
				aans+=b[i].w;
				ccnt++;
				if(ccnt==n-1) break;
			}
		}
//		cout<<aans<<' '<<ccnt<<'\n';
		if(ccnt==n-1) ans=min(aans,ans);
		return;
	}
	int p=tt[cnt];
	tt[cnt]=l;
	dfs(l+1,sum+c[l],cnt+1);
	if(p!=0) tt[cnt]=p;
	dfs(l+1,sum,cnt);
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[i][j];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int ru=find(a[i].u),rv=find(a[i].v);
		if(ru!=rv){
			f[ru]=rv;
			ans+=a[i].w;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	dfs(1,0,1);
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
