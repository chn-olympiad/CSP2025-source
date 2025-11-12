#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long now_most,n,ans = -1;
struct node{
	int x,y,z;
}a[N];
void dfs(int depth,long long now,int cnt1,int cnt2,int cnt3){
	if (depth>n){
		ans=max(now,ans);
		return;
	}
	if (cnt1<now_most){
		dfs(depth+1,now+a[depth].x,cnt1+1,cnt2,cnt3);
	}
	if (cnt2<now_most){
		dfs(depth+1,now+a[depth].y,cnt1,cnt2+1,cnt3);
	}
	if (cnt3<now_most){
		dfs(depth+1,now+a[depth].z,cnt1,cnt2,cnt3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		now_most=n/2;
		for (int i = 1; i<=n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
		dfs(1,0,0,0,0);
		cout << ans << endl;
		ans=-1;
	}
	return 0;
} 
