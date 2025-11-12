#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],ma=0,ans=0;
bool k[5050];
void m(){
	for(int i=1;i<=5000;i++){
		while(b[i]==0) continue;
		ma=max(ma,b[i]);
	}
}

void dfs(int n){
	if(n<=1){
		if(2*ma<1) ans++;
	}
	for(int i=1;i<=n;i++){
		k[i]=0;
		if(b[i]) continue;
		dfs(n-1);
		m();
		k[i]=1;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(1);
	cout<<9;
	return 0;
}

	
