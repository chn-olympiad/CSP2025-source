#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
const int p = 998244353;
long long f(int x){
	long long res = 1;
	for(long long i = 1;i <= x;i++) res = (res*i)%p;
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 0) cnt++;
	}
	if(n-cnt < m) cout << 0;
	else cout << (1ll*f(cnt)*f(n-cnt))%p;
	return 0;
}
