#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int sum;
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >>k;
	int a[m][4];
	for (int i=1;i<=m;i++){
		for (int j=1;j<=3;j++){
			cin >> a[i][j];
			
		}
		sum+=a[i][2];
	}
	cout << sum;
	return 0;
}

