#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
int ans;
int h;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		b[i]=l;
		a[i]=(a[i-1]^l);
		if(l>1) f=0;
	}
	if(f){
		if(k>1) cout<<0;
		else if(k==0){
			for(int i=1;i<=n;i++){
				if(b[i]==0){
					ans++;
				}else{
					if(b[i+1]==1){
						ans++;
						i++;
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(b[i]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=h;j<i;j++){
			if((a[i]^a[j])==k){
				ans++;
				h=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
