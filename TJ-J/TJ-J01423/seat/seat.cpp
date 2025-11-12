#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],xi,z;
bool asd(int a,int b){
	return a>b;
}
int bbb(int a,int b){
	if(a%b==0){
		return a/b;
	}else{
		return a/b+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>xi;
	a[0] = xi;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,asd);
	for(int i=0;i<n*m;i++){
		if(a[i]==xi){
			z=i+1;
			break;
		}
	}
	cout<<bbb(z,m)<<" ";
	if(bbb(z,m)%2==0){
		cout<<n+1-(z%m);
	}else{
		cout<<z%m;
	}
	
	return 0;
}

