#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=(a[i]^a[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]-a[i]==k || a[i]-a[j]==k){
				ans++;
				i=j;
			}
		}
	}
	cout<<ans+1;
	return 0;
} 
