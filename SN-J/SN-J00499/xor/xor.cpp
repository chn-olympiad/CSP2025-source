#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a=0;
int as[500005] ;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>as[i];
	}
	for(int i=1;i<=n;i++){
		ans=as[i];
		for(int j=i+1;j<=n;j++){
		
			if(ans==k){
				if(j-i>a){
					a=j-i;
				}
				if(i-j>a){
					a=i-j;
				}
				break;
			}
			ans=ans+as[j];
			if(ans==k){
				if(j-i>a){
					a=j-i;
				}
				if(i-j>a){
					a=i-j;
				}
				break;
			}
		}
		
	}
	for(int i=n;i>=1;i--){
		ans=as[i];
		for(int j=i-1;j>=1;j--){
			if(ans==k){
				if(i-j>a){
					a=i-j;
				}
				if(j-i>a){
					a=j-i;
				}
				break;
			}
			ans=ans-as[j];
			if(ans==k){
				if(i-j>a){
					a=i-j;
				}
				if(j-i>a){
					a=j-i;
				}
				break;
			}
		}
		
	}
	cout<<a;
	return 0;
	fclose(stdin);
	fclose(stdout); 
}
