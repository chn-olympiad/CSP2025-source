#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	for(int j=0;j<m/2;j+=2){
		for(int i=0;i<n;i++){
    		cin>>a[j][i];
    	}
    	for(int i=n;i>0;i--){
    	 	cin>>a[j+1][i];
    	}
	}
	for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(a[1][1]=a[i]a[j]){
    			cout<<i<<" "<<j;
			}
        }
    }
	fclose(stdin); 
	fclose(stdout);
	return 0;     
}                  
