#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,a[100001]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(n==1){
		if(a[0]==0){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=0;i<=n;i++){
			if(a[i]==0){
			    cout<<2;
		    }else{
		    	cout<<1;
		    }
		}
	}
}
