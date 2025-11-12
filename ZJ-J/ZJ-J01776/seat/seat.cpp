#include<bits/stdc++.h>
using namespace std;
int m, n, a[200], seat[11][11];
bool f;
int hang, lie=1;
bool cmp(int i, int j){
	return i>j;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int r=a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i=1;i<=n*m;i++){
		if(f==0){
			hang++;
		}
		else{
			hang--;
		}
		if(hang==0){
			lie++;
			hang=1;
			f=0;
		}
		if(hang==n+1){
			lie++;
			hang=n;
			f=1;
		}
		seat[hang][lie]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==r){
				cout << j <<" "<< i;
			}
		}
	}
}