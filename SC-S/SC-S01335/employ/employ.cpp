#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int mod=998244353;
int n,m;
string h;
int c[505],pre[505],ans;
void dfs(int now,int num,int noo){
	if(now==n+1){
		if(num>=m)ans++;
		ans=ans%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=-1){
			int k=c[i];
			if(pre[i]+noo>=c[i]||h[i]==0){
				c[i]=-1;
				dfs(now+1,num,noo+1);
			}else{
				c[i]=-1;
				dfs(now+1,num+1,noo);
			}
			c[i]=k;
		}
	}
	return ;
}
int main(){
	fre("employ");
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(h[i]=='0')pre[i]+=1;
		pre[i]+=pre[i-1];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}