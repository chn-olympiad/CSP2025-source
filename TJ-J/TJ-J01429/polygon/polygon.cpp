#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5007];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	return 0;
} 


