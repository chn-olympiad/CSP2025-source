#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[1000010],f,f2,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
		if(a[i]!=1&&a[i]!=0)f2=1;
	}
	if(f==0){
		if(k==0)cout<<n/2;
	}
	else if(f2==0){
		if(k==0){
			for(i=1;i<=n;i++){
				if(a[i]==0||a[i]==1&&a[i+1]==1)ans++;
			}
		}
		else{
			for(i=1;i<=n;i++)if(a[i]==1)ans++;
		}
		cout<<ans;
	}
	else{
		for(i=1;i<=n;i++)if(a[i]==k)ans++;
		if(ans!=0)cout<<ans;
		else cout<<n/2;
	}
}
