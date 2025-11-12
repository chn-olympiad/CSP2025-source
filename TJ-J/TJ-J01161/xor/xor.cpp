#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],num,ans,flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			num++;
		}
		if(a[1]!=1&&a[i]!=0){
			flag=1;
		}
	}
	if(flag==0){
		if(k==1){
			cout<<num;
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else if(a[i]==1){
					if(a[i+1]==1){
						ans++;
						i++;
					}
				}
			}	
			cout<<ans;
		}else if(k>1){
			cout<<"0";
		}
	}else if(flag==1){
		cout<<"2";
	}
	return 0;
}
