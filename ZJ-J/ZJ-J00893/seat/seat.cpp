#include <bits/stdc++.h>
using namespace std;

const int N = 10+10;

int n,m;
int a[N*N];
int s[N][N];
int tar;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}tar=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int j=1;j<=m;j+=2){
		for(int i=1;i<=n;i++){
			s[i][j]=a[2*n*(j/2)+i];
		}
	}for(int j=2;j<=m;j+=2){
		for(int i=n;i>=1;i--){
			s[i][j]=a[n*(j-1)+(n-i+1)];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<s[i][j]<<' ';
//		}cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==tar){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}