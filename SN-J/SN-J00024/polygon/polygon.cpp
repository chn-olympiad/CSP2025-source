#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n, a[N], b[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	if(n == 3){
		if(a[1] + a[2] + a[3] > max(a[1],max(a[2],a[3]))){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	
	int ans = 0;
	sort(b+1,b+n+1);
	int maxa = b[n];
	if(maxa == 1){
		for(int i = 3; i <= n; i++){
			for(int j = 1; j <= n-i+1; j++){
				ans += j;
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

