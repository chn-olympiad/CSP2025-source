#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

int ltn[510],ln[510];

int main(){
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		ltn[i] = 1;
	}
	for(int i=1;i<=n;i++){
		cin>>ln[i];
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans = ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
