#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t , n , a , b , c , cnt[3] , sum , k;
pair<int , int> club[100005][3] , d[100005];
bool f[100005];
void cal(int k , int a , int b , int c){
	if  (a >= b && b >= c) club[k][0] = {a , 1} , club[k][1] = {b , 2} , club[k][2] = {c , 3};
	else if  (a >= c && c >= b) club[k][0] = {a , 1} , club[k][1] = {c , 3} , club[k][2] = {b , 2};
	else if  (b >= a && a >= c) club[k][0] = {b , 2} , club[k][1] = {a , 1} , club[k][2] = {c , 3};
	else if  (b >= c && c >= a) club[k][0] = {b , 2} , club[k][1] = {c , 3} , club[k][2] = {a , 1};
	else if  (c >= a && a >= b) club[k][0] = {c , 3} , club[k][1] = {a , 1} , club[k][2] = {b , 2};
	else if  (c >= b && b >= a) club[k][0] = {c , 3} , club[k][1] = {b , 2} , club[k][2] = {a , 1};
	d[k] = {club[k][0].first - club[k][1].first , k};
}
bool cmp(pair<int , int> a , pair<int , int> b)
{
	if  (f[a.second] != f[b.second]) return f[a.second];
	return a.first < b.first;
}
void solve(){
	cnt[0] = cnt[1] = cnt[2] = sum = k = 0;
	memset(club , 0 , sizeof(club));
	memset(d , 0 , sizeof(d));
	memset(f , 0 , sizeof(f));
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> a >> b >> c;
		cal(i , a , b , c);
	}
	for (int i = 1;i <= n;i ++)
	{
		++ cnt[club[i][0].second - 1];
		sum += club[i][0].first;
	}
	if  (cnt[0] > n / 2) k = 1;
	else if  (cnt[1] > n / 2) k = 2;
	else if  (cnt[2] > n / 2) k = 3;
	else{
		cout << sum << "\n";
		return;
	}
	for (int i = 1;i <= n;i ++)
	{
		if  (club[i][0].second == k) f[i] = 1;
	}
	sort(d + 1 , d + 1 + n , cmp);
	for (int i = 1;i <= cnt[k - 1] - n / 2;i ++) sum -= d[i].first;
	cout << sum << "\n";
}  
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t --) solve();
	return 0;
} 
