#include<bits/stdc++.h>
using namespace std;
long long t;
struct node{
	int o,p,q,w;
}a[100010];
bool cmp(node & x, node & y){
	return x.w > y.w;
}
void solve(){
	long long ans = 0;
	int n , s[10];
	vector<node> v1, v2, v3;
	cin >> n;
	for (int i = 1; i <= n ; i++){
		cin >> a[i].o >> a[i].p >> a[i].q;
		s[1] = a[i].o , s[2] = a[i].p , s[3] = a[i].q;
		sort(s + 1, s + 4);
		a[i].w = s[3] - s[2];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n ; i++){
		s[1] = a[i].o , s[2] = a[i].p , s[3] = a[i].q;
		sort(s + 1, s + 4);
		a[i].w = s[3] - s[2];
		if(s[3] == a[i].q) v3.push_back(a[i]);
		else if(s[3] == a[i].p) v2.push_back(a[i]);
		else if(s[3] == a[i].o) v1.push_back(a[i]);
	}
	for (int i = 0; i < v1.size() ; i++){
		if(i + 1 > n/2){
			ans -= v1[i].w;
		}
		ans += v1[i].o;
	}
	for (int i = 0; i < v2.size() ; i++){
		if(i + 1 > n/2){
			v2[i].p -= v2[i].w;
		}
		ans += v2[i].p;
	}
	for (int i = 0; i < v3.size() ; i++){
		if(i + 1 > n/2){
			ans -= v3[i].w;
		}
		ans += v3[i].q;
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) solve();
	return 0;
}

