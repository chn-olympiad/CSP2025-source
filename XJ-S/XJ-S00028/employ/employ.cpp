#include <bits/stdc++.h>

using namespace std;

int n,m,cnts;
string s; 
long long ans=1;

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		if (x == 0){
			cnts++;
		}
	}
	ans = 1;
	for(int i=n;i>cnts;i--){
		ans *= i;
		ans = ans%998244353;
	}
	cout<<ans;
	
	return 0;
} 
