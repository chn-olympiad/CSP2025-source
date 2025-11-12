#include<bits/stdc++.h>
using namespace std;
#define maxn 555
#define mod 998244353
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
void file(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int n,m;
ll ans;
string s;
int c[maxn],used[maxn],p[maxn];
void dfs(int now,int fq){
	if(now>n){
		ans+=(n-fq>=m);
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!used[i]){
			used[i]=1;
			p[now]=i;
			if(c[i]<fq){
				dfs(now+1,fq);
			}else{
				dfs(now+1,fq+1);
			}
			used[i]=0;
		}
	}
}
int main(){
	file();
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
