#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int qwe[10000000];
int main(){
	freopen("polygon.in","r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if(n==3){
		cout << 1;
		return 0;
	}
	int mod=998244353;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i=1; i<=n; i++){
		qwe[i]=a[i];
	}
	for(int i=2; i<=n; i++){
		a[i]+=a[i-1];
	}
	long long cnt=0;
	for(int i=1; i<=n; i++){
		int max=2*qwe[n-i+1];
		for(int j=1; j>=n; j++){
				for(int i=3; i<=n; i++){
					int zd=n/2;
				
			}
		}
	}
	return 0;
}

