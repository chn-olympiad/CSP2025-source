//SN-J00251 孙悦翔 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[1]==k){
			if(a[2]==k){
				cout<<2;
				return 0;
			}
			cout<<1;
			return 0;
		}
	}   
	    else if(a[2]==k){
	    	cout<<1;
	    	return 0;
		}
        else if(a[1]^a[2]==k){
        	cout<<1;
        	return 0;
		}	
		cout<<0;
		return 0;
	return 0;
} 
