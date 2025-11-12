#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int arr[1000000];
string s;
int c[1000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	ans = 1;
	for(int i=1;i<=n;i++){
		ans = (ans * i)%998244353;
	}
	cout<<ans;
	return 0;
} 
