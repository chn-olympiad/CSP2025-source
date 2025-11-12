#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int maxn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<200000){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int l=1;l<=n;l++){
			int ans=0;
			for(int i=l;i<=n;i++){
				int tmp=0;
				for(int j=i;j<=n;j++){
					tmp^=a[j];
					if(tmp==k){
						i=j;
						ans++;
						break;
					} 
				}
			}
			maxn=max(ans,maxn);
		}
		cout<<maxn;
	}else{
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else{
					if(a[i-1]==1)ans++;
				}
			}
			cout<<ans;
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]==1)ans++;
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
