// in memory of wowaka
#include<bits/stdc++.h>
#define fo(i , x , y) for(int i = x ; i <= y ; i++)
#define go(i , x , y) for(int i = x ; i >= y ; i--)
using namespace std;
const int maxn = 100005;
int T , n;
struct node{
	int x , y , z;
}a[maxn];
vector<int> in[4];
int cal(vector<int>& q){
	sort(q.begin() , q.end());
	int ans = 0 , del = q.size() - n / 2;
	for(int x : q){
		ans += x;
		del--;
		if(del == 0) break;
	}
	return ans;
}
void solve(){
	cin >> n;
	fo(i , 1 , n)
		cin >> a[i].x >> a[i].y >> a[i].z;
	int ans = 0;
	fo(i , 1 , 3)
		in[i].clear();
	fo(i , 1 , n){
		if(a[i].x > a[i].y and a[i].x > a[i].z){
			ans += a[i].x;
			in[1].push_back(min(a[i].x - a[i].y , a[i].x - a[i].z));
		}
		else if(a[i].y > a[i].z){
			ans += a[i].y;
			in[2].push_back(min(a[i].y - a[i].x , a[i].y - a[i].z));
		}
		else{
			ans += a[i].z;
			in[3].push_back(min(a[i].z - a[i].y , a[i].z - a[i].x));
		}
	}
	fo(i , 1 , 3){
		if((int)in[i].size() <= n / 2) continue;
		ans -= cal(in[i]);
		break;
	}
	cout << ans << '\n';
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> T;
	while(T--) solve();
}
