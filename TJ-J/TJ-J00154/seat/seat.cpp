#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int b[100000];
int n, m;
int main(){
	freopen("seat.in","r", stdin);
	freopen("seat.out", "w", stdout);


	cin >> n >> m;
	int p=n*m;
	for(int i=1; i<=n*m; i++){
		cin >> b[i];
	}
	int a1=b[1];
	sort(b, b+n*m+1);
	for(int i=n*m; i>=1; i--){
		if(b[i]==a1&&p-i+1<=n){
			cout << 1 << ' '<< p-i+1;
		}
		else if (b[i]==a1&&p-i+1>n){
			if((p-i+1)%n==0){
				cout << (p-i+1)/n << m;
			}
			else{
				cout << (p-i+1)/n+1 << ' ' << ((p-i+1)%n);
			}
		}
	}
	
	return 0;
}
