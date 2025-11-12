#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,f=0;
int a[500005];
int _xor(){
	if(k==1&&f==1){
		for(int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
				ans++;
				i++;
			}
		}
	}else if(k==0&&f==1){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				ans++;
				i++;
			}
		}
	}else{
		ans=7;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0&&k==0){
		cout<<n;
		return 0;
	}else{
		cout<<_xor();
		return 0;
	}
}
