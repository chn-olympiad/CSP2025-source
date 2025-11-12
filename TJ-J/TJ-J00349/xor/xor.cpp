#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[50010],x,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			x=a[i];
			for(int l=i+1;k<j;k++){
				x=x^a[l];
			}
			if(x==k)ans++;
		}
	}
	cout<<ans;
	return 0;
}
