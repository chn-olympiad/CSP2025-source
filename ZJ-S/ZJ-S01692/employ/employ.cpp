#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
int n,m,c[505];
int cnt=0;
string s;
bool vis[505];
int jie(int r){
	int x=1ll;
	for(int i=1;i<=r;i++){
		x=(x*(long long)(i))%mod;
	}
	return x;
}
void dfs(int num,int jj){
	if(jj>=m){
		cnt=(cnt+jie(n-num+1))%mod;
		return ;
	};
	if(num==n or m>(n-num+jj)){
		return ;
	};
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(s[num]=='0' or (num-jj)>=c[i]){
				dfs(num+1,jj);
			}
			else{
				dfs(num+1,jj+1);
			};
			vis[i]=false;
		}
	}
	return ;
};
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		vis[i]=false;
	}
	int ty;
	for(int i=1;i<=n;i++){
		ty=(s[0]-'0')&(c[i]==0);
		vis[i]=true;
		dfs(1,ty);
		vis[i]=false;
	}
	printf("%lld\n",cnt);
	return 0;
}
