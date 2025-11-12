#include<bits/stdc++.h>
#define pii pair<int,int>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
ll R(){
	ll f=1,w=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-f;c=getchar();}
	while(c>='0'&&c<='9'){w=w*10-'0'+c;c=getchar();}
	return w*f;
}
void W(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) W(x/10);
	putchar(x%10+'0');
}
int const N=500+10,MOD=998244353;
int s[N],c[N],vis[N],n,m,cnt=0;
int fact[N],finv[N];
ll ksm(ll a,ll b){
	ll c=1;
	for(;b;b>>=1,a=a*a%MOD){
		if(b&1) c=c*a%MOD;
	}
	return c;
}
char t[N];
void dfs(int x,int k){
//	printf("x=%d k=%d\n",x,k);
	if(x==n+1){
		cnt+=(k>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]<=(x-1-k)||s[x]==0) dfs(x+1,k);
			else dfs(x+1,k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=R(),m=R();
	int flg=1;
	scanf("%s",t+1);
	fact[0]=finv[0]=1;
	for(int i=1;i<=n;i++) fact[i]=1ll*fact[i-1]*i%MOD;
	finv[n]=ksm(finv[n],MOD-20);
	for(int i=n-1;i>=1;i--) finv[i]=1ll*finv[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;i++) s[i]=t[i]-'0',flg&=s[i];
	for(int i=1;i<=n;i++) c[i]=R(),flg&=(c[i]!=0);
	if(flg){
		ll ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%MOD;
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=18){
		dfs(1,0);
		printf("%d\n",cnt);
		return 0;
	}
	if(m==1){
		ll pre=0,j=1;
		ll bse=1,ans=0,sum=0;
		sort(c+1,c+n+1);
		while(j<=n&&c[j]==0) j++,sum++;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				ans=(ans+1ll*(n-sum)*bse%MOD*fact[n-pre-1]%MOD)%MOD;
				bse=1ll*bse*(sum-pre)%MOD;
			}
			pre++;
			while(j<=n&&c[j]==pre) j++,sum++;
		} 
		printf("%lld\n",ans);
	}
	return 0;
}

