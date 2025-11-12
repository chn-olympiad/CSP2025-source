#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,a[1001],cnt=0,sum;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n*m;i++){
	cin>>a[i];
}
int max=0;
for(int i=0;i<n*m;i++){
	if(a[i]>max){
		max=a[i];
	}	
}
 for(int i=0;i<n*m;i++){
 	if(a[i]<=max && a[i]>=a[0]){
 		cnt++;
	 }
 }
 sum=cnt/n;
for(int i=0;i<n*m;i++){
	if(cnt%n!=0){
		cout <<sum+1<<' ';
		break;
	}
	else{
		cout <<sum<<' ';
		break;
		
	}
}
for(int i=0;i<n*m;i++){
	if(cnt%(m+1)==0){
		cout <<cnt-1;
		break;
	}
	if(cnt%m==0 ){
		cout <<cnt;
		break;
	}
	else{
		cout <<cnt%m;
		break;
	}
}
	return 0;
}
