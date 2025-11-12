#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int o=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=0){
			o++;
		}
	}
	if(o<m){
		cout<<0;
	}
	else{
		long long x=1,y=1;
		for(int i=1;i<=o;i++){
			x*=i;
			y*=n-i+1;
			x%=998244353;
			y%=998244353;
		}
		cout<<y/x;
	}
}
