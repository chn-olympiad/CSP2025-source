#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,f,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
		if(a[i]!=1) f=1;
	}
	if(f){
		if(m<=1){
			for(int i=1;i<=n;i++){
				if(a[i]==k) ans++;
				if(a[i]==!k && a[i]+1==!k){
					ans++;
					i++;
				}
			}
		} 
		else{
			for(int i=1;i<=n;i++){
				if(a[i]!=k){
					int p=a[i];
					for(int j=i+1;j<=n;j++){
						p^=a[j];
						if(p==k){
							ans++;
							i=j;
							break;
						}
					}
				}
				else ans++;
			}
		}
		cout<<ans<<endl;
	}else{
		cout<<n/2<<endl;
		return 0;
	}
	return 0;
}
