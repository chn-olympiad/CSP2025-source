#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool f=1,f1=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
		if(a[i]>1)f1=0;
	}
	if(f==1)cout<<n/2;
	else if(f1==1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(i!=n&&a[i+1]==1){
						i++;
						ans++;
					}
				}
				else ans++;
			}
			cout<<ans;
		}
		else if(k==1){
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
			cout<<ans;
		}
	}
	return 0;
}
