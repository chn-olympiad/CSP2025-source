#include <bits/stdc++.h>
using namespace std;
const int N = 500+10;
long long ans = 1;
int n,m;
string s;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n;
	for (int i = 2; i<=n; i++){
		ans=ans*i;
	}
	cout << ans;
	return 0;
}
