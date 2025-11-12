#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
int n,m;
string s1;
int s[1010],c[1010];
bool goodA=true,used1[1010];
long long ans=0;

void dfs1(int u,int v){
	if(u==n+1){
		if(v>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used1[i]) continue;
		used1[i]=true;
		if(s[u]==1&&u-v-1<c[i]) dfs1(u+1,v+1);
		else dfs1(u+1,v);
		used1[i]=false;
	}
	return;
}

long long all_(int u){
	if(u==1) return 1;
	return (all_(u-1)*u)%mod;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=0;i<n;i++){
		s[i+1]=s1[i]-'0';
		if(s[i+1]!=1) goodA=false;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	if(!goodA){
		memset(used1,0,sizeof(used1));
		dfs1(1,0);
		printf("%lld\n",ans);
	}else if(goodA){
		ans=all_(n);
		printf("%lld\n",ans);
	}
	return 0;
}
