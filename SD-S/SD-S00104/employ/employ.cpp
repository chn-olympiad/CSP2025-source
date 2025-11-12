#include<bits/stdc++.h>
using namespace std;

//#define int long long
const int N = 50005;
long long jiecheng(long long n){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans *= i;
		ans %= 998244353;
	}
	return ans;
}

int n ,m ,a[N] ;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << jiecheng(n) << "\n";
	return 0;
}


