#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,s,c=1,d,e,f;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	e=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
		if(a[e]<a[e-1]&&e!=1){
			f=a[e];
			a[e]=a[e-1];
			a[e-1]=f;
		}
		if(a[c]<a[c+1]){
			d=a[c];
			a[c]=a[c+1];
			a[c+1]=d;
			y++; 
			c++;
		}
		if(y>n){
			x++;
			y=1;
		}
	} 
	cout<<x<<" "<<y<<endl;
	return 0;	
}
