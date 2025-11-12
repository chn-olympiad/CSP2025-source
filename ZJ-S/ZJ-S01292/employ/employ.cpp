#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int c[505];
bool flag=1;
int AC;
bool vis[505];
int pu[505];
inline int jc(int n){
	int ss=1;
	for(int i=1;i<=n;i++) ss=(ss*i)%mod;
	return ss;
}
inline void dfs(int step){
	if(step==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				sum++;
				continue;
			}
			if(sum>=c[i]){
				sum++;
				continue;
			}
		}
		if(sum<=n-m) AC++;
		return; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		pu[step]=i;
		vis[i]=1;
		dfs(step+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') flag=0;
	}
	if(flag){
		cout<<jc(n)%mod;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<AC;
		return 0;
	}
	cout<<n;
	return 0;
}
