#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int M = 1e6+N*10+5;
const int K = 15;
struct Edg{
	int s,w,t;
};
Edg edg[M],cp[M];
int c[K],a[K][N],fa[N],siz[N],s[K],n,m,k;
long long ans = 0;
void init(int n){
	for(int i=1;i<=n;i++){
		siz[i] = 1;
		fa[i] = i;
	}
}
int ask(int a){
	
	return fa[a]==a?a:(fa[a] = ask(fa[a]));
}
void h(int a,int b){
	a = ask(a);
	b = ask(b);
	if(siz[a]>siz[b]){
		siz[a]+=siz[b];
		fa[b] = a;
	}
	else{
		siz[b]+=siz[a];
		fa[a] = b;
	}
}
void solve(int t,int mx){
	sort(edg+1,edg+t+1,[](Edg& a,Edg& b)->bool{
		return a.w<b.w;
	});
	int cnt = 1;
	for(int i=1;cnt<mx;i++){
		if(ask(edg[i].s)==ask(edg[i].t)){
			continue;
		}
		cnt++;
		h(edg[i].s,edg[i].t);
		ans+=edg[i].w;
	}
}
void dfs(int si,long long p,int cnt,int cnt2){
	if(si==k+1){
		init(cnt2);
		long long lans = ans;
		ans = 0;
		for(int i=1;i<=cnt;i++){
			cp[i] = edg[i];
		}
		solve(cnt,cnt2);
		for(int i=1;i<=cnt;i++){
			edg[i] = cp[i];
		}
		ans = min(ans+p,lans);
		
		return;
	}
	dfs(si+1,p,cnt,cnt2);
	long long nans = ans;
	++cnt2;
	for(int i=1;i<=n;i++){
		edg[++cnt].w = a[si][i];
		edg[cnt].s = cnt2;
		edg[cnt].t = i;
	}
	if(p+c[si]>=ans){
		
		return;
	}
	dfs(si+1,p+c[si],cnt,cnt2);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edg[i].s>>edg[i].t>>edg[i].w;
	}
	bool flag = true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag = false;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				s[i] = j;
			}
		}
	}
	if(flag){//32
		init(n);
		int t = m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				edg[++t].w = a[i][j];
				edg[t].s = s[i];
				edg[t].t = j;
			}
		}
		solve(t,n);
		cout<<ans;
	}
	else{//32
		ans = 1e18;
		dfs(1,0,m,n);
		cout<<ans;
	}
	
	return 0;
}
