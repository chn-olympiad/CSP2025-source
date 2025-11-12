#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
ll T,n;
ll ans;
ll bot[4];
ll vis[N]; 
ll f[N][N>>1][3],ff[N][N>>1][3];
struct node{
	ll x,y,z;
}a[N];

bool cmp(node a,node b){
	return a.x>b.y;
}
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i].y!=0||a[i].z!=0) return 0;
	}
	return 1;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i].z!=0) return 0;
	}
	return 1;
}
void dfs(ll x,ll sum){
	if(x==n){
		ans=max(ans,sum);
	}
	for(int i=x+1;i<=n;i++){
		if(bot[1]+1<=n/2){
			vis[i]=1;
			bot[1]++;
			dfs(i,sum+a[i].x);	
			bot[1]--;
		}
		if(bot[2]+1<=n/2){
			vis[i]=2;
			bot[2]++;
			dfs(i,sum+a[i].y);	
			bot[2]--;
		}
		if(bot[3]+1<=n/2){
			vis[i]=3;
			bot[3]++;
			dfs(i,sum+a[i].z);	
			bot[3]--;
		}
		vis[i]=0;
	}
}

void solve1(){
	dfs(0,0);
	cout<<ans<<'\n'; 
} 
void solve2(){
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;i++) ans+=a[i].x;
	cout<<ans<<'\n';
}
void solve3(){
	ll sum=0;
	for(int i=1;i<=n;i++) sum+=a[i].x+a[i].y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/2;j++){
			for(int k=0;k<i;k++){
				if(f[k][j-1][1]+a[i].x>=f[i][j][1]){
					f[i][j][1]=max(f[i][j][1],f[k][j-1][1]+a[i].x);
					ff[i][j][1]=ff[k][j-1][1]+a[i].y;
				}
				if(f[k][j-1][2]+a[i].x>=f[i][j][2]){
					f[i][j][2]=max(f[i][j][2],f[k][j-1][2]+a[i].y);
					ff[i][j][2]=ff[k][j-1][2]+a[i].x;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/2;j++){
			ans=max(ans,f[i][j][1]+(sum-ff[i][j][1]));
			ans=max(ans,f[i][j][2]+(sum-ff[i][j][2]));
		}
	}
	cout<<ans<<'\n';
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		if(n<=30) solve1();
		else if(check1()) solve2();
		else if(check2()) solve3();
	}
	return 0;
}
