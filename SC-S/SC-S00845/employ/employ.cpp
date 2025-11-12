#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,qm=998224353,cnt1;
const int N=505;
int c[N],s[N],vis[N];
void dfs(int x,int cnt,int suc){
	if(x>n){
		cnt1=(cnt1+(suc>=m))%qm;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(cnt>=c[i]) dfs(x+1,cnt+1,suc);
			else{
				if(s[x]==1) dfs(x+1,cnt,suc+1);
				else dfs(x+1,cnt+1,suc);
			}
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		char c1;
		scanf(" %c",&c1);
		s[i]=c1-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(1,0,0);
	cout<<cnt1;
	return 0;
}