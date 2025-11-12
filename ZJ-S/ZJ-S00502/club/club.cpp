#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t,n,a[N],b[N],c[N],maxx;
void dfs(int k,int cnt_a,int cnt_b,int cnt_c,int sum){
	if(k > n){
		maxx = max(maxx,sum);
		return ;
	}
	if(cnt_a < n/2){
		dfs(k+1,cnt_a+1,cnt_b,cnt_c,sum +a[k]);
	}
	if(cnt_b < n/2){
		dfs(k+1,cnt_a,cnt_b+1,cnt_c,sum +b[k]);
	}
	if(cnt_c < n/2){
		dfs(k+1,cnt_a,cnt_b,cnt_c+1,sum +c[k]);
	}
}
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		maxx = -1e9;
		dfs(1,0,0,0,0);
		cout << maxx << endl;
	}
	return 0;
}