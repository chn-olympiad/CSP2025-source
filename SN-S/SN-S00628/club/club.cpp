#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int t, n, cnt[4];
long ans;

struct stu{
	long a1, a2, a3;
}a[N];


bool cmp(stu s1, stu s2){
	return s1.a1 > s2.a1;

void dfs(int x, long t){
	if(x > n){
		ans = max(ans, t);
	}
	if(cnt[1] < n / 2){
		cnt[1]++;
		dfs(x + 1, t + a[x].a1);
		cnt[1]--;
	}
	if(cnt[2] < n / 2){
		cnt[2]++;
		dfs(x + 1, t + a[x].a2);
		cnt[2]--;
	}
	if(cnt[3] < n / 2){
		cnt[3]++;
		dfs(x + 1, t + a[x].a3); 
		cnt[3]--;
	}
	return;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		memset(a, 0, sizeof(a));
		ans = 0;
		for(int i = 1; i <= n; i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		if(n <= 30){
			dfs(1, 0);
			cout<<ans<<endl;
			continue;
		}
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n / 2; i++){
			ans += a[i].a1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
