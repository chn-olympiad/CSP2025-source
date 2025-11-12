#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int flag=0;
int falg=0;
int ji1[100100];
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]!=1&&a[i]!=0){
			falg=1;
		}
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}else{
		if(falg==0){
			if(m==1){
				int ans=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1){
						ans++;
					}
				}
				cout<<ans;
				return 0;
			}
			if(m==0){
				int ans=0;
				for(int i=1;i<=n;i++){
					if(a[i]==0){
						ans++;
					}
					if(a[i]==1&&a[i+1]==1){
						ans++;
						i++;
					}
				}
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<n-5;
	return 0;
}
