#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=n;
	while(n==1){
		n--;
		ans=ans*n;
	}
	cout<<ans;
	return 0;
}
