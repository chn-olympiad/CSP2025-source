#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//
	int n,m;
	int a[110];
	int a_1,h=1;
	int c,r;
	
	cin>>n>>m;
	cin>>a[0];
	a_1=a[0];
	for(int i=1;i<(n*m);i++){
		cin>>a[i];
		if(a_1<a[i]){
			h++;
		}
	}
	r=h%n;//0
	c=h/n;//2
	if(r==0){
		r=n;//5
	}
	if(h%n!=0){
		c+=1;
	}
	if(c%2==0){
		r=n-r+1;//1
	}

	cout<<c<<' '<<r;
	return 0;
}


