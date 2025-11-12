#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define pb push_back
#define eb emplace_back
#define siz(a) (int)((a).size())
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define exc(expr) if(expr)continue;
#define stop(expr) if(expr)break;
#define ret(expr) if(expr)return;
#define deb(var) cerr<<#var<<'='<<(var)<<"; "
#define debl(var) cerr<<#var<<'='<<(var)<<";\n"
#define inf (long long)(1e18)
#define int long long
template<class T>bool Min(T &x,T y){return x>y?x=y,1:0;} 
template<class T>bool Max(T &x,T y){return x<y?x=y,1:0;} 
const int mod=998244353;
void Add(int &x,int y){x=x+y<mod?x+y:x+y-mod;}
int fpm(int x,int y){
	int ans=1;for(;y;y>>=1,(x*=x)%=mod)if(y&1)(ans*=x)%=mod;return ans;
}

int n,a[100010][4],buc[4];
vec<int> g[4];
void work(){
	cin>>n;
	int ans=0;
	memset(buc,0,sizeof buc);
	for(int i=1;i<=3;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j];
		int t=max_element(a[i]+1,a[i]+4)-a[i];
		++buc[t];
		ans+=a[i][t];
		int cg=-inf;
		for(int j=1;j<=3;j++){
			if(j!=t)Max(cg,a[i][j]-a[i][t]); 
		}
		g[t].eb(cg);
	}
	for(int i=1;i<=3;i++){
		if(buc[i]>n/2){
			sort(all(g[i]),greater<int>());
			for(int j=0;j<buc[i]-n/2;j++)ans+=g[i][j];
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	int T=1;cin>>T;while(T--)work(); 
}
/*
- CONTINUE, NON-STOPPING, FOR THE FAITH
- START TYPING IF YOU DON'T KNOW WHAT TO DO
- STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING
*/
