#include<iostream>

#define  int  long long
using namespace std;
constexpr int N=505,p=998244353;
int n,m,ans,c[N]; char s[N];
namespace Solve1{
	bool vis[N];
	void dfs(int x,int cnt){
		if(x==n){
			ans+=(cnt>=m);
			return;
		}for(int i=1;i<=n;i++)
			if(!vis[i]){
				vis[i]=1;
				if(x-cnt>=c[i]||s[x+1]=='0')dfs(x+1,cnt);
				else dfs(x+1,cnt+1);
				vis[i]=0;
			}
	}void work(){
		dfs(0,0),cout<<ans<<'\n';
		exit(0);
	}
}namespace Solve2{
	void work(){
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%p;
		cout<<ans<<'\n';
		exit(0);
	}
}

signed main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)Solve1::work();
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(s[i]=='1');
	if(cnt==n)Solve2::work();
	
	return 0;
}
/*
3 2
101
1 1 2

10 5
1111111111
6 1 4 2 1 2 5 4 3 3


*/
