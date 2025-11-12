#include<bits/stdc++.h> 
using namespace std;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	long long x;
	cin>>n>>m;
	long long arr[n*m];
	for(long long i=0;i<n*m;i++){
	    cin>>arr[i];
	    x=i;
	}
	long long a=arr[0],f=0;
	sort(arr,arr+x+1);
    for(long long j=n*m-1;j>=0;j--){
    	f++;
	        if(arr[j]==a){
	        	break;
			}
			 
	}
	
	if(f%n==0){
		cout<<f/n<<" ";
		if((f/n)%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
	}else{
		cout<<f/n+1<<" ";
		if((f/n+1)%2==0){
			cout<<n-f%n+1;
		}else{
			cout<<f%n;
		}
	}
	
	return 0;
}
