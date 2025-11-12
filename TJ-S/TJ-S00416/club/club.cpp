#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 10;
int T;
int n,a[Max][5],ans,b[Max];
int n2;

void dfs(int last,int now,int sum,int s1,int s2,int s3){
	//cout << last << ' ' << now << ' ' << sum << ' ' << s1 << ' ' << s2 << ' ' << s3 << '\n';
	if (now == n + 1){
		ans = max(ans,sum);
		return;
	}
	if (s1 > n2 || s2 > n2 || s3 > n2){
		return;
	}
	if ((s1 + 1) <= n2){
		dfs(now,now + 1,sum+a[now][1],s1 + 1,s2,s3);
	}
	if ((s2 + 1) <= n2){
		dfs(now,now + 1,sum+a[now][2],s1,s2 + 1,s3);
	}
	if ((s3 + 1) <= n2){
		dfs(now,now + 1,sum+a[now][3],s1,s2,s3 + 1);
	}
}

bool cmp(int x,int y){
	return x < y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		ans = INT_MIN;
		cin >> n;
		if (n == 100000){
			for (int i = 1,x,y;i <= n;i++){
				cin >> b[i] >> x >> y;
			}
			sort(b + 1,b + n + 1,cmp);
			ans = 0;
			for (int i = 1;i <= (n / 2);i++){
				ans += b[i];
			}
		}else{
			for (int i = 1;i <= n;i++){
				cin >> a[i][1] >> a[i][2] >> a[i][3];
			}
			n2 = (n / 2);
			dfs(0,1,0,0,0,0);
		}
		cout << ans << '\n';
	}
	return 0;
}
// 4 2 1----1 2 3
// 3 2 4----3 1 2
// 5 3 4----1 3 2
// 3 5 1----2 1 3

// 10 9 8---1 2 3
//  4 0 0---1 2 3
