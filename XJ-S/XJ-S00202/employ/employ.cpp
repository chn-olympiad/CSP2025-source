#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum1=1,sum2=1,sum3=1;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) sum1=sum1*i%MOD;
	for(int i = 1; i <= n; i++) sum2=sum2*i%MOD;
	for(int i = 1; i <= n-m; i++) sum3=sum3*i%MOD;
	cout << (sum1/sum2/sum3)%MOD;
	return 0;
} 
