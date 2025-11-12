#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[111],nn;
int main ( ) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num;
	cin >>n>>m;
	cin >>a[1];
	int s=a[1];
	for(int i=2;i<=n*m;i++){
		cin >>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			num=i;
		}
	}
	if(num%n==0){
		nn=num/n;
	 	cout <<nn;
	}
	else{
		nn=num/n+1;
		cout <<nn;
	} 
	if(nn%2==1){
		if(num%m==0) cout <<" "<<m;
		else cout <<" "<<num%m;
	}else{
		if(num%m==0) cout <<" 1";
		else cout <<" "<<m-(num%m)+1;
	}
	
	return 0;
} 
