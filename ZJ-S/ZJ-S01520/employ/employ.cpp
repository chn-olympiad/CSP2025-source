#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int ans = 0;
string s;
int c[505];
int dp[505][505][505];
bool vis[505];
int n , m;
queue<int>q;
void check(){
	int shi = 0 , lu = 0;
	int dang = -1;
	queue<int>qq;
	qq = q;
//	cout << "wssb" << endl;
	while(!qq.empty()){
	//	cout << "xr" << endl; 
		int now = qq.front();
//		cout << now << " " << endl; 
		qq.pop();
		dang++;
		if(shi >= c[now]){
			shi++;
			continue;
		}
		if(s[dang] == '0'){
			shi += 1;
			continue;
		}
		if(shi > n - m){
			break;
		}
		lu++;
	}
	if(lu >= m) ans++;
	ans %= mod;
	return ;
}
void dg(int now){
	if(now == n + 1){
	//	cout << "!!!" << endl;
		check();
	//	q.pop();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = true;
			q.push(i);
			dg(now + 1);
			vis[i] = false;
			q.pop();
		}
	}
//	if(now == n) dg(now + 1);
	return ;
}

signed main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	
	cin >> n >> m;
	if(n == m){
		int p = 2;
		int num = 1;
		int b = n;
		while(b){
			if(b % 2 == 1){
				num = num % mod * p % mod;
				b--; 
			}
			p = p % mod * p % mod;
			b /= 2;
		}
		num %= mod;
		cout << num << endl;
	}else{
		bool flag = true;
		cin >> s;
		int len = s.size();
		for(int i=0;i<len;i++){
			if(s[i] == '0'){
				flag = false;
			}
		}
		if(flag){
			int p = 2;
			int num = 1;
			int b = n;
			while(b){
				if(b % 2 == 1){
					num = num % mod * p % mod;
					b--; 
				}
				p = p % mod * p % mod;
				b /= 2;
			}
			num %= mod;
			cout << num << endl;
		}else{
			for(int i=1;i<=n;i++){
				cin >> c[i];
			}
			dg(1);
			cout << ans << endl;
		}
	}
}
