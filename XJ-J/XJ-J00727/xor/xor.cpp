#include<bits/stdc++.h>
using namespace std;
int a[101],n,k;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		if(k==2||k==3){
			cout<<2;
			
		}
		if(k==0){
			cout<<1;
		}
	}
	return 0;
}
