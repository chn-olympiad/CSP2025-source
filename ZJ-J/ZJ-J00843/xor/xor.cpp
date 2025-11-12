#include<bits/stdc++.h>
using namespace std;
long long n,s,k,f,ans,a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(k==0&&f==0)cout<<n/2;
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==k)ans++;
			else{
				for(int j=i+1;j<=n;j++){
					s=0;
					for(int k=i;k<=j;k++)s^=a[k];
					if(s==k){
						ans++;
						i=j+1;
						break;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}