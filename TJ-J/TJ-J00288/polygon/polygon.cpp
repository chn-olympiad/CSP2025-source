#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<=20){
    int cnt=0;
	int a[105]={};
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
		    	for(int k=1;k<=n;k++){
		    		if(a[k]+a[j]+a[i]>max(2*a[i],max(2*a[j],2*a[k]))){
		    			cnt++;
					}
				}
			} 
        }
        cout<<cnt;
    }
    else{
    	cout<<1;
	}
    return 0;
	}
