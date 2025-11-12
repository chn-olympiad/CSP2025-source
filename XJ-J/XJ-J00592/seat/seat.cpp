#include<bits/stdc++.h>
using namespace std;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	int k=0;
	sort(a+1,a+n*m);
	for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		} 
		if(i%2==1){
			for(int j=n;j>=1;j--){
				
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		} 
	}
	return 0;
} 
