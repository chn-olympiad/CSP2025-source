#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	bool fen=0;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) fen=0;
	}
	if(n==3){
		if(a[0]+a[1]<a[2] || a[0]+a[2]<a[1] || a[2]+a[1]<a[0]) cou<<0<<endl;
		else cout<<1<<endl;
		return 0;
	} 
	
	if(fen){
		long long c=1;
		for(int i=0;i<n;i++){
			c*=2;
			c=(c-1)%998234353;
		}
		cout<<c;
		return 0;
	}
	cout<<0;
	return 0;
} 
