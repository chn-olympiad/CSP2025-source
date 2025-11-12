#include <bits/stdc++.h>
using namespace std;
    int n,a[100],ans=0,ans1=0,ans2=0;
int main(){
	cin>>n;
	for (int i=0;i<n;i++) {
	    cin>>a[i];	
    }
    for (int i=0;i<=3;i++) {
	    a[i]+a[i+1]+a[i+2];
		ans+=1;	
    }
    for (int i=0;i<=2;i++) {
	    a[i]+a[i+1]+a[i+2]+a[i+3];
		ans+=1;	
    }
    for (int i=0;i<=1;i++) {
	    a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4];
		ans2+=1;	
    }
    cout<<ans+ans1+ans2;
}
