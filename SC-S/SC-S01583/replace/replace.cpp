#include<bits/stdc++.h>
using namespace std;
int n, q;
struct node {
	string s1, s2;
} a[10000];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
		a[i].s1 = ' '+a[i].s1;
		a[i].s2 = ' '+a[i].s2;
	}
	while (q--) {
		int ans = 0;
		string q1, q2;
		cin >> q1 >> q2;
		q1 = ' '+q1;
		q2 = ' '+q2;
		for (int i = 1; i <= n; i++) {

			int len = a[i].s1.length();
			for (int k = 1; k <= (int)q1.length() - len+1; k++) {
				string qq = q1;
				int f = 1;
				for (int j = k; j < k + len-1; j++) {
					if (qq[j] == a[i].s1[j-k+1]){
//						cout<<i<<" "<<k<<" ";
//						cout<<qq[j]<<" ";
						qq[j] = a[i].s2[j-k+1];
//						cout<<qq[j]<<"\n";
					}
					else {
						f = 0;
						break;
					}
//					cout<<i;
				}
//				cout<<"\n";
//				cout<<qq<<"\n";
//				cout<<qq<<"\n";
				if (qq == q2&&f) {
					ans++;
//					cout<<a[i].s1;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}