#include<bits/stdc++.h>

#define int long long

#define maxn 100005

#define INF (int)(1e18)

#define double long double

using namespace std;

int T;

int n;

int tong[3];

struct node{
	
	int num,id;
	
}a[maxn][3];

bool cmp(node a,node b){
	
	return a.num > b.num;
	
}

vector<int> z;

void solve(){
	
	z.clear();
	
	int ans = 0;
	
	tong[0] = tong[1] = tong[2] = 0;
	
	cin >> n;
	
	for(int i = 1;i <= n;++ i){
		
		for(int j = 0;j <= 2;++ j){
			
			cin >> a[i][j].num;
			
			a[i][j].id = j;
			
		}
		
		sort(a[i],a[i] + 3,cmp);
		
		tong[a[i][0].id] ++;
		
		ans += a[i][0].num;
		
	}
	
	int lim = -1;
	
	if(tong[0] > n / 2) lim = 0;
	
	if(tong[1] > n / 2) lim = 1;
	
	if(tong[2] > n / 2) lim = 2;
	
	if(lim == -1){
		
		cout << ans << "\n";
		
		return ;
		
	}
	
	for(int i = 1;i <= n;++ i){
		
		if(a[i][0].id == lim){
			
			z.push_back(a[i][0].num - a[i][1].num);
			
		}
		
	}
	
	sort(z.begin(),z.end());
	
	int opt = tong[lim] - n / 2;
	
	for(int i = 0;i <= opt - 1;++ i){
		
		ans -= z[i];
		
	}
	
	cout << ans << "\n";
	
}

signed main(){

	ios::sync_with_stdio(0);
	
	cin.tie(0);
	
	cout.tie(0);
	
	freopen("club.in","r",stdin);
	
	freopen("club.out","w",stdout);
	
	cin >> T;
	
	while(T --) solve();
	
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
