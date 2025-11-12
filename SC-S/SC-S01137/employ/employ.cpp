#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const ll md=998244353;
char s[N];
int c[N],m,n;
ll f[(1<<18)+5][20],ans;
void solve(){
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))) cnt++;
		for(int k=0;k<=n;k++)
			for(int j=1;j<=n;j++)
				if(!(i&(1<<(j-1)))){
					int to=k;
					if(k>=c[j] || s[cnt+1]=='0') to++;
					f[i+(1<<(j-1))][to]=(f[i+(1<<(j-1))][to]+f[i][k])%md;
				}
	}
	for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%md;
	printf("%lld",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=18) solve();
	else{
		ll v=1,cnt=n;
		for(int i=1;i<=n;i++){
			v=v*i%md;
			if(!c[i] || s[i]=='0') cnt--;
		}
		if(cnt!=n) printf("0");
		else printf("%lld",v);
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
/*
4 2
1100
1 2 3 1
*/