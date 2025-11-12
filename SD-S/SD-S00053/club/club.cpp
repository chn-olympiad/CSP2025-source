#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int a[100010] = {0};
int s[100010] = {0};
bool cmp(int p,int q){
	return p > q;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		for(int j = 0;j < n;j++){
			int b,c;
			cin >> a[j] >> b >> c;
		}
		sort(a,a+n);
		/*for(int j = 1;j <= n;j++){
			for(int k = 1;k <= i;k++){
				int t = a[j];
				if(a[j+1] > a[j]){
					a[j] = a[j+1];
					a[j+1] = t;
				}
			}
		}*/
		s[i] += a[n-1];
		s[i] += a[n-2];
	}
	for(int i = 1;i <= t;i++){
		cout << s[i] << endl;
	}
	return 0;
}

