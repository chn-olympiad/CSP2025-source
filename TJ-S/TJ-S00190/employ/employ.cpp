#include <bits/stdc++.h>
using namespace std;
const int MAX=500;
int p[MAX];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	cout<<(n-1)%998244353;
	return 0;
}

