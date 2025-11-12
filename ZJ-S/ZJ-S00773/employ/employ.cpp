#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,c[N];
char s[N];
int ord[N],used[N];
int ans=0,sum1=0,sum2=0;
void dfs(int x){
	if(x>n){
		int out=0,in=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') out++;
			else if(c[ord[i]]<=out) out++;
			else if(s[i]=='1') in++;
		}
		if(in>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			ord[x]=i;
			used[i]=1;
			dfs(x+1);
			used[i]=0; 
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++){
		if(s[i]=='1') sum1++;
		if(c[i]>0) sum2++;
	}
	if(sum1<m||sum2<m) puts("0");
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		printf("%lld",ans);
	}
	else{
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
18 5
110111101111001011
6 0 4 2 1 2 5 4 3 3 8 5 3 1 0 5 6 4
*/
