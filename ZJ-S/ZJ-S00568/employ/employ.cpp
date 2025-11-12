#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >>m;
	if(m==0){
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
		cout << ans;
	}else cout << 0;
	return 0;
}