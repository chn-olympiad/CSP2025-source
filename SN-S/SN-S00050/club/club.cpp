#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0){
		t--;
		int n;cin>>n;
		int a[100][100];
		cin>>a[1][1];
		cin>>a[1][2];
		cin>>a[1][3];
		cin>>a[2][1];
		cin>>a[2][2];
		cin>>a[2][3];
		int b,c,d,e;
		if(a[1][1]>a[1][2]){
			b=a[1][1];
			c=1;
		}else{
			b=a[1][2];
			c=2;
		}
		if(b<a[1][3]){
			b=a[1][3];
			c=3;
		}
		if(a[2][1]>a[2][2]){
			d=a[2][1];
			e=1;
		}else{
			d=a[2][2];
			e=2;
		}
		if(d<a[2][3]){
			d=a[2][3];
			e=3;
		}
		if(c!=e){
			cout<<b+d<<endl;
		}else{
			a[1][c]=-1;
			a[2][e]=-1;
			int b1,c1,d1,e1;
			if(a[1][1]>a[1][2]){
				b1=a[1][1];
				c1=1;
			}else{
				b1=a[1][2];
				c1=2;
			}
			if(b1<a[1][3]){
				b1=a[1][3];
				c1=3;
			}
			if(a[2][1]>a[2][2]){
				d1=a[2][1];
				e1=1;
			}else{
				d1=a[2][2];
				e1=2;
			}
			if(d1<a[2][3]){
				d1=a[2][3];
				e1=3;
			}
			if(b1>d1){
				cout<<b1+d<<endl;
			}else{
				cout<<d1+b<<endl;
			}
		}
	}
}
