#include<bits/stdc++.h>
using namespace std;
string s;
int c[520];
int p[520];
int b[520];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	cin >> n >> m;
	cin >> s;
	
	for(int i=1;i<=n;i++){
		cin >> c[i];
		p[i]=i;
	}
	int ans = 0;
	if(m != n) 
	{
	do{
		int nowLeft = 0;
		int sk = 0;
		for(int i=1;i<=n;i++){
			int j = p[i];
			if(nowLeft >= c[j] || s[i-1] == '0') nowLeft++;
			else sk++;
			if(n-i+sk < m) break;
			if(sk >= m) break;
		}
		if(sk >= m) ++ans;
	}while(next_permutation(p+1, p+n+1));
	cout << ans << endl;
}
else{
	long long ans = 1;
	for(int i=0;i<n;i++){
		ans *= i+1;
		ans %= 998244353;
		if(s[i] == '0') {
			cout << 0 << endl;
			return 0;
		}
		if(c[i+1] == 0){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}
return 0;
}
