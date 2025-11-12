#include<bits/stdc++.h>
using namespace std;
int a[200]={};
int n,m,r,p;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=i;
			break;
		}
	}
	int e;
	if(p%n==0){
		cout<<p/n<<' ';
		e=p/n;
	}else{
		cout<<p/n+1<<' ';
		e=p/n+1;
	}
	int f=p%n;
	if(e%2==0){
		if(f==0){
			cout<<1;
		}else{
			cout<<n-f+1;
		}
	}else{
		if(f==0){
			cout<<n;
		}else{
			cout<<f;
		}
	}
	return 0;
}
