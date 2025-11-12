#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100][100];
	int m,n;
	cin >> m >> n;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cin >> a[i][j];
		}
	}
	int  b;
	cin >> b;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;i++){
			if(a[i][j]!=b){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
