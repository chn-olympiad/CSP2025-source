#include<bits/stdc++.h>
const int mod=998244353;
typedef long long ll;
int n,maxa;
ll ans;
ll c[5005][5005];
int a[5005]; 
void dfs(int i,int s,int maxx,int cont){
	if(i>n){
		if(s>2*maxx&&cont>=3) ans++;
		ans%=mod;
		return ;
	}
	dfs(i+1,s+a[i],std::max(maxx,a[i]),cont+1);
	dfs(i+1,s,maxx,cont);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
		maxa=std::max(maxa,a[i]);
	}
	std::sort(a+1,a+1+n);
	if(n<=3){
		if(a[1]+a[2]>a[3]) std::cout<<1;
		else std::cout<<0;
		return 0;
	}
	if(n<=10){
		dfs(1,0,0,0);
		std::cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0,0,0);
		std::cout<<ans;
		return 0;	
	}
	if(maxa==1){
		for(int i=0;i<=n;i++) c[i][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			ans+=c[n][i];
			ans%=mod;
		}
		std::cout<<ans;
		return 0;
	}
	return 0;
}

