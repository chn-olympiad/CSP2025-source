#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,a[100005],aa,bb,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
			if(k==1){
			for(int i=1;i<=n;i++){
			
			if(a[i]==1){
				ans++;
			}
			
			if(a[i]==0){
			bb++;
			if(bb==2){
				ans++;
				bb=0;
			}
			}
	}
}
		if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			
			if(a[i]==1){
			bb++;
			if(bb==2){
				ans++;
				bb=0;
			}
			}
	}
		}
		cout<<ans;
}



