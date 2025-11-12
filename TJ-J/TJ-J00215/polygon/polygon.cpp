#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int a[N],vis[N],b[N]; 
int ans,n;
void f(int deep,int T,int o){
	if(deep>T){
		b[deep-1]=o;
		if(b[deep-1]<=b[deep-2]&&deep!=1)return;
		int sum=0,mx=0;
		for(int i=1;i<=T;i++){
			sum+=a[b[i]];
			mx=max(mx,a[b[i]]);
		}
		if(mx*2<sum)ans++;
		return;
	}
	if(vis[o])return;
	b[deep-1]=o;
	if(b[deep-1]<=b[deep-2]&&deep!=1)return;
	vis[o]=1;
	for(int i=deep;i<=n;i++){
		f(deep+1,T,i);
		vis[i+1]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int u=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)u=1;
	}
	if(u!=1){
		ans=n;
		for(int i=2;i<=n;i++){
			ans+=(n-i+2)*(n-i+1)/2;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		f(1,i,0);
	}
	cout<<ans;
	return 0;
}
