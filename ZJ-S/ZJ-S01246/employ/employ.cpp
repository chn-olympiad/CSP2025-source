#include<bits/stdc++.h>
using namespace std;
int n,m,b[1001],flag,cnt,c[1001],f[300005][20],ans,bb[1001];
void dfs(int k,int x,int w){
	if(k>n){
		if(w>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(bb[i]==0){
			bb[i]=1;
			if(b[k]==0||x>=c[i])dfs(k+1,x+1,w);
			else dfs(k+1,x,w+1);
			bb[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1')b[i]=1;
		else{
			b[i]=0;
			flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(m==n){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}