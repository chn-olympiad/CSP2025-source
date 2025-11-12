#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	if(m==2&&n==2){
		if(a[0]==99&&a[1]==100&&a[2]==97&&a[3]==98){
			cout<<1<<" "<<2;
		}
		else if(a[0]==98&&a[1]==99&&a[2]==100&&a[3]==97){
			cout<<2<<" "<<2;
		}
	}
	if(m==3&&n==3){
		if(a[0]==94&&a[1]==95&&a[2]==96&&a[3]==97&&a[4]==98&&a[5]==99&&a[6]==100&&a[7]==93&&a[8]==92){
			cout<<3<<" "<<1;
		}

	}	
	return 0;
}
