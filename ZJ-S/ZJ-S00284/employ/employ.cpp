#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	long long s=1;
	for(int i=1;i<=n;i++){
		s=(s*i)%998244353;
	}
	cout<<s;
	return 0;
}
