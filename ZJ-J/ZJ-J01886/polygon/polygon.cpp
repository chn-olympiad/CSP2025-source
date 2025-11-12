#include <bits/stdc++.h>
using namespace std;
int n, a[5050];
int max1 = 0;
long long sum = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum+=a[i];
		max1 = max(max1,a[i]);
	}
	if(n == 3){
		if(sum > 2 * max1){
			cout << 1;
		}
		else cout << 0;
	}
	else if(n == 4){
		int cnt = 0;
		int max2 = max(a[1],max(a[2],a[3]));
		if((sum - a[4]) > 2 * max2) cnt++;
		int max3 = max(a[1],max(a[2],a[4]));
		if((sum - a[3]) > 2 * max3) cnt++; 
		int max4 = max(a[1],max(a[4],a[3])); 
		if((sum - a[2]) > 2 * max4) cnt++;
		int max5 = max(a[4],max(a[2],a[3])); 
		if((sum - a[1]) > 2 * max5) cnt++;
		if(sum > 2 * max1) cnt++;
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


