#include <bits/stdc++.h> 
using namespace std;
int jiang(int e,int f){
	return e>f;
}
int main(){
	int n,m,a,c=1,r=1,wei;
	cin>>n>>m;
	vector <int> v;
	cin>>a;
	v.push_back(a);
	for(int i=1;i<n*m;i++){
		int b;
		cin>>b;
		v.push_back(b);
	}
	sort(v.begin(),v.end(),jiang);
	for(int i=1;i<=n*m;i++){
		if(v[i]==a){
			wei=i;
			break;
		}
	}
	if(wei<=n){
		r=wei%n+1;
	}
	else if(wei>n){
		while(wei<=n){
			wei=wei-n;
			c++; 
		}
		r=m-wei+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
