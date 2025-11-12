#include <bits/stdc++.h>
//#include <bits/extc++.h>
#define int long long
#define ret return
#define mp make_pair
#define pb push_back
#define mid (l+r>>1)
using namespace std;
//using namespace __gnu_pbds;
int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	ret s*f;
}
const int Mod=998244353;
int a[510],c[510];
namespace Sub1{
	void solve(int n,int m){
		vector<int> f[n+1];for(int i=0;i<=n;i++)f[i].resize(1<<n);
		f[0][(1<<n)-1]=1;
		for(int i=1;i<=n;i++){
			for(int k=0;k<(1<<n);k++){
				if(__builtin_popcountll(k)!=n-i+1)continue;
				for(int b=1;b<=n;b++){
					if(!((k>>(b-1))&1))continue;
					for(int j=0;j<i;j++){
						if(a[i]==0||j>=c[b])(f[j+1][k^(1<<(b-1))]+=f[j][k])%=Mod;
						if(a[i]==1&&j<c[b])(f[j][k^(1<<(b-1))]+=f[j][k])%=Mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)(ans+=f[i][0])%=Mod;
		printf("%lld",ans);
	}
}
void solve(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%1lld",&a[i]);
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=18)Sub1::solve(n,m);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;while(t--)solve();ret 0;
}

