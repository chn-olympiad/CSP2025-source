#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	k=x-1;
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	int z=a[0];
	sort(a,a+x);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(a[k]==z){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				k--;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(a[k]==z){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				k--;
			}
		}
	}
	return 0;
}
