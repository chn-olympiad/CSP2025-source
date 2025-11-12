#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 263000
#define mod 998244353
#define int long long
#define popcnt __builtin_popcount
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<"\n"
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024.0<<"\n";
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

bool M1;
int n,m;
char s[MAXN];
int a[MAXN],c[MAXN];
int f[MAXM][25];

void solve1(){
	bool fl=1;
	for(int i=1;i<=n;i++){
		if(!a[i]) fl=0;
		if(!c[i]) fl=0;
	}
	int ans=0;
	if(fl){
		for(int i=1;i<=n;i++) (ans*=i)%=mod;
	}
	printf("%lld\n",ans);
}

bool M2;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int Time=clock();
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	for(int i=1;i<=n;i++) c[i]=read();
	if(n==m){
		solve1();
		return 0;
	}
	f[0][0]=1;
	int nn=(1<<n)-1;
	for(int s=0;s<nn;s++){
		int cnt=popcnt(s);
		for(int i=0;i<=cnt;i++){
			if(!f[s][i]) continue;
//			printf("f[%d][%d]=%d\n",s,i,f[s][i]);
			for(int j=1;j<=n;j++){
				if(s&(1<<(j-1))) continue;
				int t=s|(1<<(j-1));
				if(!a[cnt+1] || i>=c[j]) (f[t][i+1]+=f[s][i])%=mod;
				else (f[t][i]+=f[s][i])%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) (ans+=f[nn][i])%=mod;
	printf("%lld\n",ans);
	look_memory;
	look_time;
	return 0;
}
