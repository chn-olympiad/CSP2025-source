#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon.in""r",stdin);
	//freopen("polygon.out","w",stdout);
    int n,sum=0,s;
    int a[100000]={0};
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]>a[i-1]&&a[i]>a[i-2]&&a[i-3])
    	    s=a[i];
    	else if(a[i-1]>a[i]&&a[i-1]>a[i-2]&&a[i-1]>a[i-3])
			s=a[i-1];
		else if(a[i-2]>a[i]&&a[i-2]>a[i-1]&&a[i-2]>a[i-3])
		    s=a[i-2];
		else
		    s=a[i-3];
    	if(a[i]+a[i-1]+a[i-2]>s*2||a[i]+a[i-1]+a[i-2]+a[i-3]>s*2)
    		sum++;

	}
	cout<<sum;
	return 0;
}