#include<bits/stdc++.h>
using namespace std;
int n,a[5010];long long ans;
#define MOD 998244353
int red(){
	char c=getchar();int x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x*=10;x+=c-'0';c=getchar();
	}
	return x;
}
bool vis[5010];

void dfs(int k,int maxx,long long h){
	if(h>maxx*2){
		ans++;ans%=MOD;
	}
	if(k>=n)return;
	for(int i=k+1;i<=n;i++){
			dfs(i,max(maxx,a[i]),h+a[i]);
	}
}
int main(){
	//freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=red();
	dfs(0,0,0);
	cout<<ans;
	return 0;	
	//rp++
}

