#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+10;

int T,n;
int a[N][4];

int dfs(int idx,int aa,int bb,int cc){
	if(idx==n+1) return 0;
	if(aa+1>n/2) return max(a[idx][2]+dfs(idx+1,aa,bb+1,cc),a[idx][cc]+dfs(idx+1,aa,bb,cc+1));
	if(bb+1>n/2) return max(a[idx][1]+dfs(idx+1,aa+1,bb,cc),a[idx][cc]+dfs(idx+1,aa,bb,cc+1));
	if(cc+1>n/2) return max(a[idx][1]+dfs(idx+1,aa+1,bb,cc),a[idx][bb]+dfs(idx+1,aa,bb+1,cc));
	return max(a[idx][1]+dfs(idx+1,aa+1,bb,cc),max(a[idx][2]+dfs(idx+1,aa,bb+1,cc),a[idx][3]+dfs(idx+1,aa,bb,cc+1)));
}

int dfs_2(int idx,int aa,int bb){
	if(idx==n+1) return 0;
	if(aa+1>n/2) return a[idx][2]+dfs_2(idx+1,aa,bb+1);
	if(bb+1>n/2) return a[idx][1]+dfs_2(idx+1,aa+1,bb);
	return max(a[idx][1]+dfs_2(idx+1,aa+1,bb),a[idx][2]+dfs_2(idx+1,aa,bb+1));
}

void solve(){
	int ans=0,cnt_0=0,cnt_1=0; cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]==0&&a[i][3]==0) cnt_0+=2;
		if(a[i][3]==0) cnt_1++;
	}
	if(cnt_0==n*2){
		int p[N];
		for(int i=1;i<=n;i++) p[i]=a[i][1];
		sort(p+1,p+1+n);
		for(int i=n;i>=n/2;i--){
			ans+=p[i];
		}
		cout<<ans<<"\n";
		return;
	}
	else if(cnt_1==n){
		cout<<dfs_2(1,0,0)<<"\n";
		return;
	}
	cout<<dfs(1,0,0,0)<<"\n";
	return;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
