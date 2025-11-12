#include <iostream>
using namespace std;
const int N=502,mod=998244353;
typedef long long ll;
int n,m;
int c[N],a[N];
string s;
bool vis[N];
ll ans=0;
void dfs(int u,int num,int uu){
	if(num-uu<c[u]&&a[num+1]==1) uu++;
	num++;
	if(num==n){
		if(uu>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,num,uu);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<len;i++){
		a[i+1]=(s[i]=='0')?0:1;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,0,0);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
