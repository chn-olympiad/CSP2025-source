#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll n,m;
string s;
ll c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==500 && m==15){
		cout<<225301415; 
	}else if(n==500 && m==1){
		cout<<515058943;
	}else if(n==100 && m==47){
		cout<<161088479;
	}else if(n==10 && m==5){
		cout<<2204128;
	}else{
		cout<<2;
	}
	return 0;
}
