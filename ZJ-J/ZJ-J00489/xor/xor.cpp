#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			else if(a[i]==a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
	}
	
	return 0;
}