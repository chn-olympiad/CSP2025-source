#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[510];
int n;
string s;
int m;
long long ans;
int cnt;
const int K = 998244353;
int  cal(int n){
int  t = 1;
	
	for(int i = 1; i <= n; i++){
		t = t * i % K; 
	}
	
	return t; 
	
}

signed main(){
	
	

	freopen("employ.in","r",stdin);
	
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	
	cin >> s;

	cout << cal(n) ;
	
	return 0;
} 
