#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int arr[20];
int pat[20];
long long ans;
string s;
int n,m;
bool vis[20];
void dfs(int x,int sc,int gu){
	if(x>n){
		if(sc>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i =1;i<=n;i++){
		if(!vis[i]){
			int k = (pat[i]>gu&&s[x-1]=='1'?1:0);
			vis[i]=1;
			dfs(x+1,sc+k,gu+(1-k));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	int cnt=0;
	for(int i =1;i <= n;i++){
		scanf("%d",&pat[i]);
		if(pat[i]==0){
			cnt++;
		}
	}
	if(n-cnt < m){
		printf("0");
		return 0;
	}
	if(n <= 10){
		dfs(1,0,0);
		printf("%lld",ans);
	}else{
		for(int i = n;i > 1;i--){
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans);
	}
	return 0;
}
