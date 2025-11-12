#include <bits/stdc++.h>
using namespace std;
long long n,i,a[1000001],mi=2e9,ma,k,s1,pop,s0,price,j,b[1000001],c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i],mi=min(mi,a[i]),ma=max(ma,a[i]);
	if(ma==1&&mi==1){//A
		cout<<n/2<<"\n";
		return 0;
	}else if(ma==1&&mi==0){//B
		if(k==0){
			for(i=1;i<=n;i++){
				if(a[i]==1)s1++;
				else if(a[i]==0)s0++;
				if(s1%2==0||s0>0)price++,s1=s0=0;
			}
		}if(k==1){
			for(i=1;i<=n;i++){
				if(a[i]==1)s1++;
				else if(a[i]==0)s0++;
				if(s1%2==1)price++,s1=s0=0;
			}
		}cout<<price<<"\n";
		return 0;
	}else{
		b[1]=a[1];
		for(i=2;i<=n;i++)b[i]=a[i]^b[i-1];
		for(i=1;i<=n;i++){
			for(j=pop;j<=i;j++){
				c=b[i]^b[j-1];
				if(c==k){
					price++,pop=i+1;
					
					break;
				}
			}
		
		}
		cout<<price<<"\n";
	}
	return 0;
}