#include<bits/stdc++.h>
#define int long long
#define I ios_base::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
#define endl '\n'
#define mod 998244353
using namespace std;
const int maxn=1001;  
int n,m; string str; int na[maxn]; int te[maxn];bool A=true;int ans=0;int o0=0;
bool vis[maxn];
void dfs(int t0,int dep,int u,int x){
	cout<<t0<<" "<<dep<<" "<<u<<" "<<x<<endl;
	vis[u]=true;
	int new_t0=t0; int new_x=x;
	if(te[dep]==0 || na[u]<t0)new_t0++;
	else new_x++;
	if(dep==n && x>=m){ans++; return;}
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs(new_t0,dep+1,i,new_x);
	}
	vis[u]=false;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	I AK CSP 
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){cin>>na[i]; if(na[i]==0)o0++;}
	for(int i=0;i<n;i++){te[i+1]=str[i]-'0'; if(te[i+1]!=1)A=false;}
	for(int i=1;i<=n;i++)dfs(0,1,i,0);
	cout<<ans;
	return 0;
}