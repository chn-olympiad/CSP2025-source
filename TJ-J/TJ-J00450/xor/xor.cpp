#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, k, cnt, ans;
ll arr[514514];
ll s[514514];
ll f[514514];
vector <int> e[514514];

int main(){
	//xor
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		
		if(i==1){
			s[i] = arr[i];
		}
		else{
			s[i] = s[i-1]^arr[i];
		}
	}
	
	
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if((i!=j && ((i!=1 && s[j]^s[i-1]==k) || (i==1 && s[j]==k))) || (i==j && arr[i]==k)){
				e[i].push_back(j);
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		f[i] = max(f[i], f[i-1]);
		
		
		for(int j:e[i]){
			f[j+1] = max(f[j+1], f[i]+1);
		}
	}
	
	for(int i=1; i<=n+1; i++){
		ans = max(ans, f[i]);
	}
	
	cout<<ans;
	
	return 0;
}
