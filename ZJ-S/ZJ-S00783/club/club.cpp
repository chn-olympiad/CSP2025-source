#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=26;
int T,n,a[N][4],ans,f[M][M][M];
void dfs(int t,int s,int x,int y){
	if(f[x][y][t-x-y-1]>s) return;
	else f[x][y][t-x-y-1]=s;
	if(t>n){
		ans=max(s,ans);
		return;
	}
	for(int i=1;i<4;i++){
		if(i==1&&x<n/2) dfs(t+1,s+a[t][i],x+1,y);
		if(i==2&&y<n/2) dfs(t+1,s+a[t][i],x,y+1);
		if(i==3&&t-x-y<=n/2) dfs(t+1,s+a[t][i],x,y);
	}
}
struct Node{
	int x,y,z;
}b[N];
bool cmp(Node x,Node y){
	int p=abs(x.x-x.y),q=abs(y.x-y.y);
	if(p^q) return p>q;
	return max(x.x,x.y)>max(y.x,y.y);
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(f,0,sizeof f);
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++){
				cin>>a[i][j];
			}
			b[i]={a[i][1],a[i][2],a[i][3]};
		}
		if(n<=50) dfs(1,0,0,0);
		else{
			sort(b+1,b+n+1,cmp);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt<n/2&&b[i].x>b[i].y){
					ans+=b[i].x;
					cnt++;
				}
				else ans+=b[i].y;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}