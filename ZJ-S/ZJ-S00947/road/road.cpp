#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10015;
ll xc[15][N],n,m,mm,k,ans,ltk[N];
bool use[15];
struct node{
	ll u,v,w;
}dl[1400005];
inline bool cmp(node x,node y){return x.w<y.w;}
inline ll fi(int p){return p==ltk[p]?p:ltk[p]=fi(ltk[p]);}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=1145141919810114;
	cin>>n>>m>>k;
	mm=m;
	for (ll i=1;i<=m;++i) cin>>dl[i].u>>dl[i].v>>dl[i].w;
	for (ll i=1;i<=k;++i){
		cin>>xc[i][0];
		for (int j=1;j<=n;++j){
			dl[mm].u=j,dl[mm].v=i+n;
			cin>>dl[mm++].w;
		}
	}
	sort(dl+1,dl+mm+1,cmp);
	for (ll jr=0;jr<(1<<k);jr++){
		memset(use,0,sizeof(use));
		for (ll i=1;i<=n;i++) ltk[i]=i;
		ll now=1,mm=m,cs=n,res=0,jrr=jr;
		while (jrr){
			if (jrr&1){
				cs++;
				res+=xc[now][0];
				ltk[now+n]=now+n;
				use[now]=1;
			}
			jrr>>=1;
			now++;
		}
		ll s=1,cnt=1;
		while (s<cs){
			while ((dl[cnt].v>n&&(!use[dl[cnt].v-n]))||fi(dl[cnt].u)==fi(dl[cnt].v)) cnt++;
			res+=dl[cnt].w;
			ltk[fi(ltk[dl[cnt].v])]=fi(ltk[dl[cnt].u]);
			s++;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
