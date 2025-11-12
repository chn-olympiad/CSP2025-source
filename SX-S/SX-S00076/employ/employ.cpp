#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s=1;
	cin>>n>>m;
	for(int i=2;i<=m;i++) s*=i,s%=998244353;
	cout<<s;
	return 0;
}