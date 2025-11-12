#include<bits/stdc++.h>
using namespace std;
int n,a[500001],k,sum[500001],f[500001],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=1;
		sum[i]=a[i]^sum[i-1];
	}
	if(flag==0&&n>1000){
		if(k==0){
			int cnt=0,ff=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(a[i+1]==1)cnt++;
				}
				else cnt++;
			}
			cout<<cnt;
			return 0;
		}
		if(k==1){
			int cnt=0,ff=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
			cout<<cnt;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=i;j>=1;j--){
			int x=sum[i]^sum[j-1];
			if(x==k){
				f[i]=max(f[j-1]+1,f[i]);
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
}
