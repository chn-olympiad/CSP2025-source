#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)s=s*i%998244353;
	cout<<s;
	return 0;
}

