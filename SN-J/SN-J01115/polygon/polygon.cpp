#include<iostream>
using namespace std;
int main(){
	preopen(polygon.in,'r',stdin);
	preopen(polygon.out,'w',stdout);
	int a[101000][101000],n,m;
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cin >> a[i][j];
		}
	}
	return 0;
}	
