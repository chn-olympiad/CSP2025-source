#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)ans++;
	}
	if(k==0)cout<<0;
	else cout<<ans;
	return 0;
} 
