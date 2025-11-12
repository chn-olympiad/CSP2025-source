#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])s++;
	}
	cout<<s/n+1<<" ";
	if((s/n+1)%2==1){
		cout<<s%n+1;
	}
	else{
		cout<<n-s%n;
	}
	return 0;
}
