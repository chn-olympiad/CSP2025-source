#include <iostream>
#include <algorithm>
using namespace std;
int t,n,anss;
struct Person{
	int id,score;
};
bool cmp(Person a,Person b){
	return a.score > b.score;
}
Person a[100005][3];

void dfs(int x,int cnt[3],int ans){
	if (x == n+1){
		anss = max(ans,anss);
		return;
	}
	
	for (int i = 1;i<=3;i++){
		if (cnt[i-1] + 1 > n/2) continue;
		cnt[i-1]++;
		ans += a[x][i].score;
		dfs(x+1,cnt,ans);
		cnt[i-1]--;
		ans -= a[x][i].score;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	
	while (t--){
		anss = -1e5; 
		cin >> n;
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=3;j++){
				cin >> a[i][j].score;
				a[i][j].id = j;
			}
		}
		int cnt[3] = {0,0,0};
		dfs(1,cnt,0);
		cout << anss << endl;
	}
}