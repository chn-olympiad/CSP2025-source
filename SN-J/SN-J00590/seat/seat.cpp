// 西安市曲江第一学校 SN-J00590 李骏铭
#include<bits/stdc++.h>
using namespace std;
int n,m;
int o=1;
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int a[n*m+5];
	for (int i=1; i<=n*m; i++) {
		cin >> a[i];
	}
	int y=a[1];
	sort(a+1,a+1+n*m);
	int sum;
	for (int i=n*m; i>0; i--) {
		if (a[i]==y) {
			sum=o;
			break;
		}
		o++;
	}
	if (sum-n<=0) {
		cout << 1 << " " << sum;
	} else if(sum%n==0) {
		if (sum/n%2==0) {
			cout << sum/n << " " << 1;
		} else {
			cout << sum/n << " " << n;
		}
	} else {
		if (sum/n%2==0) {
			cout << sum/n+1 << " "<< sum%n;
		} else {
			if (sum%n==1) {
				if (sum/n%2==0) {
					cout << sum/n+1 << " " << 1;

				} else {
					cout << sum/n+1 << " "<< n;
				}
			} else {
				cout << sum/n+1 << " " << n-sum%n;
			}

		}
	}
	cout << endl;
	return 0;
}

