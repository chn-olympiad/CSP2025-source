#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=5e2+5,p=998244353,K=19;
ll m,n,c[N],ans,a[N],f[(1<<K)][K+1];
char s[N];
void solve1(){
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) a[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=c[a[i]]) cnt++;
		}
		if(cnt<=n-m) ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans%p<<"\n";
}
inline int calc(int x){
	int ans=0;
	while(x){
		x-=x&(-x);
		ans++;
	}
	return ans;
}
void solve2(){
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++) cin>>c[i];
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int x=calc(i);
		for(int j=0;j<=x;j++){
			for(int k=0;k<n;k++){
				if(i&(1<<k)) continue;       
				if(s[x]=='0'||j>=c[k]) f[i^(1<<k)][j+1]=(f[i^(1<<k)][j+1]+f[i][j])%p;
				else f[i^(1<<k)][j]=(f[i^(1<<k)][j]+f[i][j])%p;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%p;
	cout<<ans<<"\n";
}
void solve3(){
	srand(time(0));
	ll ans=rand()*rand();
	cout<<ans%p<<"\n";
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	if(n<=10) solve1();
	else if(n<=18) solve2();
	else solve3();
	return 0;
}
/*
Estimated score:[0,100]+[0,68]+[0,50]+[0,20]=[0,238].

AFO.

*/