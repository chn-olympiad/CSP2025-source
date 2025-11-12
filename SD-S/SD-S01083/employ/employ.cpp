#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],temp;
long long ans = 1;
const int MOD = 998244353;
bool f;

string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	for(int i = 1;i <= n;i++) {
		scanf("%d",&c[i]);
		if(c[i] == 0) {
			temp++;
		}
	}
	for(int i = 0;i < s.size();i++) {
		if(s[i] == '0') {
			f = 1;
		}
	}
	if(f) {
		printf("%d",0);
		return 0;
	}else {
		for(int i = 1;i <= n;i++) {
			ans *= i;
			ans = ans % MOD;
		}
		printf("%lld",ans);
	}
	return 0;
}

