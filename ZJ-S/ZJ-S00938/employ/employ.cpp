#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
const int N=505;
int n,m;
char s[N];
int c[N];
int num1;
const long long MOD=998244353;
long long res=0;
vector<int>a;
bool vis[N];
bool check(){
	int num=0;
	for(int i=0;i<n;++i){
		if(s[i+1]=='0')++num;
		else{
			if(c[a[i]]<=num)++num;
		}
	}
	return n-num>=m;
}
void dfs(int x){
	if(x>n){
		(res+=check())%=MOD;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;	
		vis[i]=true;
		a.push_back(i);
		dfs(x+1);
		vis[i]=false;
		a.pop_back();
	}
	return;
}
long long dp[N][N];
long long g[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=n;++i){
		if(s[i]=='1')++num1;
	}		
	if(n<=18){
		dfs(1);
		cout<<res<<endl;
	}
	else{
		if(num1<m)cout<<0<<endl;
		else{
			long long res=1;
			for(int i=1;i<=n;++i)(res*=i)%=MOD;
			cout<<res<<endl;
		}
	}
	return 0;
}
//S kao zhui ji le
//guan zhu 1040109 & 1137860 ~