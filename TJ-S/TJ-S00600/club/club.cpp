#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m,s=0,a1,a2,a3;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
	     	cin>>m;
	     	a1=m;
	        a2=m;
	        a3=m;
			if(a1>a2&&a1>a2)   
			    s+=a1;
		    if(a2>a1&&a2>a3)   
			    s+=a2;
		    if(a3>a1&&a3>a2)   
			    s+=a3;
		}
	}
cout<<s;
return 0;
}
