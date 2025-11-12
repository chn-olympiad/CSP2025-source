#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
   	int n,k,a[500005],dp[105][105],ans=0;
    bool flag=1,flag2=1,flag3;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1){
    		flag=0;
		}
		if(a[i]>1){
			flag2=0;
		}
	}
	if(k){
		flag=0;
	}
	if(k>1){
		flag2=0;
	}
	if(flag){
		cout<<n/2<<endl;
		return 0;
	}
	if(flag2){
		if(k==0){
			flag3=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&flag3==1){
					flag3=0;
					ans++;
					continue;
				}else if(a[i]==1&&flag3==0){
					flag3=1;
					continue;
				}else if(a[i]==0&&flag3==0){
					ans++;
					continue;
				}else{
					continue;
				}
			}
			cout<<ans<<endl;
			return 0;
		}else{
			flag3=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&flag3==1){
					flag3=1;
					continue;
				}else if(a[i]==1&&flag3==0){
					ans++;
					flag3=0;
					continue;
				}else if(a[i]==0&&flag3==1){
					flag3=1;
					ans++;
					continue;
				}else{
					continue;
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	/*if(n<500){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j){
					dp[i][j]=a[i];
				}else{
					dp[i][j]=dp[i][j-1] xor a[j];
				}
				if(dp[i][j]==k){
					ans++;
					i=j-1;
					break;
				} 
			}
		}
	}
	cout<<ans<<endl;*/
    return 0;
}

