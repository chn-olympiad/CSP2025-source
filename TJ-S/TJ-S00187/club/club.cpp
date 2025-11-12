# include <bits/stdc++.h>
using namespace std;
int m[7];
int c[7];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> m[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m[i];j++){
			for (int k=0;k<3;k++){
				cin >> c[k];
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m[i];j++){
			int sum = 0,s=0;
			for (int k=0;k<3;k++){
				if (c[k]>s) s = c[k];
			}
			sum += s;
		}
		cout << sum << endl;
	}
	return 0;
}
