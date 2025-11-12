#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
string s;
int c[510];
bool now[510];
const int MOD=998244353;
void dfs(int k,int sum,int x){	
	if(x>=m){
		ans++;
		cout<<k;
		ans%=MOD;
		return;
	}
	if(k==n+1)return;
	for(int i=k;i<=n;i++){
		if(now[i])continue;
		if(sum>=c[i])continue;
		if(s[k-1]=='1'){
			now[i]=1;
			dfs(k+1,sum,x+1);
			now[i]=0;
		}else{
			now[i]=1;
			dfs(k+1,sum+1,x);
			now[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
//	bool f=0;
//	for(int i=0;i<n;i++){
//		if(s[i]!='1')f=1;
//	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
