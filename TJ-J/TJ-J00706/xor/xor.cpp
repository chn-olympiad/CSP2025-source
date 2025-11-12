#include<bits/stdc++.h>
using namespace std;
bool x(int a,int b){
	return a>b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum=0,n,m,a[5001]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int g=a[i];
			for(int x=i+1;x<=j;x++){
			    g=g^a[x];
			}
			if(g==m){
				sum++;
			}
    	}
	}
	cout<<sum/2;
	return 0;
}

