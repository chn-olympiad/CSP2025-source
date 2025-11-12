#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,y=998244353;
	cin >> n >> m;
	int s[n];
	string c;
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	cin >> c;
	long long ans;
	for (int i=0;i<n;i++){
		ans*s[i];
		ans%y;
	}
	for (int i=0;i<n;i++){
		(ans+y)/c[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}