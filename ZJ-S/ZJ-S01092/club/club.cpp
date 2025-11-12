#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e5+20,M=1e5+20;
const ll INF=1ll<<60,mod=998244353;
int n,a[N][5],num[5][N],tot[5],c[N];
ll ans;
void init(){
	ans=0;
	MS(num,0);MS(c,0x3f);MS(tot,0);
}
void solve(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxx=max({a[i][1],a[i][2],a[i][3]});
		ans+=maxx;
		if(maxx==a[i][1]){
			num[1][++tot[1]]=i;
		}
		else if(maxx==a[i][2]){
			num[2][++tot[2]]=i;
		}
		else{
			num[3][++tot[3]]=i;
		}
	}
	int id=0;
	if(tot[1]>n/2) id=1;
	if(tot[2]>n/2) id=2;
	if(tot[3]>n/2) id=3;
//	cout<<id<<"\n";
	if(!id){
		cout<<ans<<"\n";
		return ;
	}
	for(int t=1;t<=tot[id];t++){
		int i=num[id][t];
		for(int j=1;j<=3;j++){
			if(j==id) continue;
			c[t]=min(c[t],a[i][id]-a[i][j]);
		}
	}
	sort(c+1,c+1+tot[id]);
	for(int i=1;i<=tot[id]-n/2;i++) ans-=c[i];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IOS;int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}
/*

*/
