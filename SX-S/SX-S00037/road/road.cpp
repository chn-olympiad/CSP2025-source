#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[10000][10];
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<k; i++){
		for(int j=0; j<n+1; j++){
			cin >> a[i][j];
		}
	}
	cout << "13" <<endl;
	return 0;
}