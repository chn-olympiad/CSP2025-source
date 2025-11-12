#include <bits/stdc++.h>
using namespace std;

int n,k;
int ma=-1;
int a[500100];

int solve(int l,int r) {
	int sum=0;
	for(int i=l; i<=r; i++) {
		sum=sum^a[i];
	}
	return sum;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(solve(i,j)==k) {
				if((j-i+1)>ma) {
					ma=j-i+1;
				}
			}
		}
	}
	cout << ma << endl;
	return 0;
}
