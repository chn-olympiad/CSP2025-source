#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1;
long long sum = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	for(int i=1;i<=n;i++){
		sum = sum*i;
	}
	cout<<sum % 998244353;
	return 0;
} 
