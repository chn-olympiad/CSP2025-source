#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int n;
	for(int i=0;i<t;i++){
		cin >> n;
		int f[n][3];
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin >> f[j][k];
			}
		}
		cout << f[i][i];
	}
	return 0;
}
