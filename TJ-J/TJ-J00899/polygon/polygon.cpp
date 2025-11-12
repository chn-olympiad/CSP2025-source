#include<bits/stdc++.h>
using namespace std;
#define int long long
const int K = 998244353;
int a[5010];
int vis[30];
int n;
vector<int> vec;
map<int ,int> mp;
int ans;
int cal(int a){
	int t = 1;
	for(int i = 1; i <= a; i++){
		t *= i;
	}
	return t;
}
void dfs(int x){
	if(x > n){
		if(vec.size() < 3) return ;
		long long f = 0;
		for(auto v : vec){
			f = f * 10 + v;
		} 
		if(mp.find(f)!=mp.end()){
			;
		}else{
			int M = 0, sum = 0;
			 
			for(auto v : vec){
				M = max(M,a[v]);
				sum += a[v];
			} 
				
				mp[f] = 1;
				if(sum > M * 2) ans++;
		}
	
		return ;
	}
	
	for(int i = x ; i <= n; i++){
		dfs(i + 1);
		if(vis[i] == 0){
			vis[i] = 1;
			vec.push_back(i);
			dfs(i + 1);
			vec.pop_back();
			vis[i] = 0;
		}
	}
	return ;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	int mm = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mm = max(a[i],mm);
	}
	if(n <3 ){
		cout << 0;
		return 0;
	} 
	if(n == 3){
		int sum  = a[1] + a[2] + a[3];
		if(sum > 2 * mm) cout << 1;
		else cout << 0;
		return 0;
	}
	
	
	if(mm == 1){
		
		for(int i = 3; i <= n; i++){
			ans = (ans + cal(n)/cal(i)/cal(n-i)) % K;
		}
		cout << ans;
		return 0;
	}
	
	sort(a + 1, a +1+n);
	
	dfs(1);
	cout << ans;
	return 0;
} 
