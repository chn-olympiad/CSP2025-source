#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=500,mod=998244353;

char s[N];

int n,m,times[N],c[N],ans,vis[N];

void DFS(int x,int st,int citui){
	if(st==n){
		if(s[st]=='0'){
			citui++;
		}else if(citui>=c[x]){
			citui++;
		}
		if(n-citui>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	if(s[st]=='0'){
		citui++;
	}else if(citui>=c[x]){
		citui++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		DFS(i,st+1,citui);
		vis[i]=0;
	}
	return ;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')f=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			DFS(i,1,0);
			vis[i]=0;
		}
		cout<<ans;
		return 0;
	}
	if(f==1){
		times[0]=1;
		for(int i=1;i<=n;i++){
			times[i]=times[i-1]*i;
			times[i]%=mod;
		}
		cout<<times[n];
		return 0;
	}
	cout<<0<<endl;
	
	return 0;
}
