#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[410];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio;cin.tie(0);cout.tie(0);
	int n,m,e=0;
	cin >> n >> m;
	int p=n*m;
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	e=b[0];
	sort(b,b+n*m+1);
	for(int i=0;i<400;i++){
		if(b[i]==e){
			int r=i%(n*2),o=i/n;
			if(r<=n&&r!=0){
				cout << o+1 << ' ' << r;
			}
			else if(r>n) cout << o+1 << ' ' << 2*n-r+1;
			else cout << o << ' ' << 1;
		} 
		
	}
	return 0;
}
