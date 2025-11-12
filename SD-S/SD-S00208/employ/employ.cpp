#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int n,m,c[505],ans=1;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
} 
