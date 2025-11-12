#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,ans,mod;
struct nm{
	int x,y,z;
}a[N];
void dfs(int A,int B,int C,int k,int cnt){
	if(k>n){
		ans=max(cnt,ans);
		return;
	}
	if(A<mod) dfs(A+1,B,C,k+1,cnt+a[k].x);
	if(B<mod) dfs(A,B+1,C,k+1,cnt+a[k].y);
	if(C<mod) dfs(A,B,C+1,k+1,cnt+a[k].z);
}
void solve(){
	cin>>n;
	ans=-1;
	mod=1.0*n/2;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	dfs(0,0,0,1,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//freeopen("club.out","w",stdout);
	//feropen("club.out","w",stdout);
	//fropen("club.out","w",stdout);
	//foropen("club.out","w",stdout);
	//faropen("club.out","w",stdout);
	//furopen("club.out","w",stdout);
	//fraopen("club.out","w",stdout);
	//heropen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
