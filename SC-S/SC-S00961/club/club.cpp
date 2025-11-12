#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n;
int c1[N]={},c2[N]={},c3[N]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		int ans = 0;
		for(int j=0;j<n;j++){
			cin >> c1[j] >> c2[j] >> c3[j];
			ans += max(max(c1[j],c2[j]),c3[j]);
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}