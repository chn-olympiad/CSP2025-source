#include<bits/stdc++.h>
using namespace std;
int a;
int n=0,k=0,_0=0,_1=0;
bool ta=1,tb=1,tc=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a);
    	if(n==1&&a!=k){
            cout<<0;
            return 0;
    	}else if(n==1&&a==k){
    	    cout<<1;
    	    return 0;
    	}
    	if(a==0)_0++;
		if(a==1)_1++;
    	if(a!=1)ta=0;
		if(a>1)tb=0;
	}
	if(k==0&&ta){
		printf("%d",n/2);
	}if(k<=1&&tb){
		if(k==0){
			printf("%d",_0+(_1/2));
		}else{
			printf("%d",_1);
		}
	}

    return 0;
}
