#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace wjx{

int T_T = 1;
int n,m;
struct node{
	int val,id;
}a[105];
bool vis[15][15];
bool cmp(node a,node b){
	return a.val > b.val;
}
int x,y;
void FRE(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void get(){
	cin >> n >> m;
	for (int i = 1;i <= n * m;++i){
		cin >> a[i].val;
		a[i].id = i;
	}
	
}

void solve(){
	sort(a + 1,a + n*m + 1,cmp);
	x = 1;y = 1;
	for (int i = 1;i <= n * m;++i){
		if (a[i].id == 1){
			cout << x << ' ' << y << "\n";
		}
		vis[x][y] = true;
		if (y < n && !vis[x][y + 1]) ++y;
		else if (y > 1 && !vis[x][y - 1]) --y;
		else ++x;
	}
}

signed main(){
//	cin >> T_T;
	while (T_T--){
		wjx::get();
		wjx::solve();
	}
	return 0;
}

}

signed main(){
//	wjx::IOS();
	wjx::FRE();
	return wjx::main();
}
/*
rp++
*/

