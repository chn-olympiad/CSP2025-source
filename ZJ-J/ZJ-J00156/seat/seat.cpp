#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	for(int i = 2;i <= n*m;i++){
		scanf("%d",&a[i]);
		if(a[i] > a[1]) sum++;
	}
	cout << ceil(sum*1.0/n) << " ";
	if(sum % n != 0) cout << sum%n;
	else cout << n;
	return 0;
}