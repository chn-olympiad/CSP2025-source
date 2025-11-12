#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
bool vis[5005];
int cnt=0;
int p[5005];
long long ans=0;
long long mod=998244353;

void dfs(int x,int j){
	if(x==0){
		int maxn=0;
		long long s=0;
		for(int i=1;i<=cnt;i++){
			maxn=max(maxn,p[i]);
			s+=p[i];
		}
		if(s>1ll*2*maxn){
			ans++; 
		}
		ans%=mod;
		return ;
	}
	for(int i=j;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		p[++cnt]=a[i];
		dfs(x-1,i+1);
		cnt--;
		vis[i]=0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
		}
	}
	if(s==n){
		for(int i=3;i<=n;i++){
			long long sum=1;
			long long cs=1;
			for(int j=1;j<=i;j++){
				sum*=1ll*(n-j+1);
				sum%=mod;
				cs*=1ll*j;
			}
			sum/=cs;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	else{
		for(int i=3;i<=n;i++){
			memset(vis,0,sizeof vis);
			dfs(i,1);
		}	
		cout<<ans%mod;
	}
	return 0;
}
