#include<bits/stdc++.h>
using namespace std;
int m,n,r;
int ch;
int a[1000000];
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		if(i==1){
			cin>>r;
			a[i]=r;
		}else{
			cin>>a[i];
		}
	}
	sort(a+1,a+m*n+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ch=i;
			i=m*n+1;
		}
	} 
	int r;
	int c=((ch-1)/n)+1;
	if(c%2==0){
		r=n+1-(ch%n);
	}else{
		r=1+(ch-1)%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
