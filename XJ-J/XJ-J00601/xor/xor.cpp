#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
bool f=1;
int k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)f=0;
	}
	if(k==0&&f==1)cout<<n/2;
	if(k==0&&f==0){
		for(int i=1;i<=n;i++){
		if(a[i]==0)ans++;
		if(i<=n-1&&a[i]==1&&a[i+1]==1){
			ans++;
			i++;
		}
	}
	}
	if(k==1&&f==0){
		for(int i=1;i<=n;i++){
		if(a[i]==1)ans++;
	}
	}
	cout<<ans;
	return 0;
}

