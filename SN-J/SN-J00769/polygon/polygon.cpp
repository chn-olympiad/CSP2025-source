#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	int n,m;
	cin >> n;
	cin >> m;
	int c[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cin >> c[i][j];
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			if(j != m-1){
				if(c[0][0] < c[i][j+1]){
					cout << i+1 << endl;
					cout << j+2 << endl;
				}
			}
			if(j == m-1){
				if(c[0][0] < c[i+1][1]){
					cout << i+2 << endl;
					cout << 1 << endl;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
