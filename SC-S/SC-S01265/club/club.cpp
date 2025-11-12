#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N],b[N],c[N];
int n;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1,a + n + 1,cmp);
		for(int i = 1;i <= n/2;i++) ans += a[i];
		cout << ans << endl;
	}
	return 0;
}