#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10,P=998244353;
char s[N];
int ans=0,n,m,a[N],c[N],vis[N],fc[N];
void dfs(int p){
	if(p>n){
		int flg=0,sum=0;
		for(int i=1;i<=n;i++){
			if(flg>=a[c[i]]){
				flg++;
				continue;
			}
			if(s[i]=='0') flg++;
			else sum++;
		}
		if(sum>=m) ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1,c[p]=i;
		dfs(p+1);
		vis[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	fc[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//fc[i]=fc[i-1]*i;
	}
	dfs(1);
	cout<<ans%P;
	return 0;
}
//CSP-S2025 rp++
//8
//100+[64,100]+[10,25]+8=[180,233] hui ying ma£¿ 
