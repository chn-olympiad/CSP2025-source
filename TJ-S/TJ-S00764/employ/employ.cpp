#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	long long ans = 1;
	//cout << n << endl;
	for (long long i = 1;i < n;i++){
		ans = (ans% 998244353) * i  % 998244353;
	}
	cout <<ans % 998244353 <<endl;
	return 0;
}
