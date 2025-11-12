#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t,n,ans,sum;
struct node{
	int a,b,c;
}d[N];
bool cmp(node i,node j){return i.a > j.a;}
bool flag;
void dfs(int x,int s1,int s2,int s3,int cnt){
	if(x > n && s1 <= n / 2 && s2 <= n / 2 && s3 <= n / 2){
		ans = max(ans,cnt);
		return;
	}
	if(s1 > n / 2 || s2 > n / 2 || s3 > n / 2)return;
	dfs(x + 1,s1 + 1,s2,s3,cnt + d[x].a);
	dfs(x + 1,s1,s2 + 1,s3,cnt + d[x].b);
	dfs(x + 1,s1,s2,s3 + 1,cnt + d[x].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		ans = sum = 0;
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> d[i].a >> d[i].b >> d[i].c;
			if(d[i].b != 0 || d[i].c != 0)flag = true;
		}
		if(!flag){
			sort(d + 1,d + n + 1,cmp);
			for(int i = 1; i <= n / 2; ++i)sum += d[i].a;
			cout << sum << '\n';
			continue;
		}
		dfs(1,0,0,0,0);
		cout << ans << '\n';
	}
	return 0;
}