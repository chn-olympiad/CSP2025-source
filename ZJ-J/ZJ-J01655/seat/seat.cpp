#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a;
	cin>>a;
	int b=1;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>a){
			b++;
		}
	}
	int l=(b-1)/n+1;
	cout<<l<<" ";
	if(l%2==1){
		cout<<(b-1)%n+1;
	}
	else{
		cout<<n-(b-1)%n;
	}
	return 0;
}
