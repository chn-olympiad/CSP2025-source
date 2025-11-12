#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,b;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==b){
			b=n*m-i+1;
			break;
		}
	}
	int l=b%(2*n);
	if(l<=n){
		cout<<b/(2*n)*2+1<<" "<<l;
	}else{
		cout<<b/(2*n)*2+2<<" "<<2*n-l+1;
	}
}
