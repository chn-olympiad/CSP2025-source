#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100005;
int t,n,tot[4];
long long ans=0;
int a[MAXN][4];
bool vis[MAXN][4];
struct Node{
	int d,p;
};
bool cmp1(Node x,Node y){
	return x.d>y.d;
}
bool cmp(int x,int y){
	return x>y;
}
void dfs(int step,long long sum){
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(tot[i]>=n/2) continue;
		tot[i]++;
		dfs(step+1,sum+a[step][i]*1ll);
		tot[i]--;
	}
}
void solve(){
	bool flag2=false,flag3=false;
	ans=0,tot[1]=0,tot[2]=0,tot[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0) flag2=true;
		if(a[i][3]!=0) flag3=true;
	}
	if(n<=10){
		dfs(1,0);
		cout<<ans<<'\n';
		return;
	}
	if(!flag2&&!flag3){
		sort(a[1]+1,a[1]+n+1,cmp);
		for(int i=1;i<=n/2;i++) ans+=a[1][i];
		cout<<ans<<'\n';
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			Node b[4];
			for(int j=1;j<=3;j++){
				Node t;
				t.d=a[i][j];
				t.p=j;
				b[j]=t;
			}
			sort(b+1,b+n+1,cmp1);
			int p1=b[1].p,p2=b[2].p,p3=b[3].p;
			if(tot[p1]<n/2){
				ans+=a[i][p1];
				vis[i][p1]=true;
				tot[p1]++;
			}
			else{
				int posmin=0,minn=100000;
				for(int j=1;j<i;j++) if(minn>a[j][p1]&&vis[j][p1]) minn=a[j][p1],posmin=j;
				if(minn<a[i][p1]) vis[posmin][p1]=false,vis[i][p1]=true,ans-=a[posmin][p1],ans+=a[i][p1];
				if(posmin==0){
					if(tot[p2]<n/2){
						ans+=a[i][p2];
						vis[i][p2]=true;
						tot[p2]++;
					}
					else{
						posmin=0,minn=100000;
						for(int j=1;j<i;j++) if(minn>a[j][p2]&&vis[j][p2]) minn=a[j][p2],posmin=j;
						if(minn<a[i][p2]) vis[posmin][p2]=false,vis[i][p2]=true,ans-=a[posmin][p2],ans+=a[i][p2];
						if(posmin==0){
							ans+=a[i][p3];
							vis[i][p3]==true;
							tot[p3]++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
