#include <bits/stdc++.h>
using namespace std;
int n,k,ans,flag,flag2;
int a[500010],yihuo[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1; 
		if(a[i]!=0 && a[i]!=1) flag2=1;
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
	}
	if(!flag){
		cout<<n/2;
		return 0;
	}
	if(!flag2){
		int ind=1,len=0;
		while(ind<=n){
			if(a[ind]!=-1){
				len++;
				a[ind]=-1;
			}
			else{
				ans+=len/2;
				len=0;
			}
			ind++;
		}
		cout<<ans+len/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int xorr=a[i];
		for(int j=i+1;j<=n;j++){
			if(a[j]==-1) break;
			xorr=xorr^a[j];
			if(xorr==k){
				ans++;
				for(int l=i;l<=j;l++) a[l]=-1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}