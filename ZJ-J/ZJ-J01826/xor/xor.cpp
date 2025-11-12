#include<bits/stdc++.h>
using namespace std;
int n,k,ans,l;
int a[500002],pre[500001];
bool flag=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
		pre[i]=(pre[i-1]^a[i]);
	}
	if(n>1000){
		if(flag){
			for(int i=1;i<=n;i++){
				if(k==0){
					if(a[i]==0) ans++;
					if(a[i]==1 and a[i+1]==1){
						i++;
						ans++;
					}
				}
				if(k==1){
					if(a[i]==1) ans++;
				}
			}
			cout<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=l;j<i;j++){
			if((pre[i]^pre[j])==k){
				l=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
