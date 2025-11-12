#include<iostream>
#include<cstdio>
#include<string>
#define int long long
using namespace std;
const int mx=510;
const int mod=998244353;
int n,m,c[mx];
string s;

bool vis[mx];

int sum=0;

void dfs(int step,int cnt){
	if(step==n+1){
		if(n-cnt>=m) sum=(sum+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(cnt>=c[i]||s[step-1]=='0') dfs(step+1,cnt+1);
			else dfs(step+1,cnt);
			vis[i]=false;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
//	bool fl=true;
//	for(int i=0;i<s.length();i++){
//		if(s[i]=='0') fl=false;
//	}
//	int ans=1;
//	if(fl){
//		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
//		cout<<ans<<endl;
//		return 0;
//	}
	dfs(1,0);
	cout<<sum<<endl;
	return 0;
}
