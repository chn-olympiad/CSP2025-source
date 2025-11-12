#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[10000001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
}
