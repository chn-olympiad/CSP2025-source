#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	if (n<3) cout << 0;
	if (sum==n) cout << n-2;
	fclose(stdin);fclose(stdout);
	return 0;
}
