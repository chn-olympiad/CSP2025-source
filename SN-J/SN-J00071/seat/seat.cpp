#include<bits/stdc++.h>
using namespace std;
int a[105]={0},cnt=1;
int main(){
	freopen("seat.in",r ,"stdin");
	freopen("seat.out",w ,"stdout");
	int m,n,c;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m-1;i++){
		for(int j=i;j<n*m;j++){
			c=i%n;
			if(a[i]>a[j]){
				swap(a[i],a[j]);
				if(i%n!=0){
					if(c==n) cnt=n-1;
					else if(c==1) cnt=1;
				}	
			} 
		}
	}
	cout<<cnt<<" "<<n-c;
	return 0;
}
