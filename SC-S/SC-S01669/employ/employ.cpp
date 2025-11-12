#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
char d[502];
int n,m,e[502],fac[502],val[502],ans,flc;
vector<int> path;
bool flag=0,vis[502];
inline void dfs(int step,int cnt,int cur){
	if(cnt+n-step+1-val[step]<m) return;
	if(step==n+1){
		if(cnt>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		vis[i]=1;
		path.push_back(i);
		if(cur>=e[i] or d[step]=='0') dfs(step+1,cnt,cur+1);
		else dfs(step+1,cnt+1,cur);
		path.pop_back();
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1; i<=n; i++){
		cin>>d[i];
		fac[i]=(fac[i-1]*i)%mod;
//		if(fac[i]==161088479) cout<<"WARN:"<<i<<"\n";
		if(d[i]=='0') flag=1;
	} 
	for(int i=1; i<=n; i++){
		cin>>e[i];
		if(e[i]==0) flc++;
	} 
	if(m==n){
		if(flc!=0 or flag) cout<<0;
		else cout<<fac[n];
		return 0;
	}else if(!flag){
		if(n-flc<m) cout<<0;
		else cout<<fac[n];
		return 0;
	}
	for(int i=n; i>=1; i--){
		val[i]=val[i+1]+(d[i]=='0');
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
