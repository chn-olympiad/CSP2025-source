#include<bits/stdc++.h>
using namespace std;
int arr[105];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout); 
	int n,m,k;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>arr[i];
	}
	int ans=arr[1];
	sort(arr+1,arr+n*m+1);
    for(int i=1;i<=n*m;i++){
    	if(arr[i]==ans){
    		k=n*m-i+1;		
		} 
	}
    cout<<k/n+1<<" ";
    if((k/n+1)%2==1){
    	if(k%n==0){
    		cout<<n;
		}else{
			cout<<k%n;
		}
    	
    }else{
		cout<<m-(k%n);
	}
    return 0;
} 


