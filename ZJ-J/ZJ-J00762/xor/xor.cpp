#include<bits/stdc++.h>
using namespace std;
long long a[600000],k,x;
int n,i=0,s=0,j=0;
int b(){
	int l=j+1,r;
	for(;l<i;l++){
		x=0;
	    for(r=l;r<i;r++){
	    	x=x xor a[r];
	    	if(x==k){
	    		j=l;
	    		i=r;
	    		b();
                return 0;
			}
	    }
	}
	i=i+1;
	return 0;
}
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(;i<n;i++)cin>>a[i];
    for(i=0;i<n;j=i)for(x=0;i<n;i++){
   		x=x xor a[i];
   		if(x==k){
   		    b();
   		    s++;
   		    break;
		}
	}
	cout<<s;
	return 0;
}
