#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=1; 
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) x++;
	}
	int l=(x+n-1)/n;
	cout<<l<<" ";
	int h=x%n;
	if(l%2==0){
		if(h==0) cout<<1;
		else cout<<n-h+1;
	}
	else{
		if(h==0) cout<<n;
		else cout<<h;
	}
	return 0;
}
