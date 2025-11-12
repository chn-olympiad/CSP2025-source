#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	  freopen("polygon.out","w",stdout);
    long long n,num=0,sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		return 0;
	}
    for(long long i=1;i<=n;i++){
    	num=num+a[i];
    	b[i]=b[i-1]+a[i];
	}
    if(num<2*a[n]){
    	sum=1;
	}
	else{
		sum=0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(i>j){
           if(b[j]-b[i]>2*b[i]){
           	sum++;
		   }
       }
       else{
 if(b[j]-b[i]>2*b[j]){
           	sum++;
		   }
	   }
		}
	}
	cout<<sum;
}