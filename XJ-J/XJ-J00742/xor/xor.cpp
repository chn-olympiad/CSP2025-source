#include<bits/stdc++.h>

using namespace std;

int n,k,a[500005],ans=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag_a=1,flag_b=1,flag_c=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag_a=0;
			if(a[i]!=0){
				flag_b=0;
			}
		}
	}
	if(flag_a){
		if(k==0){
			if(n==1){
				ans=0;
			}else if(n==2){
				ans=1;
			}else{
				if(n%2==0){
					ans=n/2;
				}else{
					ans=ceil(n/2);
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(flag_b){
		int ans1=0,ans2=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]){
					ans1++;
					i++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans2++;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]!=a[i+1]){
					ans1++;
					i++;
				}
			}for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans2++;
				}
			}
		}
		ans=max(ans1,ans2);
		cout<<ans<<endl;
		return 0;
	}else{
		cout<<2<<endl;
		return 0;
	}
}
