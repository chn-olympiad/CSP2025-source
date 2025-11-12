#include <bits/stdc++.h>

using namespace std;
int n,m,a[505],cnt,ans = 1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		if(s[i] == '1'){
			cnt++;
		}
	}
	if(cnt == n){
		for(int i = 1;i<=n;i++){
			ans*=i;
		}
		cout<<ans/(n-m);
	}
	return 0;
} 
