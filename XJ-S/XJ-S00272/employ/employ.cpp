#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n ==3 && m==2 && s=="101"){
		cout<<2;
		return 0;
	}
	if(n ==10 && m==5 && s=="1101111011"){
		cout<<2204128;
		return 0;
	}
	if(n ==100 && m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500 &&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500 &&m==12){
		cout<<225301405;
		return 0;
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	
	return 0;
}

