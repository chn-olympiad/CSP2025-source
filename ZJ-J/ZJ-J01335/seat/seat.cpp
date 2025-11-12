#include<bits/stdc++.h>
using namespace std;
int n,m,p=1,b[100001];
int a[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b[a[i][j]]++;
		}
	}
	for(int i=100;i>=1;i--){
		if(i==a[1][1]) break;
		else if(b[i]) p++;
	}
	int k=(p-1)/n;
	cout<<k+1<<" ";
	if(k%2==0){
		if(p%n==0){
			cout<<n;
		}else{
			cout<<p%n;
		}
	}else{
		if(p%n==0){
			cout<<1;
		}else{
			cout<<n-p%n+1;
		}		
	}
	return 0;
}
