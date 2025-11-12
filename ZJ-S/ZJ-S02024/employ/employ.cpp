#include<bits/stdc++.h>
using namespace std;
char c[100000];
long long t,n,k[10],a1[100100],flagnm,sum,flagm1,flag18,out,flaga,nai[1000000],ans,m,a2[100100],a3[100100],vis[100100],dp[201][101][101],maxn;
void dfs(long long sum,long long step){
	if(sum==(1<<n)-1){
		int flagcheck=0,defeat=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='0'||defeat>=k[i]){
				defeat++;
			}
			
			if(defeat>n-flag18){
				flagcheck=1;
				break;
			}
		}
		if(flagcheck==0)
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
	if(!((sum>>(i-1))&1)){
		k[step]=nai[i];
		dfs(sum^(1<<(i-1)),step+1);
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0'){
			flagnm=1;flaga=1;
		}
		if(c[i]=='1'){
			flagm1=1;flag18++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>nai[i];
	}
	if(m>flag18){
		cout<<0;
		return 0;
	}
	if(flagnm==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n==m){
		if(flagnm==1)cout<<0;
		else{
			ans=1;
			for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
		}
		return 0;
	}
	else if(flaga==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	else{
		if(n>7){
		sort(nai+1,nai+n+1);
		for(int i=1;i<=n;i++){
			if(c[i]=='0')out++;
			if(out>=nai[i+1]){
				out++;
				sum++;
				if(sum>flag18-m){
					cout<<0;
					return 0;
				}
			}
		}
	}
	else{
		dfs(0,1);
		cout<<ans;
	}
	}
return 0;
}
//6 0 5
//5 0 0
//4 0 0
//3 0 0
//abaaa
//aabaa
