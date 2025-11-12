#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n;
int k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==0||a[i]==1&&a[i-1]==1){
				ans++;
				a[i]=0;
			}
		}
	}cout<<ans;
	return 0;
}
