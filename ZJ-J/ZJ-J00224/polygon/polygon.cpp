//Maybe we can sort it?
//Let's make a force soltion again.
//I know it not a right soltion.When n only 500,this code was TLE.
//Now is 10 o'clock.To exam finish still have 2 hours.I can't fix this code.I'm very bored.
//10:18 I'm trying a new soltion now.
//11:04 I'm very happy now.Because maybe I can AK CSP-J 2025!
//Now,I hope problem3 won't TLE.

/*Wrong soltion
#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n;
int a[5003];
int ans;
int solve(int id,int k){//In [1,id - 1],how much choise can make they sum bigger than k?
	if(k < 0) return (1 << (id - 1)) % mod;//Attention:problem say a[i] > 0
	if(id == 1) return 0;
	int sum = 0;
	sum += solve(id - 1,k);//Don't choose a[id - 1]
	sum %= mod;
	sum += solve(id - 1,k - a[id - 1]);//Choose a[id - 1]
	sum %= mod;
	return sum;
}

int main(){
	ifstream cin("polygon.in");
	ofstream cout("polygon.out");
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		ans += solve(i,a[i]);
		ans %= mod;
	}
	cout<<ans;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n;
int a[5003];
int dp[5003][5003];
int _2[5003];
int mx;
int ans;

int get(int i,int j){
	if(i == 0) return 0;
	if(j < 0) return _2[i] % mod;
	return dp[i][j];
}

int main(){
	ifstream cin("polygon.in");
	ofstream cout("polygon.out");
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		mx = max(mx,a[i]);
	}
	_2[0] = 1;
	for(int i = 1;i <= n;i++){
		_2[i] = _2[i - 1] * 2;
		_2[i] %= mod;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= mx;j++){
			if(j == 0) dp[i][j] = _2[i] - 1;
			else if(i == 1){
				dp[i][j] = a[i] > j;
			}else{
				dp[i][j] += get(i - 1,j) + get(i - 1,j - a[i]);
				dp[i][j] %= mod;
			}
//			cout<<dp[i][j]<<" ";
		}
//		cout<<"\n";
	}
	for(int i = 1;i <= n;i++){
		ans += dp[i - 1][a[i]];
		ans %= mod;
	}
	cout<<ans;
	return 0;
}
