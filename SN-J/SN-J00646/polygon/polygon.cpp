#include <bits/stdc++.h>
using namespace std;
int n, ans, a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 3;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			int maxx = -1;
			int anss = 0;
			for(int k = j;k <= (j + i);k ++){
				anss += a[k];
				if(a[k] > maxx){
					maxx = a[k];
				}
			}
			if(anss > maxx * 2){
				ans ++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
