#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m;
int a[N];
int ans,tmp;
int h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m);
	for(int u=1;;u++){
		if(a[u]==ans){
			tmp=n*m-u+1;
			break;	
		}
	}
	if(tmp%n==0){
		l=tmp/n;
	}else{
		l=tmp/n+1;
	}
	if(l%2==1){
		if(tmp%n==0){
			h=n;
		}else{
			h=tmp%n;
		}
	}else{
		if(tmp%n==0){
			h=1;
		}else{
			h=n-tmp%n+1;
		}
	}
	cout<<l<<' '<<h;
}
