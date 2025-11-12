#include<bits/stdc++.h>
using namespace std;
int main(){
// 	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100+10];
	int bh,cj;
	cin>>cj;
	for(int i=0;i<n*m-1;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j]>a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=0;i<n*m-1;i++){
		if(cj<a[i]){
			bh=i+1;
		}
	}
	if((bh-1)%n!=0 && (bh-1)<n){
		cout<<(bh-1)%n;
	}
	else{
		cout<<1;
	}
	return 0;
}