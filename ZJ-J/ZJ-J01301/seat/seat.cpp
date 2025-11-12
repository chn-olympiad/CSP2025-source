#include<bits/stdc++.h>
using namespace std;
int n,m,r,p,h;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=n*m-i+1;
			break;
		}
	}
	if(r%n!=0) p=1;
	cout<<r/n+p<<" ";
	if((r/n+p)%2==0){
		cout<<n-r%n+1;
	}
	else{
		h=r%n;
		if(h==0) cout<<n;
		else cout<<h;
	}
	return 0;
}
