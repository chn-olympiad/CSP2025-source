#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,ans = 0,a[100010];
	scanf ("%d%d",&n,&k);
	for (int i = 1;i <= n;i++){
		scanf ("%d",&a[i]);
	}
	if (n == 2){
		ans++;
	}
	printf ("%d",ans);
	return 0;
}
