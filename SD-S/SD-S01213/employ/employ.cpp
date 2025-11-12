#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template <typename ty>
inline void read(ty &x) {
	x=0; bool f=0; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
template <typename ty,typename ...T>
inline void read(ty &x,T &...te) {
	read(x); read(te...);
}
const int N=503;
const int MOD=998244353;
char s[N];
int c[N];
int n,m;
namespace Subtask1{
int f[1<<18][19];
void Add(int &x,int y) {
	x+=y;
	if(x>=MOD) x-=MOD;
}
void solve() {
	f[0][0]=1;
	for(int S=0;S<1<<n;S++) {
		int pcnt=__builtin_popcount(S); 
		for(int i=0;i<=n;i++) if(f[S][i]) {
			for(int j=1;j<=n;j++) if(S>>j-1&1^1) {
				if(i>=c[j]||s[pcnt+1]=='0') Add(f[S|(1<<j-1)][i+1],f[S][i]);
				else Add(f[S|(1<<j-1)][i],f[S][i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) 
		Add(ans,f[(1<<n)-1][i]);
	printf("%d",ans);
}
}
namespace Subtask2{
void solve() {
	for(int i=1;i<=n;i++) 
		if(s[i]=='0') {
			puts("0");
			return ;
		}
	for(int i=1;i<=n;i++) 
		if(!c[i]) {
			puts("0");
			return ;
		}
	ll ans=1;
	for(int i=1;i<=n;i++) 
		ans=ans*i%MOD;
	printf("%lld",ans);
}
}
namespace Subtask3{
void solve() {
	sort(c+1,c+n+1);
	ll ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%MOD;
	ll p=0;
	ll t=1; ll cnt=0,cur=0;
	for(int i=1;i<=n;i++) {
		if(s[i]=='0') {
			cnt++;
		}else {
			while(p<n&&c[p+1]<=i-1) p++;
			t=t*(p-cur)%MOD;
			cur++;
		}
	}
	for(int i=1;i<=cnt;i++) t=t*i%MOD;
	(ans-=t)%=MOD;
	ans=(ans+MOD)%MOD;
	printf("%lld",ans);
}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n,m);
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n;i++) if(s[i]=='1') cnt++;
	for(int i=1;i<=n;i++) read(c[i]);
	if(n<=18) Subtask1::solve();
	else if(m==n) Subtask2::solve();
	else if(m==1) Subtask3::solve();
	else puts("0");
	return 0;
}

