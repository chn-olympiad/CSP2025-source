#include<bits/stdc++.h>;
using namespace std;
int as,n,m,a[505],b[505],f[505],kl;
int dfs(int x,int y,int s){
	if(x==n+1){
	//	cout<<"----"<<'\n';
		if(s>=m){
			as++;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
	//		cout<<i<<" "<<x<<'\n';
			f[i]=1;
			if(a[x]&&y<b[i]){
				dfs(x+1,y,s+1);
			}else{
				dfs(x+1,y+1,s);
			}
			f[i]=0;
		}
	}
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
		if(a[i]==1) kl++;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m>kl){
		cout<<0;
		return 0;
	}
	if(kl==n){
		long long ans=1,mod=998244353;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}else{
		dfs(1,0,0);
		cout<<as;
	}
	return 0;
} 