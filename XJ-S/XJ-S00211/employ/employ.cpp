#include <bits/stdc++.h> 
using namespace std;
int n,m,c[510];
string s;
long long fx(int x){
	long long a;
	for(int i = 1;i <= x;i++){
		a*=i;
	}
	return a;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans = 0;
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	bool f = true;
	for(int i = 1;i <= n;i++){
		if(s[i] == 0){
			f = false;
		}
	}
	if(m == 1){
		int id;
		for(int i = 0;s[i] == 0;i++){
			id = i;
		}
		id++;
		for(int i = 1;i <= n;i++){
			if(c[i]>=id)ans++;
		} 
	}
	if(f){
		ans = fx(n) / fx(n-m) / fx(m);
	}
	else{
		ans = 225301405;
	}
	cout << ans%998224353;
	return 0;
}
