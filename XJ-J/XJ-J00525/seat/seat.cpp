#include<bits/stdc++.h>
using namespace std;
int b[1000];
bool s(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,c=1,d=1,e=0,f=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	a=b[0];
	sort(b,b+n*m,s);
	while(b[f]!=a){
		f++;
	}
	for(int i=0;i<f;i++){
		if(e==0){
			d++;
			if(d>n){
				e=1;
				c++;
				d=n;
			}
		}else{
			d--;
			if(d<1){
				e=0;
				c++;
				d=1;
			}
		}
	}
	cout<<c<<' '<<d;
	return 0;
}
