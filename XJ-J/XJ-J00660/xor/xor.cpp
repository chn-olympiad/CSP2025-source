#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,m;	
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[i] = (b[i-1]^a[i]);
	}
	int ans = 0,mi = 500005;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if((b[j]^b[i-1])==m){
				mi = min(mi,j);
				break;
			}
		}
		if(i>=mi){
			mi = 500005;
			ans++;
		}
	}
	cout<<ans;
}
