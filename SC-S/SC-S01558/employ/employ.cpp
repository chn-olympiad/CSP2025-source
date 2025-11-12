#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

typedef long long ll;

const int N=510,MOD=998244353;

int n,m;
int s[N],c[N];
int res;
int a[N];
char vis[N];

void dfs(int now){
	if(now==n+1){
		int fail=0,cnt=0;
		for(int i=1;i<=n;++i)
			if(!s[i]||fail>=c[a[i]]) ++fail;
			else ++cnt;
		res+=(cnt>=m);
		return;
	}
	for(int i=1;i<=n;++i)if(!vis[i]){
		vis[i]=1;
		a[now]=i; 
		dfs(now+1);
		vis[i]=0;
	}
}
int main(){
	Fre("employ");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%1d",s+i);
	for(int i=1;i<=n;++i) scanf("%d",c+i);
	if(n==m){
		int sum=0;
		for(int i=1;i<=n;++i) sum+=s[i];
		if(sum<n) puts("0");
		else{
			for(int i=1;i<=n;++i)
				if(!c[i])
					puts("0"),exit(0);
			res=1;
			for(int i=1;i<=n;++i)
				res=(ll)res*i%MOD;
			printf("%d\n",res);
		}
		return 0;
	}
	dfs(1);
	printf("%d\n",res);
	
	return 0;
}