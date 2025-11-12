#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 105;
int n,m,c[N];
string s;
ll ans;
vector<int>num;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	
	cin >> s;
	for(int i = 1;i <= n;i ++)cin >> c[i];
	for(int i = 1;i <= n;i ++){
		num.push_back(i);
	}
	
	
	do{
	   int tmp = 0,cnt = 0; 
	   for(int i = 0;i < num.size();i ++){
			int p = num[i];
			if(tmp >= c[p] || s[i] == '0')tmp ++;
			else{
				cnt ++;
			}
	   }	
	   if(cnt >= m)ans ++;
		ans %= mod;
	}while(next_permutation(num.begin(),num.end()));
	
	cout << ans << "\n";
	
	
	
	
	return 0;
} 
