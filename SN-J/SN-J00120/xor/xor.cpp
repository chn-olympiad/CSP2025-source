#include <bits/stdc++.h> 
using namespace std;
int n,k,b,ans;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)	b=1;
	}
	if(k==0&&b==0){
		cout<<n/2;	
		return 0;
	}
	else if(k==0&&b==1){
		for(int i=1;i<=n-1;i++){
			if(a[i]==1&&a[i+1]==1) ans++,i++;
			if(a[i]==0) ans++;
		}
		cout<<ans;
		return 0;
	}
	else if(k==1&&b==1){
		for(int i=1;i<=n-1;i++){
			if(a[i]==1) ans++;
			else if(a[i]!=a[i+1]) ans++,i++;
		}
		cout<<ans;
		return 0;
	}
	else{
		if(a[1]==k) ans++,a[1]=0;
		for(int i=2;i<=n;i++){
			a[i]=a[i-1]^a[i];
			if(a[i]==k) ans++,a[i]=0;
		}
		cout<<ans;
	}
	return 0;
}
