#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
unsigned long long n,m,nx[1000],ans,d[15];
string nd;
bool flag = true,xg[15];
void dfs(int s){
	if(s == n+1){
		int cnt = 0,o = 0;
		for(int i = 1;i <= n;i++){
			if(nd[i-1] == '0')
				o++;
			else if(nx[d[i]] > o){
				cnt++;
			}
			else
				o++;	
		}
		if(cnt >= m){
//			cout << "ÇáËÉ" << '\n';
			ans++;
		}
			
	}
	for(int i = 1;i <= n;i++){
		if(!xg[i]){
			xg[i] = true;
			d[s] = i;
			dfs(s+1);
			xg[i] = false;
		}
	}
	return;
}
long long C(int x,int y){
	if(x > y)
		return 0;
	if(y/2 < x)
		x = y-x;
	unsigned __int128 sum = 1;
	for(int i = y;i >= y-x+1;i--){
		sum *= i;
		sum /= (y-i+1);
	}
	sum %= mod;
	return (long long)sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> nd;
	int pppp = 0;
	for(int i = 1;i <= n;i++){
		cin >> nx[i];
		if(nx[i] == 0)
			pppp++;
	}
	for(int i = 0;i < nd.size();i++)
		if(nd[i] != '1')
			flag = false;
	if(flag){
		for(int i = m;i <= n-pppp;i++)
			ans = (ans+C(i,n-pppp))%mod;
		cout << ans << '\n';
	}
	else if(n <= 10){
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
