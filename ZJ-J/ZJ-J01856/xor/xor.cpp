#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[600005];
int num_1;
int num_0;
int num_other;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			num_1+=1;			
		}
		else if(a[i]==0){
			num_0+=1;
		}
		else{
			num_other+=1;
		}
	}
	if(num_1==n){
		if(k==0)cout<<n/2;
		else if(k==1) cout<<n;
		return 0;
	}
	else if(num_0==n){
		if(k==0) cout<<n;
		else if(k==1) cout<<0;
		return 0;
	}
	else if(num_other==0){
		if(k==0){
			int ans=0;
			int flag=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans+=1;
				}
				else if(flag==0 && a[i]==1){
					flag=1;
				}
				else if(flag==1 && a[i]==1){
					ans+=1;
					flag=0;
				}
				if(flag==1 && a[i]==0){
					flag=0;
				}	
			}
			cout<<ans;
			return 0;
		}
		else if(k==1){
			cout<<num_1;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
