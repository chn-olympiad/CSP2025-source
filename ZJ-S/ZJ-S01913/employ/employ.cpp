#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
int n,m,c[505],cnt=0,ans=0,a[505];
bitset<505> v;
char s[505];
void dfs(int now){
	if(now>n){
		cnt=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=c[a[i]]){
				sum++;
			}else{
				if(s[i]=='1'){
					cnt++;
				}else{
					sum++;
				}
			}
		}

		if(cnt>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			a[now]=i;
			dfs(now+1);
			v[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt==n){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cnt++;
			}
		}
		if(n-cnt<m){
			puts("0");
			return 0;
		}
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}else if(n<=10){
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}
//yzczex
