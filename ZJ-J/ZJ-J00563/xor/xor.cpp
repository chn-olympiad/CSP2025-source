#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,a[500010],flag,ans,b[500010]; 
int flag2;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
		if(a[i]!=1&&a[i]!=0) flag2=1;
//		if(a[i]>k) a[i]^=k;
	}if(flag==0){
		if(k==0) cout<<n/2;
		else if(k==1) cout<<n;
		return 0;
	}if(flag2=1){
		if(k==0){
			int t=0;
			int l=0,r=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) l=1;
				if(a[i]==1&&l==1){
					
				}
			} cout<<ans;
		} else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}cout<<ans;
		}return 0;
	}for(int i=1;i<=n;i++){
		b[i]=b[i-1];
		b[i]^=a[i];
	}for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i]^b[j]==k) ans++;
		}
	}cout<<ans;
	
	return 0;
}//#Shang4Shan3Ruo6Shui4


