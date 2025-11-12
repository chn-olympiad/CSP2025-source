#include <bits/stdc++.h>
using namespace std;
int n,ans,cnt,f;
int a[100000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;i<n;i++){
		cnt=0;
		f=0;
	 	for(int j=0;j<n-i;j++){
	 	    cnt+=a[j];
	 	    f++;
    	}
    	if(cnt>a[n-i]){
    		ans++;
    		for(int k=0;k<n-i-1;k++){
    			cnt-=a[k];
    			if(cnt>a[n-i]){
    				ans++;
				}
	    	}
		}
	}
	
	cout<<ans;
	return 0;
} 
