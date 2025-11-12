#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>m;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int j=1;j<n;j++){
		for(int i=0;i<n;i++){
		    int temp_a;
		    if(b[i]<b[i+1]){
			    temp_a=b[i];
			    b[i]=b[i+1];
			    b[i+1]=temp_a;
		    }
	    }
	}
	cout<<b[0];
	return 0;
}
