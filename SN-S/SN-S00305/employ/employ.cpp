#include <bits/stdc++.h>
using namespace std;
int n,m;
char x;
int a;
int ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	for(int i=n;i>n-m;i--){
		ans*=i;
		ans%=998244353; 
	}
	cout<<ans;
}
