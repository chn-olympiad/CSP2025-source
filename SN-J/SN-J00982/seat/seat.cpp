#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,d=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		string a;
		cin>>a;
		if(a[0]<a[i-1]){
			d+=1;
		}
	}
	int c=d/m,r=d%n;
	cout<<c<<" "<<r;
	return 0;
}
