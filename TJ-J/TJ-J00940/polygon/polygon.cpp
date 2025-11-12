#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,sum = 0,cnt = 0,maxx = 0;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);
	int l = 0;
	for (int i = 3;i<n;i++){
		sum = 0;
		for (int j = l++;j<i;j++){
			sum	+= a[j];
			if (a[j]>=maxx) maxx = a[j];
			if (sum >= maxx) {
				cnt++;
			}
		}
	}
	cout << cnt;//¿ÉÁ¯¿ÉÁ¯º¢×Ó°É~please>= 
	return 0;
}

