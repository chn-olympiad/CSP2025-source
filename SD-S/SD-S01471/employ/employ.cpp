/*
at 16:04
finally aked
with all the best wishes

at 17:20
4 duipais were built

try to write an overall selfeval 
but failed 
*/
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

int n,m,a[510],buc[510];
char s[510];

int f[2][510][510],fac[510];
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>a[i],++buc[a[i]];
	for(int i=n;i;i--)buc[i-1]+=buc[i];
	
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=0;i<=n;i++){
		f[0][0][i]=fac[n-i];
	}
	for(int i=1;i<=n;i++){
		memset(f[i&1],0,sizeof f[0]);
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				int v=f[~i&1][j][k];
				exc(!v);
				Add(f[i&1][j+1][k],v);
				if(k&&s[i]=='1'){
					(f[i&1][j+1][k-1]+=(mod-v)*(buc[j+1]-k+1))%=mod;
					(f[i&1][j][k-1]+=v*(buc[j+1]-k+1))%=mod;
				}
			}			
		}
	}
	int ans=0;
	for(int j=0;j<=n-m;j++){
		Add(ans,f[n&1][j][0]);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	int T=1;while(T--)work();
}
/*
- CONTINUE, NON-STOPPING, FOR THE FAITH
- START TYPING IF YOU DON'T KNOW WHAT TO DO
- STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING
*/

