#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[25],f=1,fac=1,cnt,vis[25];
string s;
void dfs(int x,int y,int num){
	if(x==s.size()){
		if(num>=m) cnt=(cnt+1)%mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		if(y>=a[i]||s[x]=='0'){
			vis[i]=1;
			dfs(x+1,y+1,num);
			vis[i]=0;
		}
		else{
			vis[i]=1;
			dfs(x+1,y,num+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<s.size();++i){
		if(s[i]=='0') f=0;
	}
	if(f){
		for(int i=1;i<=n;++i) fac=(1ll*fac*i)%mod;
		printf("%d",fac);
		return 0;
	}
	dfs(1,0,0);
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
