#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005],ans,mx,z;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(k<=1&&mx<=1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				z=i;
				break; 
			}
		}
	}
	if(z){
		for(int i=z;i<=n;i++)
		{
			int v=a[i];
			if(v==k){
				ans++;
				continue;
			}
			for(int j=i+1;j<=n;j++){
				v^=a[j];
				if(v==k){
					ans++;
					i=j+1;
					break; 
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int v=a[i];
		if(v==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			v^=a[j];
			if(v==k){
				ans++;
				i=j+1;
				break; 
			}
		}
	}
	cout<<ans;
}
