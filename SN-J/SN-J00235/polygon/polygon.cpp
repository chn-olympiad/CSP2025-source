#include <bits/stdc++.h>
using namespace std;
int n,ans = 0;
int a[10000010];
bool cmp(int a1, int a2){
	return a1 > a2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
//	for (int i = 1; i <= n; i++){
//		
//	}
	cout << ans % 998244353;
	return 0;
}

