#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int r=a[1],grade;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			grade=i;
		}
	}
	int t;
	if(grade%n==0){
		t=grade/n;
	}else{
		t=(grade/n)+1;
	}
	cout<<t<<" ";
	if(t%2==1){
		if(grade%n==0){
			cout<<n;
		}else{
			cout<<grade%n;
		}
	}else{
		if(grade%n==0){
			cout<<1;
		}else{
			cout<<n-grade%n+1;
		}
	}
	return 0;
}
