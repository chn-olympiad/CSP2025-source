#include<bits/stdc++.h>
using namespace std;


int n,k;
int a[500005];



int main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);


	cin>>n>>k;
	
	bool isA=true;
	bool isB=false;
	
	
	if(k!=0){
		isA=false;
	}
	
	if(k<=1){
		isB=true;
	}
	
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			isA=false;
		}
		if(!(a[i]>=0&&a[i]<=1)){
			isB=false;
			
		}
	}
	
	
	if(isA==true){
		cout<<n/2<<endl;
		return 0;
	}
	
	if(isB==true){
		if(k==1){
			int tmp=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					tmp++;
				}		
				if(tmp%2==1){
					ans++;
					tmp=0;
				}	
			}
			cout<<ans<<endl;
			
		}else{
			int tmp=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					tmp++;
				}		
				if(tmp%2==0){
					ans++;
					tmp=0;
				}	
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	/*
	for(int l=1;i<=n;i++){
		for(int r=1;i<=n;i++){
			if(xo(l,r)==k){
				
			}
		}
	}
	*/
	

	return 0;
}



//By StuffyWalk Problem3

