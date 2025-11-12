#include<iostream>
using namespace std;
bool polygon(int m,int mmax,int ssum,int o,int a){
	if(m==0){
		if(ssum>2*mmax){
			return true;
		}else return false;
	}
	
	return polygon(m--,max(mmax,a),ssum+=a,o++,a);
}
int main(){
	int n;
	int mmax=0,ssum=0;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int m=3;m<=n;m++){
		for(int p=0;p<n;p++){
			if(polygon(m,mmax,ssum,p,a[p]))  sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
