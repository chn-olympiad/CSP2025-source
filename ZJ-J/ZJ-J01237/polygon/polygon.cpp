#include<bits/stdc++.h>
//#define int long long
using namespace std;
const long long mod=998244353;
long long a[5005],s[5005],cnt,ans;
long long n;
void dfs(long long x){
	if(x==n+1){
		if(cnt<3) return ;
		long long sum=0,p=1;
		for(long long i=cnt-1;i>=1;i--){
			sum+=a[s[i]];
			if(sum>a[s[cnt]]){
				p=0;
				break;
			}
		}
		if(p==0){
			ans++;
			ans%=mod;
		}
		return ;
	}
	dfs(x+1);
	cnt++;
	s[cnt]=x;
	dfs(x+1);
	s[cnt]=0;
	cnt--;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int g=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) g=0;
	}
	if(g==1){
		for(int m=3;m<=n;m++){
			int sum=1;
			for(int i=n;i>=m+1;i--){
				sum*=i;
				sum%mod;
			}
			for(int i=2;i<=n-m;i++){
				if(sum<i){
					sum+=mod;
				}
				sum/=i;
			}
			ans+=sum;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1);
	cout<<ans;
	return 0;
}
