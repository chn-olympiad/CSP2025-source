#include<bits/stdc++.h>
using namespace std;
int n,m,A[200],ans;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>A[i];
	}
	int k=A[1];
	sort(A+1,A+n*m+1);
	for(int i=n*m;i>0;i--){
		if(A[i]==k){
			ans=n*m-i+1;
		}
	}
	int b=ans%(n*2);
	int d=ans/(n*2);
	if(b<=n&&b!=0){
		cout<<d*2+1<<" ";
		cout<<b;
		return 0;
	}
	if(b>n&&b!=0){
		cout<<d*2+2<<" ";
		cout<<2*n-b+1;
		return 0;
	}else{
		cout<<d*2<<" ";
		cout<<1;
		return 0;
	}
}
