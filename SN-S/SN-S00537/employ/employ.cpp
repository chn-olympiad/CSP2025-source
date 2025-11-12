#include<bits/stdc++.h>
using namespace std;

long long dfs(long long l,long long r){
	long long n=1;
	for(int i=0;i<=r;i++){
		n*=(l-i);
	}
	return n;
}
long long n,z1,a[100010];
string c1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>z1;
	cin>>c1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(n,z1);
	return 0;
}


