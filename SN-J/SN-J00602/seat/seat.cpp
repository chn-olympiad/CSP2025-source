//SN-J00692
#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[105],num,ax,ay;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+p);
	for(int i=1;i<=p;i++){
		if(a[i]==num){
			int j=p-i+1;
			int x=j%n;
			int y=j/n;
//			cout<<j<<endl;
//			cout<<x<<endl<<y<<endl;
			if(x!=0 and y%2==1){
				ax=n+1-x;
				ay=y+1;
			}else if(x!=0 and y%2==0){
				ax=x;
				ay=y+1;
			}else if(x==0 and y%2==1){
				ax=n;
				ay=y;
			}else{
				ax=1;
				ay=y;
			}
			break;
		}
	}
	cout<<ay<<" "<<ax;
	return 0;
}
