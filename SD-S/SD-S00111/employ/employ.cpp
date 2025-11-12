#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353;
int n,m;
string s;
int c[N];
int sum[N];
int t[N];
bool vis[N];
int ans;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int k){
	if(k>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[t[i]]>sum[i]&&s[i-1]=='1'){
				cnt++;
			}
		}
		if(cnt>=m){
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1; 
			t[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(s[i-1]=='0');
	}
	bool flagA=1;
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			flagA=0;
			break;
		}
	}
	if(flagA){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cnt++;
			}
		}
		cnt=n-cnt;
		if(cnt<m){
			printf("0");
			return 0;
		}
		int ans=1;
		for(int i=n;i>=1;i--){
			ans=ans*i%mod;
		}
		printf("%lld",ans);
	}
	else{
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}
