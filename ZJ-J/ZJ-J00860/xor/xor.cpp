#include<bits/stdc++.h>
using namespace std;
int n,k,mx,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int xr=a[i],cnt=0;
		for(int j=i+1;j<n;j++){
			if(xr==k){
				cnt++;
				xr=a[j];
			}else xr=xr|a[j];
		}
		if(xr==k)cnt++;
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}