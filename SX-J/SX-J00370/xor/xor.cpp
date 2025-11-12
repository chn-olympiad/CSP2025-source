#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,t;
int a[200009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)t++;
	}
	if(t==n)cout<<n/2;
	else if(k==1)cout<<t;
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1){
				ans++;
				a[i+1]=2;
			}
		}
		cout<<ans;
	}

	return 0;
}