#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,xos[100005],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>xos[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(xos[i]==1)cnt++;
	}
	if(cnt==n&&k==0){
		cout<<n/2;
		return 0;
	}
	
	int sum;	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=xos[i];
			for(int q=i+1;q<=j;q++)
			{
				sum^=xos[q];
			}
			if(sum==k){
				ans++;
				i=j;
			}
		}
	} 

	cout<<ans;
    return 0;
}																												

                                                
                                                
                                                
                                                
                                                
                                                
                                                
                                                
                                                
                                                
                                                   
                       	                         
                                                
                                                
                                                
                                                
                                       

