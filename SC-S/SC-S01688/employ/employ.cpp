#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=998'244'353;
int n,m,a[N],c[N],ans;
bool usd[N];
int ord[N];
void dfs(int u){
	if(u>n){
		int ly=0;
		for(int i=1,cnt=0;i<=n;i++){
			if(a[i]==0||cnt>=c[ord[i]])cnt++;
			else ly++;
		}
		if(ly>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)if(!usd[i]){
		ord[u]=i;usd[i]=1;
		dfs(u+1);
		usd[i]=0;
	}
}
ll fac(int x){
	ll res=1;
	for(int i=2;i<=x;i++)res*=i,res%=mod;
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%1d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	if(m==n){
		sort(a+1,a+n+1);
		bool flg=1;
		for(int i=1;i<=n;i++){
			flg&=(a[i]==1);
		}
		if(!flg)printf("0\n");
		else printf("%lld\n",fac(n));
	}else if(n<=10){
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}