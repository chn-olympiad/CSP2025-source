#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		cin>>a[i];
	   if(a[i]>a[i+1]){
	   	a[i]=i;
	   	cout<<1<<" ";
	   }	
		else if(a[i]<a[i+1]){
			a[i]=n*m-i+1;
			cout<<2;
		}	
		}
	}
	return 0;
}
