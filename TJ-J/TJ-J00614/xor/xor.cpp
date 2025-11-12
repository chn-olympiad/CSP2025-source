#include<bits/stdc++.h>
using namespace std;
int arr[1000005]={};
int brr[1000005]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==0){
			k++; 
		}
	}
	if(m==0){
		cout<<k;
		return 0;
	}
	
	return 0;
}
