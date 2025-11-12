#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans,sum1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i < n;i++){
		sum1 += a[i];
	}
	if(sum1 <= a[n]){
		cout << 0;
		return 0;
	}
	ans++;
	printf("%d",ans);
	return 0;
}
// vara help me
// this ccf is ssb
// can i 1=
// no!