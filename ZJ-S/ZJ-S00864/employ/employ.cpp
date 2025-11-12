#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,k,a[100010],vis[100010],cnt;
string s;
long long min(int x,long long y){
	if(x<y) return x;
	return y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++){
		cin>>k;
		ans+=min(1,k);
	}
	for(long long i=ans;i>=ans-m+1;i--){
		a[++cnt]=i;
	}
	for(long long i=1;i<=cnt;i++){
		for(long long j=m;j>=1;j--){
			if(vis[j]) continue;
			if(a[i]%j==0){
				a[i]/=j;
				vis[j]=1;
			}
		}
	}
	long long ans=1;
	for(long long i=1;i<=cnt;i++){
		ans*=a[i];
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}