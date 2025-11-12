#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a,k=1;
	cin>>a;
	int b[m*n+1];
	b[1]=a;
	for(int i=2;i<=m*n;i++){
		cin>>b[i];
		if(a<b[i]) k++;
	}
	int nu=1;
	while(k>n){
		k-=n;
		nu++;
	}
	cout<<nu<<" "<<k;
	return 0;
}
