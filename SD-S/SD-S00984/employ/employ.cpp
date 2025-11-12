#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ve vector
#define pb push_back
#define pii pair<int,int> 
#define p_q priority_queue
#define mk make_pair
#define fi first
#define se second
namespace cute_fzj_kuai_ruarua{
	int n,m,c[505],s[505],vis[505],ans=0,a[505];
	const ll mod=998244353;
	void dfs(int x){
		if(x==n+1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt>=a[i]||!s[i]){
					cnt++;
				}
			}
			if(n-cnt>=m) ans++;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				a[x]=c[i];
				dfs(x+1);
				vis[i]=0;
			}
		}
	}
	void main(){
		cin>>n>>m;
		string _;
		cin>>_;
		for(int i=0;i<_.size();i++){
			s[i+1]=_[i]-'0';
		}
		for(int i=1;i<=n;i++) cin>>c[i];
		dfs(1);
		cout<<ans;
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}
