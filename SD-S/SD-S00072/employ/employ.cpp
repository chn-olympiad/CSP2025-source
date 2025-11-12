#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e6+9;
int n,m,a[N],b[N],p[N],ans;
bitset<N> vis;
void check(){
	int cnt=0,res=0;
	for(int i=1;i<=n;i++){
		if(cnt<b[p[i]]){
			if(!a[i]){
				res++;
			}else{
				cnt++;
			}
		}else{
			cnt++;
		}
	}
//		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//		cout<<"\n";
//		cout<<res<<"\n";
	if(res>=m){
		ans++;
	}
}
void dfs(int u){
	if(u==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[u]=i;
			vis[i]=1;
			dfs(u+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

