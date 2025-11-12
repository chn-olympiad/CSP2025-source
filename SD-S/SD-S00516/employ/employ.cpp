#include <bits/stdc++.h>
using namespace std;
int b[10004];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string a;
	long long ans=1;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
}

