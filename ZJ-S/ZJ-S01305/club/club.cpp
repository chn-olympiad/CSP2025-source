#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll mf[4][N];
ll maxx;
ll ans;
ll now[4];
ll n;
struct node{
	ll cha,ai,big,mid;
};
node x[N];
bool cmp(node aa,node bb){
	return aa.cha>bb.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		now[1]=0;now[2]=0;now[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&mf[1][i],&mf[2][i],&mf[3][i]);
			x[i].cha=max({mf[1][i],mf[2][i],mf[3][i]})-min({mf[1][i],mf[2][i],mf[3][i]});
			x[i].ai=i;
		}
		sort(x+1,x+n+1,cmp);
		maxx=n/2;
		for(int i=1;i<=n;i++){
			int tn=x[i].ai;
			int fm=(mf[1][tn]>mf[2][tn] ? (mf[1][tn]>mf[3][tn] ? 1 : 3) : (mf[2][tn]>mf[3][tn] ? 2 : 3));//biggest
			int tm=(mf[1][tn]>mf[2][tn] ? (mf[2][tn]>mf[3][tn] ? 3 : 2) : (mf[1][tn]>mf[3][tn] ? 3 : 1));//least
			int sm=6-fm-tm;//medium
			if(now[fm]==maxx){
				if(now[sm]==maxx){
					now[tm]++;
					ans+=mf[tm][tn];
				}
				else{
					now[sm]++;
					ans+=mf[sm][tn];
				}
			}
			else{
				ans+=mf[fm][tn];
				now[fm]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

