#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int s1,int s2){
	return s1>s2;
}
int b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int pl=n*m;
	for (int i=1;i<=pl;i++){
		cin >> a[i];
	}
	int ol=a[1];
	sort(a+1,a+pl+1,cmp);
	for (int j=1;j<=m;j+=2){
		for (int i=1;i<=n;i++){
			b[i][j]=a[(j-1)*n+i];
		}
	}
	for (int j=2;j<=m;j+=2){
		for (int i=1;i<=n;i++){
			b[i][j]=a[j*n-i+1];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (b[i][j]==ol){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}

