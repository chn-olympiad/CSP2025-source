//SN-J01002   贺宇轩  西安市经开第二中学 
#include<bits/stdc++.h>
using namespace std;
//	freopen(" seat1.in","r",stdin);
//	freopen(" seat1.out","w",stdout);
int main(){
	int n,m,v,z,e,o;
	cin>>n>>m;	
	int x[n*m];
	e=1;
	z=0;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
		o=x[1];
	}
	for(int j=1;j<=n*m;j++){
		if(x[1]<x[j]){
			v=x[j];
			z++;
		}
	}
	for(int f=1;f<=n*m;f++){
		if(z>n){
			z-=n;
			if(z==0){
				z=n;
				e++;
				break;
			}
			e++;	
		}
//		if(z=n){
//			e++;	
//		}
	}
	if(e%2==0){
		if(z==n){
			
			cout<<e+1<<" "<<1;	
		}
		else{
			
			cout<<e<<" "<<n-z;	
		}
	}
	else{
		cout<<e<<" "<<z+1;
	}
	return 0;
}
