#include<bits/stdc++.h>
//#define int long long
#define FST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ls(x)(x<<1)
#define rs(x)(x<<1|1)
#define mid(l,r)((l+r)>>1)
#define fclose buyaojiafclose
using namespace std;
const int maxn=1e4+37,maxm=2e6+37;
int n,m,k;
struct node{
	int x,y,num;
};
bool cmp(node a,node b){
	return a.num<b.num;
}
int c[15];
int w[15][maxn];
node edge[maxm];
int fa[maxn+20];
int fin(int x){
	return fa[x]==x?x:fa[x]=fin(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	FST;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].num;
	}
	bool pdd=0;
	for(int i=1;i<=k;i++){
		bool pd=0;
		cin>>c[i];
		if(c[i]==0)pd=1;
		int pdcnt=0;
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
			if(w[i][j]==0){
				pdcnt++;
			}
		}
		if(pd&&pdcnt==n)pdd=1;
	}
	if(pdd){
		cout<<0<<endl;
		return 0;
	}
	int mxs=1<<k,tot,cnt;
	ll ans=1e18+37;
	for(int s=0;s<mxs;s++){
		tot=m,cnt=n;
		ll nowans=0;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				nowans+=c[i],cnt++;
				for(int j=1;j<=n;j++){
					tot++;
					edge[tot].x=n+i,edge[tot].y=j,edge[tot].num=w[i][j];
				}
			}
		}
		sort(edge+1,edge+tot+1,cmp);
		for(int i=1;i<=n+20;i++){
			fa[i]=i;
		}
		int zcnt=1;
		for(int i=1;i<=tot;i++){
			int finx=fin(edge[i].x),finy=fin(edge[i].y);
			if(finx==finy)continue;
			zcnt++;
			fa[finx]=finy;
			nowans+=edge[i].num;
//			if(zcnt==cnt+1)break;
		}
		ans=min(ans,nowans);
	}
	cout<<ans<<endl;
	return 0;
}

