#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n;
	string s;
	cin>>s;
	int d[n];
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	for(int j=0;j<n;j++){
		t*=(t-1);
	}
	cout<<t%998244353;
	return 0;
}
