#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const ll N=1e6+10;
/*====================*/
const ll M=1e4+10;
/*====================*/
const ll INF=0x3F3F3F3F3F3F3F3F;
/*====================*/
struct qq{
	ll u,v,w,cst;
	friend bool operator<(qq f,qq l){
		return f.cst<l.cst;
	}
}s[N];
/*====================*/
ll n,m,k,sum;
ll vis[M],minn[M];
ll c[15],a[15][N];
/*====================*/
void Solve(void){
	ll fg=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)fg=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				fg=0;
			}
		}
	}
	if(fg){
		cout<<0;return;
	}
	for(int i=1;i<=m;i++){
		ll cun=1e9+7;
		for(int j=1;j<=k;j++){
			cun=min(cun,a[j][s[i].u]+a[j][s[i].v]);
		}
		s[i].cst=min(cun,s[i].w);
		//cout<<s[i].cst<<"\n";
	}
	sort(s+1,s+m+1);
	for(int i=1;i<=m;i++){
		if(vis[s[i].u]==1&&vis[s[i].v]==1){
			continue;
		}
		vis[s[i].u]=1,vis[s[i].v]=1;
		sum+=s[i].cst;
		//cout<<sum<<"\n";
	}
	cout<<sum;
}
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}

