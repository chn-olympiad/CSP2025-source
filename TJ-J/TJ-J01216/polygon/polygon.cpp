#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],sum=0,mxa=0,ans=0,flag=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mxa=max(mxa,a[i]);
		if(a[i]!=1) flag=1;
	}
	if(n==3){
	    if(sum>mxa*2){
	   	    cout<<1<<endl;
	    } 
	    else cout<<0<<endl;
	    return 0;	
	}
	if(flag==0){
		cout<<n-2<<endl;
		return 0;
	}	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
