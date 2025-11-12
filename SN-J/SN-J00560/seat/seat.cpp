#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m,a[z],b;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<z;i++){
		b=a[i];
		if(b<a[i+1]){
			b=a[i+1];
		}
		
	}
	cout<<b;
	return 0;
}
