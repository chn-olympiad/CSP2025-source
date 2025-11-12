#include<bits/stdc++.h>
using namespace std;
long long n,k,i_,j_,k_[10000001],kkk,jg;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		i_=i;
		i=arr[i];
		for(int j=i+1;j<n;j++){
			j_=j;
		    j=arr[j];
		    k_[i]=i;
		    for(int kk=i+1;kk<=j;kk++){
		    	k_[kk]=kk;
		    	kkk+=k_[kk]||k_[kk-1];
				
			}
			if(kkk==k){
				jg++;
			
			}
			kkk=0;	
		    j=j_;
		}
		i=i_;
	}
	cout<<jg;
	return 0;
}
