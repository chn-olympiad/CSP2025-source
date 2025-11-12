#include<bits/stdc++.h>
using namespace std;
int n,x1,bk=0;
int jk[5001];
int asks(){
	for(int i=0;i<n;i++){
		if(jk[i]+jk[i+1]+jk[i+2]>x1){
			bk++;		
		}
	}
	return 0;	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>jk[i];
	}
	for(int i=0;i<n-1;i++){
		bool z=true;
		for(int j=0;j<n-i;j++){
			if(jk[j]<jk[j-1]){
				swap(jk[j],jk[j-1]);
				z=false;
			}
			
		}
		if(z){
			break;
		}
	}
	x1=jk[n-1]*2;
	for(int i=0;i<n;i++){
		bk+=jk[i];
	}
	if(bk<x1){
		cout<<0;
	}
	for(int x=3;x<=n;x++){
		asks();
	}
	cout<<bk/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

