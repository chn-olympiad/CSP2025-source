#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[525];
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=1;
	for(int i=n;i>0;i--)ans=ans*i;
	cout<<ans/(n-m);
	return 0;
}
