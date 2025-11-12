#include <bits/stdc++.h>
using namespace std;
int n,a,s;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans = 0;
	cin >> n >> a >> s;
	if(n + a + s >= 3){
		cout << "1";
	}
	return 0;
}
