#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
	int n,k;
	int mx=-1;
	int ans[10005];
	int mp[1105]; 
	int a[1000005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=k;i++){
		if(a[i]>mx){
			mx=a[i];
			if(mx==100){
				ans[i]=mp[++i];
			}
		}
	} 
	for(int i=1;i<=k;i++){
		cout<<ans[i]; 
	}
	return 0;
} 
