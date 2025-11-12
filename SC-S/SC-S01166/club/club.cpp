#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans = 0,n;
vector<vector<int>> a;
void dfs(vector<int> cnt,int tot,int totCnt){
	if(cnt[1] > n/2 || cnt[2] > n/2 || cnt[3] > n/2) return;
	if(totCnt == n){
		ans = max(ans,tot);
		return;
	} 
//	if(totCnt >= ans) return;
	for(int i = 1;i<=3;i++){
		cnt[i]++,totCnt++;
		dfs(cnt,tot+a[totCnt][i],totCnt);
		cnt[i]--,totCnt--;
	}
}
void solve(){
	ans = 0;
	scanf("%lld",&n);
	if(n <= 35){
		a.assign(n+1,vector<int>(4));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		dfs({0,0,0,0},0,0);
		printf("%lld\n",ans);
	}
	else{
		vector<pair<int,int>> num(n+1);
		bool flag = true;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			num.emplace_back(a,b);
			if(b!=0) flag = false;
		}
//		if(flag){''
			sort(num.begin()+1,num.end(),greater<>());
			int ans = 0;
			for(int i=1;i<=n/2;i++){
				ans+=num[i].first;
			}
			printf("%lld\n",ans);
//		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}