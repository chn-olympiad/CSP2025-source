#include <bits/stdc++.h>
using namespace std;
#define mod 998244353

long long ans;
int m[505],n,k;
int pl[505],vis[505];
string tst;
void dfs(int x){
	if(x==n+1){
		int cnt=0,fal=0;
		for(int i=1;i<=n;i++){
			if(fal>=m[pl[i]]){
				fal++;
				continue;
			}
			if(tst[i-1]=='1'){
				cnt++;
			}else{
				fal++;
			}
		}
		if(cnt>=k){
			ans=(ans+1)%mod;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			vis[i]=1;
			pl[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>tst;
	for(int i=1;i<=n;i++)cin>>m[i];
	int flag=true;
	for(int i=0;i<n;i++){
		if(tst[i]=='0'){
			flag=false;
			break;
		}
	}
	if(flag){
		int cnt=0;
		for(int i=1;i<=n;i++)if(m[i]==0)cnt++;
		if(cnt==0){
			ans=1;
			for(int i=n;i>=1;i--)ans=((ans%mod)*(i%mod))%mod;
		}
	}else{
		dfs(1);
	}
	cout<<ans;
	return 0;
}
