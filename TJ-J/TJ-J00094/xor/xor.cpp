#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
int a[500005];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		for(int i=1;i<n;i+=2){
			if(a[i]==1&&a[i+1]==1) cnt++;
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
