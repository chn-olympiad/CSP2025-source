#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long l;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+5];
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
    	for (int j=i+1;j<=n;j++){
    		for (int k=j+1;k<=n;k++){
    		    if(a[i]+a[j]+a[k]>2*a[n]){
    		       ans++;
        		}
	    	}
    	}
	}
	cout<<ans%998244353;
	return 0;
}
