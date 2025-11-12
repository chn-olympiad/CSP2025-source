#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int c[maxn];
long long ans, tot;
int n, m;
int cnt;
bool v[maxn];
string s;
void dfs(int k, int day){
	//cout << tot << " " << day << endl;
	//if(tot == m) cout << "m" << endl;
	if(tot == m){
		//cout << "d" << endl;
		ans = ans%998;
		ans %= 244;
		ans %= 353;
		ans++;
		return;
	}
	if(k > n) return;
	for(int i = k; i < n; i++){
		if(v[i]){
			if(c[i] <= cnt){
				v[i] = 0;
				//cout << day << endl;
			}
		}
	}
	/*
	if(!v[k]){
		cout << "j" << day << endl; return;
	}
	*/
	if(c[k] == 0) return;

	//int sum = 0;
	/*
	if(!s[day]){
		cnt++;
		return;
	}
	*/
	for(int i = 0; i < n; i++){
		if(!v[i]) continue;
		if(s[day] == '0'){
			//cout << 0 << endl;
			cnt++;
			v[i] = 0;
			dfs(i+1, day+1);
			v[i] = 1;
			cnt--;
		}else{
			//cout << 1 <<endl;
			v[i] = 0;
			tot++;
			dfs(i+1, day+1);
			v[i] = 1;
			tot--;
			/*
			if(cnt < c[k]){
				tot++;
				dfs(i, day+1);
			}else{
				cnt++;
				dfs(i, day+1);
			}
			*/
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n; i++){
		cin >> c[i];
		v[i] = 1;
	}
	sort(c, c+n);
	dfs(0, 0);
	cout << ans;
	return 0;
}
