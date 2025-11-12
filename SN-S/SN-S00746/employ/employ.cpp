#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501],c[501],ans,w[501];
bool b[501];
char z;
void dfs(long long mq,long long s,long long cs,long long yj){
	b[mq]=1;
	if(cs<c[mq]&&a[s]) yj++;
	else cs++;
	if(s==n){
		if(yj>=m) ans=(ans+1)%998244353;
		b[mq]=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		dfs(i,s+1,cs,yj);
	}
	b[mq]=0;
}
void dfs2(long long mq,long long s,long long cs,long long yj){
	b[mq]=1;
	if(cs<c[mq]&&a[s]){
		ans=(ans+w[n-s])%998244353;
		b[mq]=1;
		return;
	}
	if(s==n){
		b[mq]=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		dfs(i,s+1,cs,yj);
	}
	b[mq]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>z;
		a[i]=z-48;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==1){
		w[1]=1;
		for(int i=2;i<=500;i++){
			w[i]=(w[i-1]*i)%998244353;
		}
		for(int i=1;i<=n;i++){
			dfs(i,1,0,0);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,0,0);
	}
	cout<<ans;
	return 0;
}

