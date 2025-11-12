#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5+10;
int t,n,ans;
int a[N][3],b[N];
bool vis[3];
void dfs(int n1,int n2,int n3,int c,int ans1){
	if(c > n){ans = max(ans1,ans);return;}
	if(n1 > 0)dfs(n1-1,n2,n3,c+1,ans1+a[c][0]);
	if(n2 > 0)dfs(n1,n2-1,n3,c+1,ans1+a[c][1]);
	if(n3 > 0)dfs(n1,n2,n3-1,c+1,ans1+a[c][2]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0;i < 3;i ++)vis[i]=0;
		for(int i = 1;i <= n;i ++){
			for(int j = 0;j < 3;j ++){
				cin >> a[i][j];
				if(a[i][j]!=0)vis[j]=1;
			}
		}
		ans = 0;
		//cout << vis[1] << vis[2];//0 qvan0 1 you!0
		if((!vis[1])&&(!vis[2])){
			for(int i = 1;i <= n;i ++)
				b[i]=a[i][0];
			sort(b+1,b+1+n);
			for(int i = n;i > n/2;i --)ans += b[i];
		}
		else dfs(n/2,n/2,n/2,1,0);
		cout << ans << "\n";
	}
	return 0;
}//Ren5Jie4Di4Ling5%

