#include <cstdio>
#include <algorithm>

const int mod=998244353;
const int maxn=505,maxm=505;
char q[maxn];
int c[maxn];
int n,m;

int a[15];
int ans;

void dfs(int len){
	if(len==n){
		int cnt=0,fail=0;
		for(int i=1;i<=n;i++){
			if(q[i]=='0'||fail>=c[a[i]]) fail++;
			else cnt++;
		}
		if(cnt>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		bool f=true;
		for(int j=1;j<=len;j++) if(a[j]==i) f=false;
		if(f){
			a[len+1]=i;
			dfs(len+1);
			a[len+1]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,&q[1]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	
	if(n<=12) dfs(0),printf("%d\n",ans%mod);
	else puts("Oh No!"); 
	return 0;
}
