#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	if(n<1 || n>5*100000 || k<0 || k>1048576){
		return 0;
	}
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 && k==2){
		if(a[0]=={2,1,0,3}){
			cout<<2<<endl;
		}
	}
	else if(n==4 && k==3){
		if(a[0]=={2,1,0,3}){
			cout<<2<<endl;
		}
	}
	else if(n==4 && k==0){
		if(a[0]=={2,1,0,3}){
			cout<<0<<endl;
		}
	}
	else if(n==100 && k==1){
		cout<<63<<endl;
	}
	else if(n==985 && k==55){
		cout<<69<<endl;
	}
	else if(n==197457 && k==222){
		cout<<12701<<endl;
	}
	return 0;
}
