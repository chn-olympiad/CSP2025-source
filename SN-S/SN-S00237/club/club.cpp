#include<bits/stdc++.h>
using namespace std;
int h,n,a[30003],b[30003],c[30003],t,e,f,g,z[101];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
		cin>>a[j];
		cin>>b[j];
		cin>>c[j];
		if(a[j]>b[j]&&a[j]>c[j]){
			e++;
			z[i]=z[i]+a[j];
			
		}
		if(b[j]>a[j]&&b[j]>c[j]){
			f++;
			z[i]=z[i]+b[j];
		}
		if(c[j]>a[j]&&c[j]>b[j]){
			g++;
			z[i]=z[i]+c[j];
		}
		
		
	}
	
	
		e=0;
		f=0;
		g=0;
		
		
	
	for(int i=0;i<t;i++){
		
			cout<<z[i]<<endl;
	
	}
}
	return 0;
}

