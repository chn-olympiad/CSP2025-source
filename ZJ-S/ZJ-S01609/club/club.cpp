#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int t,n,cnt,a[N][4];
int gg[4],mx;
void dfs(int d,int g[],int cnt){
	if(d>n){
		mx=max(mx,cnt);
//		cout<<cnt<<endl;
	}
	for(int i=1;i<=3;i++){
		if(g[i]<(n/2)){
			g[i]++;
			dfs(d+1,g,cnt+a[d][i]);
			g[i]--;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
//				cout<<i<<" "<<j<<endl;
			}
		}
		dfs(1,gg,0);
		cout<<mx<<endl;
	}
	return 0;
}
