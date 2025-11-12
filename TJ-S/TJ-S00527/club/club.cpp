#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][100005],b[3],ans;
bool flag_a=true,flag_b=true;
bool cmp(int a,int b) {
	return a>b;
}
void dfs(int x,int sum) {
	if(x>n) {
		ans=max(ans,sum);
		return;
	}
 	for(int i=0;i<3;i++) {
 		if(b[i]>=n/2) continue;
 		b[i]++;
 		dfs(x+1,sum+a[i][x]);
 		b[i]--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>t;
	for(int z=1;z<=t;z++) {
		ans=0;
		for(int i=0;i<3;i++) b[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			if(a[1][i]!=0) flag_a=false;
			if(a[2][i]!=0) flag_b=false;
		}
		if(flag_a&&flag_b) {
			sort(a[0]+1,a[0]+n+1,cmp);
			for(int i=1;i<=n/2;i++) {
				ans+=a[0][i];
			}
		}
		else dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
