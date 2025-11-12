#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0){
			flag=0;
		}
	}
	int ans=0;
	if(k==0&&flag){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
	}
	else if(k==1&&flag){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
