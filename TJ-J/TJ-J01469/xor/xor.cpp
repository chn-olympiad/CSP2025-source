#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,p,f1,f2,g,ans,q,flag;
ll a[500010],f[5010][5010],vis[5010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&a[i]!=1){
			f1=1;
		}
		if(a[i]!=1){
			f2=1;
		}
	}
	if(f2){
		if(f1){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=-1;
				}
			}
			for(int i=1;i<=n;i++){
				f[i][i]=a[i];
			}
			
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(f[i][j]==-1){
						f[i][j]=f[i][j-1]^a[j];
					}	
				}
			}
			for(int k=0;k<n;k++){
				for(int i=1;i+k<=n;i++){
					flag=0;
					for(int j=i;j<=i+k;j++){
						if(vis[j]==1){
							flag=1;
							break;
						}
					}
					if(!flag&&f[i][i+k]==q){
						for(int j=i;j<=i+k;j++){
							vis[j]=1;
						}
						ans++;
					}
				}
			}
			cout<<ans;
		}else{
			if(q==0){
				for(int i=1;i<=n;i++){
					if(g==0&&a[i]==0){
						ans++;
					}
					if(a[i]==1){
						if(g==1){
							if(i-p-1>=1){
								ans+=i-p-1;
								p=i;
							}else{
								g=0;
								ans++;
							}
						}else{
							g=1;
							p=i;
						}
					}
				}
				if(p!=n){
					ans+=n-p;
				}
			}else{
				for(int i=1;i<=n;i++){
					ans+=a[i];
				}
			}
			cout<<ans;
		}
	}else{
		cout<<n/2;
	}
	return 0;
}

