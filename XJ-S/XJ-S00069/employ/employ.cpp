#include<bits/stdc++.h>
using namespace std;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<((1ll*n*m*114514%998244353)*1919810)%998244353;
	return 0;
}
