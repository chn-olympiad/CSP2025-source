#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string a;
	cin>>n>>m;
	int h[n+10]={};
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	int o=n;
	bool litle=1;
	for(int i=0;i<a.size();i++){
		if(a[i]=2){
			litle=0;
			o--;
		}
	}
	if(litle=0){
		cout<<m*o;
	}else{
		cout<<m*998244351%998244351;
	}
	return 0;
}
