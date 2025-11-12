#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m],r=0,c=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==r){
			c=i;
			break;
		}
	}
	if(c%n==0){
		cout<<c/n<<" ";
	}else{
		cout<<(c/n)+1<<" ";
	}
	if(c%(2*n)>n){
		cout<<n-(c%(2*n)-n);
	}else{
		cout<<c%(2*n);
	}
	return 0;
}
