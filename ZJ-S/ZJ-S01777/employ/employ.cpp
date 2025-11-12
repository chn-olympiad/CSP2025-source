#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,KK=15,M=1e6+5,MM=1200; 
#define fst first
#define scd second
#define llg long long
#define pii pair<int,int>
#define mkp make_pair
const int inf=2e9,mod=998244353;

int a[N],vis[N],c[N];
string s;
int n,m,K,cnt;
llg ans,val[N];

void solve(int x,int d){
	if(x-d-1>=m){
		ans=(ans+val[n-x+1])%mod;
		return;
	}
	if(n-d<m) return;
	if(x==n+1){
		//if(n-d>=m) ans++;
		return;
	}
	for(int i=1; i<=n; i++) if(!vis[i]){
		vis[i]=1; 
		solve(x+1,d+((d>=c[i])|(!a[x])));
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	val[0]=1; for(int i=1; i<=n; i++) val[i]=(val[i-1]*i)%mod;
	for(int i=1; i<=n; i++){
		a[i]=s[i-1]-'0';
	}
	for(int j=1; j<=n; j++){
		cin>>c[j];
	}
	solve(1,0);
	cout<<ans<<"\n";
}
