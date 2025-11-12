#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++)if(a[i])ans++;
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++)if(!a[i])ans++;
		for(int i=1;i<n;i++)if(a[i]==1&&a[i+1]==1)ans++;
		cout<<ans;
	}
	return 0;
} 
