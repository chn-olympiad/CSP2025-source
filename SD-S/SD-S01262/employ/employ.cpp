#include<iostream>
#include<cstdio>
using namespace std;
int a[505];
long long f(int x){
	long long l=1;
	for(int i=1;i<=x;i++){
		l*=i;
	}
	return l;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f(n)%998244353;
	return 0;
}
