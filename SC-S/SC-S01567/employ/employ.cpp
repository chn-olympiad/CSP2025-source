#include<bits/stdc++.h>
using namespace std;
const int N = 505; 
const long long mod = 998244353;
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n,m,flag=0,ans=1;
	cin >> n >> m;
	int base = n, res = 0;
	string s;
	cin >> s;
	long long c[N]={};
	for(int i=0;i<n;i++){
		if(s[i]=='0') flag =1;
		cin >> c[i];
		if(c[i]==0)base--;
		
		
	}
	sort(c,c+n);
//	cout << base << endl;
//	for(int i=base;i<n;i++){
//		cout << c[i] << " ";
//	}
	if(base<m) {cout << 0;return 0;}
	else{
		for(int i=m;i<=base;i++){
			ans= (ans*i)%mod;
		}
		cout << ans;
	}
	return 0;
}

