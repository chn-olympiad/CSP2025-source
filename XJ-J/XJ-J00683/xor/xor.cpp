#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005],s[500005],n,k,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1;
	for(int j=1;j<=n;j++){
		r++;
		b[l]=a[l];
	    for(int i=l;i<=r;i++){
	        b[i]=b[i-1]|a[i];
	        s[i]=s[i-1]+c[i];
	        if(a[i]==k&&s[i]==0){
	    	    sum++;
	    	    c[l]++;
	    	    c[r+1]--;
	    	    l--;
		    }
	    }
	    
    }
	cout<<sum; 
	return 0;
}
