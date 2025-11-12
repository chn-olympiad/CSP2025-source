#include<bits/stdc++.h> 
using namespace std;
int t,x,y,z,xz,ans=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,a[100100],b[100100],c[100100],xz,x=0,y=0,z=0;
		cin>>n;
		xz=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		if(n==2){
			int maxx=0;
			if((a[1]+b[2])>maxx){
				x=a[1],y=b[2];
				maxx=(a[1]+b[2]);
			}
			if((a[1]+c[2])>maxx){
				x=a[1],z=c[2];
				maxx=(a[1]+c[2]);
			}
			if((b[1]+a[2])>maxx){
				y=b[1],x=a[2];
				maxx=(b[1]+a[2]);
			}
			if((b[1]+c[2])>maxx){
				y=b[1],z=c[2];
				maxx=(b[1]+c[2]);
			}
			if((c[1]+a[2])>maxx){
				z=c[1],x=a[2];
				maxx=(c[1]+a[2]);
			}
			if((c[1]+b[2])>maxx){
				z=c[1],y=b[2];
				maxx=(c[1]+b[2]);
			}
		}
		else{
			sort(a+1,a+n+1);
			for(int j=n;j>(n-xz);j--)x+=a[j]; 
		}
		cout<<x+y+z<<'\n';
		x=0,y=0,z=0;	
	}
	
	return 0;
}