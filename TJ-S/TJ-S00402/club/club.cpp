#include <bits/stdc++.h>
using namespace std;
int t,n,a1[100005],f,cnt = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		for(int j = 1;j <= n;j++) cin >> a1[j] >> f >> f;
		sort(a1 + 1,a1 + 1 + n);
		cnt = 0;
		for(int j = n;j >  n / 2;j--) cnt += a1[j];
		cout << cnt << endl;
	}
	return 0;
} 
