#include<bits/stdc++.h>
using namespace std;

const int N=1010,mod=998244353;
int n,m,ans,c[N];
int fac[N];
char prb[N];
bool st[N];

void dfs(int dep,int fail,int accept){
	
	//cout<<"dep="<<dep<<" fail="<<fail<<" accept="<<accept<<endl;
	
	if(accept==m){
//		for(int i=1;i<dep;++i)cout<<human[i]<<' ';
//		puts("");
		ans=(ans+fac[n-dep+1])%mod;
		//cout<<ans<<endl;
		return;
	}
	if(dep==n+1)return;
	
	for(int i=1;i<=n;++i){
		if(st[i])continue;
		st[i]=true;
		int newfail=fail,newaccept=accept;
		if(fail>=c[i])newfail++;
		else if(prb[dep]=='0')newfail++;
		else newaccept++;
		dfs(dep+1,newfail,newaccept);
		st[i]=false;
		//cout<<"i="<<i<<" dep="<<dep<<" fail="<<fail<<" accept="<<accept<<endl;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",prb+1);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	
	for(int i=0;i<=n;++i){
		fac[i]=1;
		for(int j=1;j<=i;++j)fac[i]=fac[i]*j%mod;
	}
	
	dfs(1,0,0);
	
	printf("%d\n",ans);
	return 0;
}
