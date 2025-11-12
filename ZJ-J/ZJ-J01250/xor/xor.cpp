#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[500005];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
	}
	if(k==1){
		cout<<ans;
	}else{
		ans=0;
		for(int i=1;i<=n;){
			if(a[i]==0){
				ans++;
				i++;
			}else if(a[i]==1 && a[i+1]==1){
				ans++;
				i+=2;
			}else{
				i++;
			}
		
		}
		cout<<ans;
	}

	return 0;
}

