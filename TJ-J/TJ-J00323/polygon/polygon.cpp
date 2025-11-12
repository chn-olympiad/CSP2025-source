#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	int n,count = 0,a[5002] = {};
	cin >> n;

	
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	for(int i = 1;i <= n;i++){
		for (int j = i;i <= n;j++){
			for (int k = j;k <= n;k++){
				if((a[i] + a[j] + a[k] + 1) / 2 > max(a[i],a[j],a[k])){
					count ++;
				}
			}
		}
	}
	cout << count;
	return 0;
}
