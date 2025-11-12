#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[(int)5e5+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	int ans=0;
	if(cnt==n){
		if(k==1){
			cout<<n;
		}else{
			cout<<n/2;
		}
	}else{
		int bk,ft=2;
		if(k==1){
			for(int i=2;i<=n;i++){
				if(a[i]==1){
					ans++;
					bk=i;
				}else{
					for(int j=i-1,int k=ft+1;j>bk&&k<=n;j--,k++){
						if(a[j]==1){
							if(a[k]==1){
								if(j<=k){
									ans++;
									bk=j;
								}else{
									ft=k;
									i=k;
									bk=j;
									ans++;
								}
							}else{
								ans++;
								bk=j;
							}
						}else{
							if(a[k]==1){
								ft=k;
								i=k;
								bk=j;
								ans++;	
							}
						}
					}
				}
			}
			cout<<ans;
			return 0;
		}else{
			for(int i=2;i<=n;i++){
				if(a[i]==0){
					ans++;
					bk=i;
				}else{
					for(int j=i-1,int k=ft+1;j>bk&&k<=n;j--,k++){
						if(a[j]==0){
							if(a[k]==0){
								if(j<=k){
									ans++;
									bk=j;
								}else{
									ft=k;
									i=k;
									bk=j;
									ans++;
								}
							}else{
								ans++;
								bk=j;
							}
						}else{
							if(a[k]==0){
								ft=k;
								i=k;
								bk=j;
								ans++;	
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
