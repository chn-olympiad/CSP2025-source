#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,mod=998244353;
char s[maxn];
int c[maxn];
int n,m;
bool vis[maxn];
int xu[maxn],ans;
void dfs(int x,int step){
	vis[x]=1;
	xu[step]=x;
	if(step==n){
		int cg=0,sb=0;
		for(int i=1;i<=n;i++){
			if(cg>=m) break;
			if(sb>=c[xu[i]]){
				sb++;
				continue;
			}
			if(s[i]=='1') cg++;
			else sb++;
		}
		if(cg>=m){
			ans++;
			if(ans>mod) ans-=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		dfs(i,step+1);
		vis[i]=0; 
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){//8
		for(int i=1;i<=n;i++){
			dfs(i,1);
			vis[i]=0;
		}
		cout<<ans<<endl;
		return 0;
	}  
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			flag=0;
			break;
		}
	}
	if(flag){//buhui
		int N=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0) N--;
		}
		if(N<m){
			cout<<0<<endl;
			return 0;
		}
		sort(c+1,c+n+1);
		int anss=1;
		for(int i=N;i>=1;i--) anss=anss*i%mod;
		for(int i=n-N;i>=1;i--) anss=anss*i%mod;
		cout<<anss<<endl;
		return 0;
	}
	if(m==n){//4
		if(!flag){
			cout<<0<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0<<endl;
				return 0;
			}
		}
		int anss=1;
		for(int i=n;i>=1;i--) anss=anss*i%mod;
		cout<<anss<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
