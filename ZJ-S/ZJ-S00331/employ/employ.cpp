#include<bits/stdc++.h>
using namespace std;
int Mod=998244353;
int n,m,c[505],vis[505],list[505],cnt=0,ans=0;//cnt=accessly employed
string s;
int jie(int x){
	int an=1;
	for(int i=1;i<=x;i++){
		an=(an*i)%Mod;
	}
	return an;
}
void dfs(int x){
	if(x==n){
		ans=(ans+1)%Mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int fl=0;
			if(x-cnt<c[i]&&s[i-1]=='1'){
				cnt++;fl=1;
			}
			vis[i]=1;
			x++;
			if(n-x+cnt<=m){
				x--;
				cnt-=fl;
				vis[i]=0;
				continue;
			}
			else if(cnt>=m){
				vis[i]=0;
				ans=(ans+jie(n-x))%Mod;
				cnt-=fl;
				x--;
				continue;
			}
			//list[x]=i;
			dfs(x);
			x--;
			cnt-=fl;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
/*
5 2
11111
1 0 1 0 1

3 2
101
1 1 2
*/