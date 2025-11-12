#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);
    string a;
    long long ans;   
    cin>>a;
    int n;
    n=a.length();
    int b[n+3];
    int c=0;																																																																																																																																																																																						
    for (int i;i=0;i<=n,i++){
        if(a[i]>'1'){
        	if(a[i]>'9' ){
            	b[c]=a[i];
            	c+=1;
        }
        }
    }
    int bea=0;
    for (int i;i=0;i<c,i++){
   		for (int i;i=0;i<c,i++){
			if(b[i]<b[i-1]){
				bea=b[i];
				b[i]=b[i-1];
				b[i-1]=bea;
		}
	}
}
    for(int i;i=0;i<c,i++){
    	cout<<b[i];
    }
    
    return 0;
}																																																				
